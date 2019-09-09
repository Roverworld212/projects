#include "TYPES.h"
#include "MTASKING.h"

void initialize_process_tree(void) {
	process_tree = tree_create();
	process_list = list_create();
	process_queue = list_create();
	sleep_queue = list_create();

	/* Start off with enough bits for 64 processes */
	bitset_init(&pid_set, MAX_PID / 8);
	/* First two bits are set by default */
	bitset_set(&pid_set, 0);
	bitset_set(&pid_set, 1);
}

tree_t * tree_create(void) {
	/* Create a new tree */
	tree_t * out = malloc(sizeof(tree_t));
	out->nodes  = 0;
	out->root   = NULL;
	return out;
}

list_t * list_create(void) {
	/* Create a fresh list */
	list_t * out = malloc(sizeof(list_t));
	out->head = NULL;
	out->tail = NULL;
	out->length = 0;
	return out;
}

/* malloc() {{{ */
static void * __attribute__ ((malloc)) klmalloc(uintptr_t size) {
	/*
	 * C standard implementation:
	 * If size is zero, we can choose do a number of things.
	 * This implementation will return a NULL pointer.
	 */
	if (__builtin_expect(size == 0, 0))
		return NULL;

	/*
	 * Find the appropriate bin for the requested
	 * allocation and start looking through that list.
	 */
	unsigned int bucket_id = klmalloc_bin_size(size);

	if (bucket_id < BIG_BIN) {
		/*
		 * Small bins.
		 */
		klmalloc_bin_header * bin_header = klmalloc_list_head(&klmalloc_bin_head[bucket_id]);
		if (!bin_header) {
			/*
			 * Grow the heap for the new bin.
			 */
			bin_header = (klmalloc_bin_header*)sbrk(PAGE_SIZE);
			bin_header->bin_magic = BIN_MAGIC;
			assert((uintptr_t)bin_header % PAGE_SIZE == 0);

			/*
			 * Set the head of the stack.
			 */
			bin_header->head = (void*)((uintptr_t)bin_header + sizeof(klmalloc_bin_header));
			/*
			 * Insert the new bin at the front of
			 * the list of bins for this size.
			 */
			klmalloc_list_insert(&klmalloc_bin_head[bucket_id], bin_header);
			/*
			 * Initialize the stack inside the bin.
			 * The stack is initially full, with each
			 * entry pointing to the next until the end
			 * which points to NULL.
			 */
			uintptr_t adj = SMALLEST_BIN_LOG + bucket_id;
			uintptr_t i, available = ((PAGE_SIZE - sizeof(klmalloc_bin_header)) >> adj) - 1;

			uintptr_t **base = bin_header->head;
			for (i = 0; i < available; ++i) {
				/*
				 * Our available memory is made into a stack, with each
				 * piece of memory turned into a pointer to the next
				 * available piece. When we want to get a new piece
				 * of memory from this block, we just pop off a free
				 * spot and give its address.
				 */
				base[i << bucket_id] = (uintptr_t *)&base[(i + 1) << bucket_id];
			}
			base[available << bucket_id] = NULL;
			bin_header->size = bucket_id;
		}
		uintptr_t ** item = klmalloc_stack_pop(bin_header);
		if (klmalloc_stack_empty(bin_header)) {
			klmalloc_list_decouple(&(klmalloc_bin_head[bucket_id]),bin_header);
		}
		return item;
	} else {
		/*
		 * Big bins.
		 */
		klmalloc_big_bin_header * bin_header = klmalloc_skip_list_findbest(size);
		if (bin_header) {
			assert(bin_header->size >= size);
			/*
			 * If we found one, delete it from the skip list
			 */
			klmalloc_skip_list_delete(bin_header);
			/*
			 * Retreive the head of the block.
			 */
			uintptr_t ** item = klmalloc_stack_pop((klmalloc_bin_header *)bin_header);
#if 0
			/*
			 * Resize block, if necessary
			 */
			assert(bin_header->head == NULL);
			uintptr_t old_size = bin_header->size;
			//uintptr_t rsize = size;
			/*
			 * Round the requeste size to our full required size.
			 */
			size = ((size + sizeof(klmalloc_big_bin_header)) / PAGE_SIZE + 1) * PAGE_SIZE - sizeof(klmalloc_big_bin_header);
			assert((size + sizeof(klmalloc_big_bin_header)) % PAGE_SIZE == 0);
			if (bin_header->size > size * 2) {
				assert(old_size != size);
				/*
				 * If we have extra space, start splitting.
				 */
				bin_header->size = size;
				assert(sbrk(0) >= bin_header->size + (uintptr_t)bin_header);
				/*
				 * Make a new block at the end of the needed space.
				 */
				klmalloc_big_bin_header * header_new = (klmalloc_big_bin_header *)((uintptr_t)bin_header + sizeof(klmalloc_big_bin_header) + size);
				assert((uintptr_t)header_new % PAGE_SIZE == 0);
				memset(header_new, 0, sizeof(klmalloc_big_bin_header) + sizeof(void *));
				header_new->prev = bin_header;
				if (bin_header->next) {
					bin_header->next->prev = header_new;
				}
				header_new->next = bin_header->next;
				bin_header->next = header_new;
				if (klmalloc_newest_big == bin_header) {
					klmalloc_newest_big = header_new;
				}
				header_new->size = old_size - (size + sizeof(klmalloc_big_bin_header));
				assert(((uintptr_t)header_new->size + sizeof(klmalloc_big_bin_header)) % PAGE_SIZE == 0);
				fprintf(stderr, "Splitting %p [now %zx] at %p [%zx] from [%zx,%zx].\n", (void*)bin_header, bin_header->size, (void*)header_new, header_new->size, old_size, size);
				/*
				 * Free the new block.
				 */
				klfree((void *)((uintptr_t)header_new + sizeof(klmalloc_big_bin_header)));
			}
#endif
			return item;
		} else {
			/*
			 * Round requested size to a set of pages, plus the header size.
			 */
			uintptr_t pages = (size + sizeof(klmalloc_big_bin_header)) / PAGE_SIZE + 1;
			bin_header = (klmalloc_big_bin_header*)sbrk(PAGE_SIZE * pages);
			bin_header->bin_magic = BIN_MAGIC;
			assert((uintptr_t)bin_header % PAGE_SIZE == 0);
			/*
			 * Give the header the remaining space.
			 */
			bin_header->size = pages * PAGE_SIZE - sizeof(klmalloc_big_bin_header);
			assert((bin_header->size + sizeof(klmalloc_big_bin_header)) % PAGE_SIZE == 0);
			/*
			 * Link the block in physical memory.
			 */
			bin_header->prev = klmalloc_newest_big;
			if (bin_header->prev) {
				bin_header->prev->next = bin_header;
			}
			klmalloc_newest_big = bin_header;
			bin_header->next = NULL;
			/*
			 * Return the head of the block.
			 */
			bin_header->head = NULL;
			return (void*)((uintptr_t)bin_header + sizeof(klmalloc_big_bin_header));
		}
	}
}
