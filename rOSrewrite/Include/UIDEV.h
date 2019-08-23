#ifndef UIDEV_H
#define UIDEV_H

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;


#define VGA_ADDRESS 0xB8000
#define BUFSIZE 2200

uint16* vga_buffer;

#define NULL 0

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

#endif
//index for video buffer array
uint32 vga_index;
//counter to store new lines
static uint32 next_line_index = 1;
//fore & back color values
uint8 g_fore_color = WHITE, g_back_color = BLUE;
//digit ascii code for printing integers
int digit_ascii_codes[10] = { 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39 };

/*
16 bit video buffer elements(register ax)
8 bits(ah) higher :
  lower 4 bits - forec olor
  higher 4 bits - back color

8 bits(al) lower :
  8 bits : ASCII character to print
*/
uint16 vga_entry(unsigned char ch, uint8 fore_color, uint8 back_color)
{
	uint16 ax = 0;
	uint8 ah = 0, al = 0;

	ah = back_color;
	ah <<= 4;
	ah |= fore_color;
	ax = ah;
	ax <<= 8;
	al = ch;
	ax |= al;
	return ax;
}

//clear video buffer array
void clear_vga_buffer(uint16 **buffer, uint8 fore_color, uint8 back_color)
{;
	uint32 i;
	for (i = 0; i < BUFSIZE; i++) {
		(*buffer)[i] = vga_entry(NULL, fore_color, back_color);
	}
	next_line_index = 1;
	vga_index = 0;
}

//initialize vga buffer
void init_vga(uint8 fore_color, uint8 back_color)
{
	vga_buffer = (uint16*)VGA_ADDRESS;
	clear_vga_buffer(&vga_buffer, fore_color, back_color);
	g_fore_color = fore_color;
	g_back_color = back_color;
}

/*
increase vga_index by width of row(80)
*/
void pline()
{
	if (next_line_index >= 55) {
		next_line_index = 0;
		clear_vga_buffer(&vga_buffer, g_fore_color, g_back_color);
	}
	vga_index = 80 * next_line_index;
	next_line_index++;
}

int hpts = 1;

//assign ascii character to video buffer
void pchar(char ch)
{
	hpts = 0;
	vga_buffer[vga_index] = vga_entry(ch, g_fore_color, g_back_color);
	vga_index++;
	hpts = 1;
}

//print string by calling print_char
void pstring(char *str,int nl)
{
	uint32 index = 0;
	while (str[index]) {
		pchar(str[index]);
		index++;
	}
	if (nl == 1) {
		pline();
	}
}

uint32 digit_count(int num)
{
	uint32 count = 0;
	if (num == 0) {
		return 1;
	}
	while (num > 0) {
		count++;
		num = num / 10;
	}
	return count;
}

//print int by converting it into string
//& then printing string
void pint(int num,int nl)
{
	char str_num[digit_count(num) + 1];
	itoa(num, str_num);
	pstring(str_num,nl);
}
