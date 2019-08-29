#include "UIDEV.h"
#include "IO.h"
#include "UTILS.h"
#include "KERNUTILS.h"
#include "terminal.c"
#include "MTUTILS.h"

int termstart() {
	pstring("Terminal loaded", 1);
	pstring(">", 0);
	while (1 == 1) {
		int i = terminal();
		if (i == 1) {
			return 1;
		}
		else {
			i = terminal();
		}
	}
}

void kernel_main() {
	apid[0] = 0;//Kernel has PID 0
	init_vga(WHITE, BLACK);
	pstring("VGA Initialized", 1);
	pstring("VGA BUFFER: ",0);
	pstring(&vgabuffer, 1);
	pstring("CURRENT INDEX: ", 0);
	pint(vga_index, 1);
	pstring("USING KEYBOARD PORT: ", 0);
	pstring(KEYBOARD_PORT, 1);
	tkbd();
	pstring("Loading Terminal", 1);
	int i = termstart();
	kern_panic("TERMINAL RETURNED", i, __FUNCTION__);
}
