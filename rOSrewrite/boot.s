#The main boot file for the rOS kernel
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


_start:
	mov $stackTop, %esp
	call kernel_main #Main kernel
	call tdaemon #Test daemon

	cli
	
#_launchd:

# put system in infinite loop
hltLoop:

	hlt
	jmp hltLoop

.size _start, . - _start
