#pragma once

#define VGA_ADDRESS 0xB8000
#define BUFSIZE 2200

#include "TYPES.h"

/* /kernel/ui.c */
extern void init_vga(uint8 fore_color, uint8 back_color);
extern void pstring(char *str,int nl);
extern void pline();
extern void cls();
extern void pint(int num,int nl);
extern void backspace();

extern int charp[99];//Up to 100 backspaces
extern int charpindx;

enum vga_color {
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	BROWN,
	GREY,
	DARK_GREY,
	BRIGHT_BLUE,
	BRIGHT_GREEN,
	BRIGHT_CYAN,
	BRIGHT_RED,
	BRIGHT_MAGENTA,
	YELLOW,
	WHITE,
};

#define NULL 0
