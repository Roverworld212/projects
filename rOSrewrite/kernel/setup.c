#include "KUTILS.h"
#include "TYPES.h"
#include "GDT.h"
#include "UIDEV.h"

void setup(){//Setup all important funcs at boot
  init_vga(WHITE, BLUE);
  gdt_install();
}

void stp(){
  sleep(0x02FFFFFF);
	sleep(0x02FFFFFF);
	sleep(0x02FFFFFF);
	sleep(0x02FFFFFF);
}

void gdt_set_gate(uint8_t num, uint64_t base, uint64_t limit, uint8_t access, uint8_t gran) {
	/* Base Address */
	ENTRY(num).base_low = (base & 0xFFFF);
	ENTRY(num).base_middle = (base >> 16) & 0xFF;
	ENTRY(num).base_high = (base >> 24) & 0xFF;
	/* Limits */
	ENTRY(num).limit_low = (limit & 0xFFFF);
	ENTRY(num).granularity = (limit >> 16) & 0X0F;
	/* Granularity */
	ENTRY(num).granularity |= (gran & 0xF0);
	/* Access flags */
	ENTRY(num).access = access;
}

static void write_tss(int32_t num, uint16_t ss0, uint32_t esp0);

void gdt_install(void) {
  pstring("setting the gdt pointer", 1);
	gdt_pointer_t *gdtp = &gdt.pointer;
  pstring("setting base & limit", 1);
	gdtp->limit = sizeof gdt.entries - 1;
	gdtp->base = (uintptr_t)&ENTRY(0);
  pstring("Setting gates", 1);
	gdt_set_gate(0, 0, 0, 0, 0);                /* NULL segment */
	gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); /* Code segment */
	gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF); /* Data segment */
	gdt_set_gate(3, 0, 0xFFFFFFFF, 0xFA, 0xCF); /* User code */
	gdt_set_gate(4, 0, 0xFFFFFFFF, 0xF2, 0xCF); /* User data */
  pstring("Writing to tss", 1);
	write_tss(5, 0x10, 0x0);
  pstring("flushing gdt & tss", 1);
	/* Go go go */
	gdt_flush((uintptr_t)gdtp);
	tss_flush();
  pstring("setup done", 1);
}

static void write_tss(int32_t num, uint16_t ss0, uint32_t esp0) {
	tss_entry_t * tss = &gdt.tss;
	uintptr_t base = (uintptr_t)tss;
	uintptr_t limit = base + sizeof *tss;

	/* Add the TSS descriptor to the GDT */
	gdt_set_gate(num, base, limit, 0xE9, 0x00);

	memset(tss, 0x0, sizeof *tss);

	tss->ss0 = ss0;
	tss->esp0 = esp0;
	tss->cs = 0x0b;
	tss->ss = 0x13;
	tss->ds = 0x13;
	tss->es = 0x13;
	tss->fs = 0x13;
	tss->gs = 0x13;

	tss->iomap_base = sizeof *tss;
}

void set_kernel_stack(uintptr_t stack) {
	/* Set the kernel stack */
	gdt.tss.esp0 = stack;
}
