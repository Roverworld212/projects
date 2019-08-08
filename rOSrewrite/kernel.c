#include "UIDEV.h"
#include "IO.h"
#include "KERNUTILS.h"
#include "terminal.c"

void test_input()
{
	char ch = 0;
	char keycode = 0;
	do {
		keycode = get_input_keycode();
		if (hpts == 1) {
			if (keycode == KEY_ENTER) {
				print_new_line();
			}
			else {
				ch = get_ascii_char(keycode);
				pchar(ch);
				sleept(30);
			}
		}
	} while (ch > 0);
}

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
