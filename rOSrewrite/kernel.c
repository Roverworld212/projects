#include "UIDEV.h"
#include "IO.h"
#include "KERNUTILS.h"
#include "terminal.c"

void termstart() {
	while (1 == 1) {
		int i = terminal();
		if (i == 1) {
			return;
		}
	}
}

void kernel_main() {
	init_vga(WHITE, BLACK);
	pstring("VGA Initialized", 1);
	tkbd();
	int *NFIPT = &termstart;
	pstring("Loading Terminal", 1);
	termstart();
	kern_panic("TERMINAL RETURNED", NFIPT);
}