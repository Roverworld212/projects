.set FLAGS,    0
.set MAGIC,    0x1BADB002
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot
.long MAGIC
.long FLAGS
.long CHECKSUM

stackBottom:

.skip 4096

stackTop:

.section .text
.global _start
.type _start, @function

.global gdt_flush
.type gdt_flush, @function

.global tss_flush
.type tss_flush, @function



_start:
	mov $stackTop, %esp
	call kernel_main
	jmp reload

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

reload:
mov $stackTop, %esp
call kernel_main
cli
jmp reload

# put system in infinite loop
hltLoop:
	hlt
	jmp hltLoop

.size _start, . - _start
