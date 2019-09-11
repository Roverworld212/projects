# set flags to 0
.set FLAGS,    0

# set magic number to 0x1BADB002 to identified by bootloader
.set MAGIC,    0x1BADB002

# set the checksum
.set CHECKSUM, -(MAGIC + FLAGS)

# set multiboot enabled
.section .multiboot

# define type to long for each data defined as above
.long MAGIC
.long FLAGS
.long CHECKSUM


# set the stack bottom
stackBottom:

# define the maximum size of stack to 512 bytes
.skip 4096


# set the stack top which grows from higher to lower
stackTop:

.section .text
.global _start
.type _start, @function

.global gdt_flush
.type gdt_flush, @function

.global tss_flush
.type tss_flush, @function



_start:

  # assign current stack pointer location to stackTop
	mov $stackTop, %esp

  # call the kernel main function
	call kernel_main

	cli

  gdt_flush:
      /* Load GDT */
      mov 4(%esp), %eax
      lgdt (%eax)

      mov $0x10, %ax
      mov %ax, %ds
      mov %ax, %es
      mov %ax, %fs
      mov %ax, %ss
      mov %ax, %gs

      ljmp $0x08, $.flush
  .flush:
      ret

      tss_flush:
          mov $0x2B, %ax
          ltr %ax
          ret



# put system in infinite loop
hltLoop:

	hlt
	jmp hltLoop

.size _start, . - _start