#include "UIDEV.h"
#include "IO.h"
#include "KERNUTILS.h"
#include "terminal.c"

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
	init_vga(WHITE, BLACK);
	pstring("VGA Initialized", 1);
	tkbd();
	pstring("Loading Terminal", 1);
	int i = termstart();
	kern_panic("TERMINAL RETURNED", i, __FUNCTION__);
}