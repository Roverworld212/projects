#ifndef IO_H
#define IO_H

#define KEYBOARD_PORT 0x60


#define KEY_A 0x1E
#define KEY_B 0x30
#define KEY_C 0x2E
#define KEY_D 0x20
#define KEY_E 0x12
#define KEY_F 0x21
#define KEY_G 0x22
#define KEY_H 0x23
#define KEY_I 0x17
#define KEY_J 0x24
#define KEY_K 0x25
#define KEY_L 0x26
#define KEY_M 0x32
#define KEY_N 0x31
#define KEY_O 0x18
#define KEY_P 0x19
#define KEY_Q 0x10
#define KEY_R 0x13
#define KEY_S 0x1F
#define KEY_T 0x14
#define KEY_U 0x16
#define KEY_V 0x2F
#define KEY_W 0x11
#define KEY_X 0x2D
#define KEY_Y 0x15
#define KEY_Z 0x2C
#define KEY_1 0x02
#define KEY_2 0x03
#define KEY_3 0x04
#define KEY_4 0x05
#define KEY_5 0x06
#define KEY_6 0x07
#define KEY_7 0x08
#define KEY_8 0x09
#define KEY_9 0x0A
#define KEY_0 0x0B
#define KEY_MINUS 0x0C
#define KEY_EQUAL 0x0D
#define KEY_SQUARE_OPEN_BRACKET 0x1A
#define KEY_SQUARE_CLOSE_BRACKET 0x1B
#define KEY_SEMICOLON 0x27
#define KEY_BACKSLASH 0x2B
#define KEY_COMMA 0x33
#define KEY_DOT 0x34
#define KEY_FORESLHASH 0x35
#define KEY_F1 0x3B
#define KEY_F2 0x3C
#define KEY_F3 0x3D
#define KEY_F4 0x3E
#define KEY_F5 0x3F
#define KEY_F6 0x40
#define KEY_F7 0x41
#define KEY_F8 0x42
#define KEY_F9 0x43
#define KEY_F10 0x44
#define KEY_F11 0x85
#define KEY_F12 0x86
#define KEY_BACKSPACE 0x0E
#define KEY_DELETE 0x53
#define KEY_DOWN 0x50
#define KEY_END 0x4F
#define KEY_ENTER 0x1C
#define KEY_ESC 0x01
#define KEY_HOME 0x47
#define KEY_INSERT 0x52
#define KEY_KEYPAD_5 0x4C
#define KEY_KEYPAD_MUL 0x37
#define KEY_KEYPAD_Minus 0x4A
#define KEY_KEYPAD_PLUS 0x4E
#define KEY_KEYPAD_DIV 0x35
#define KEY_LEFT 0x4B
#define KEY_PAGE_DOWN 0x51
#define KEY_PAGE_UP 0x49
#define KEY_PRINT_SCREEN 0x37
#define KEY_RIGHT 0x4D
#define KEY_SPACE 0x39
#define KEY_TAB 0x0F
#define KEY_UP 0x48


#endif

typedef enum {false, true} bool;
int kpressed = 0;
int cmdnum = 0;
int tnum = 0;
char gac(uint8 key_code)
{
	switch (key_code) {
		case KEY_A://Add 5
    tnum = cmdnum + 5;
    cmdnum = tnum;
    kpressed++;
		sleep(0x02FFFFFF);
  	return 'A';
  	case KEY_B://Add 10
    tnum = cmdnum + 10;
    cmdnum = tnum;
    kpressed++;
		sleep(0x02FFFFFF);
    return 'B';
  	case KEY_C://Add 15
    tnum = cmdnum + 15;
    cmdnum = tnum;
    kpressed++;
		sleep(0x02FFFFFF);
    return 'C';
  	case KEY_D://Add 20
    tnum = cmdnum + 20;
    cmdnum = tnum;
		kpressed++;
		sleep(0x02FFFFFF);
		return 'D';
  	case KEY_E://Add 25
    tnum = cmdnum + 25;
    cmdnum = tnum;
		kpressed++;
		sleep(0x02FFFFFF);
		return 'E';
  	case KEY_F://Add 30
    tnum = cmdnum + 30;
    cmdnum = tnum;
		kpressed++;
		sleep(0x02FFFFFF);
		return 'F';
  	case KEY_G://Add 35
    tnum = cmdnum + 35;
    cmdnum = tnum;
		kpressed++;
		sleep(0x02FFFFFF);
		return 'G';
  	case KEY_H://Add 40
    tnum = cmdnum + 40;
    cmdnum = tnum;
		kpressed++;
		sleep(0x02FFFFFF);
		return 'H';
  	case KEY_I://Add 45
    cmdnum = cmdnum + 45;
    cmdnum = tnum;
		kpressed++;
		sleep(0x02FFFFFF);
		return 'I';
  	case KEY_J://Add 50
    cmdnum = cmdnum + 50;
    cmdnum = tnum;
		kpressed++;
		sleep(0x02FFFFFF);
		return 'J';
  	case KEY_K://Add 55
    cmdnum = cmdnum + 55;
    cmdnum = tnum;
		kpressed++;
		sleep(0x02FFFFFF);
		return 'K';
  	case KEY_L://Add 60
    cmdnum = cmdnum + 60;
    cmdnum = tnum;
		kpressed++;
		sleep(0x02FFFFFF);
		return 'L';
  	case KEY_M://Add 65
    cmdnum = cmdnum + 65;
    cmdnum = tnum;
		kpressed++;
		sleep(0x02FFFFFF);
		return 'M';
  	case KEY_N://Add 70
    cmdnum = cmdnum + 70;
    cmdnum = tnum;
		kpressed++;
		sleep(0x02FFFFFF);
		return 'N';
  	case KEY_O://Add 75
    cmdnum = cmdnum + 75;
    cmdnum = tnum;
		kpressed++;
		sleep(0x02FFFFFF);
		return 'O';
  	case KEY_P://Add 80
    cmdnum = cmdnum + 80;
    cmdnum = tnum;
		kpressed++;
		sleep(0x02FFFFFF);
		return 'P';
  	case KEY_Q://Add 85
    cmdnum = cmdnum + 85;
    cmdnum = tnum;
		kpressed++;
		sleep(0x02FFFFFF);
		return 'Q';
  	case KEY_R://Add 90
    cmdnum = cmdnum + 90;
    cmdnum = tnum;
		kpressed++;
		sleep(0x02FFFFFF);
		return 'R';
  	case KEY_S://Add 95
    cmdnum = cmdnum + 95;
    cmdnum = tnum;
		kpressed++;
		sleep(0x02FFFFFF);
		return 'S';
  	case KEY_T://Add 100
    cmdnum = cmdnum + 100;
    cmdnum = tnum;
		kpressed++;
		sleep(0x02FFFFFF);
		return 'T';
  	case KEY_U://Add 105
    cmdnum = cmdnum + 105;
    cmdnum = tnum;
		kpressed++;
		sleep(0x02FFFFFF);
		return 'U';
  	case KEY_V://Add 110
    cmdnum = cmdnum + 110;
    cmdnum = tnum;
		kpressed++;
		sleep(0x02FFFFFF);
		return 'V';
  	case KEY_W://Add 115
    cmdnum = cmdnum + 115;
    cmdnum = tnum;
		kpressed++;
		sleep(0x02FFFFFF);
		return 'W';
  	case KEY_X://Add 120
    cmdnum = cmdnum + 120;
    cmdnum = tnum;
		kpressed++;
		sleep(0x02FFFFFF);
		return 'X';
  	case KEY_Y://Add 125
    cmdnum = cmdnum + 125;
    cmdnum = tnum;
		kpressed++;
		sleep(0x02FFFFFF);
		return 'Y';
  	case KEY_Z://Add 130
    cmdnum = cmdnum + 130;
    cmdnum = tnum;
		kpressed++;
		sleep(0x02FFFFFF);
		return 'Z';
	case KEY_1: return '1';
	case KEY_2: return '2';
	case KEY_3: return '3';
	case KEY_4: return '4';
	case KEY_5: return '5';
	case KEY_6: return '6';
	case KEY_7: return '7';
	case KEY_8: return '8';
	case KEY_9: return '9';
	case KEY_0: return '0';
	case KEY_MINUS: return '-';
	case KEY_EQUAL: return '=';
	case KEY_SQUARE_OPEN_BRACKET: return '[';
	case KEY_SQUARE_CLOSE_BRACKET: return ']';
	case KEY_SEMICOLON: return ';';
	case KEY_BACKSLASH: return '\\';
	case KEY_COMMA: return ',';
	case KEY_DOT: return '.';
	case KEY_FORESLHASH: return '/';
	case KEY_SPACE: return ' ';
	default: return 0;
	}
}

uint8 inb(uint16 port)
{
	uint8 ret;
	asm volatile("inb %1, %0" : "=a"(ret) : "d"(port));
	return ret;
}

void outb(uint16 port, uint8 data)
{
	asm volatile("outb %0, %1" : "=a"(data) : "d"(port));
}

char kin()
{
	char ch = 0;
	while ((ch = inb(KEYBOARD_PORT)) != 0) {
		if (ch > 0) {
			return ch;
		}
	}
	return ch;
}

/*
keep the cpu busy for doing nothing(nop)
so that io port will not be processed by cpu
here timer can also be used, but lets do this in looping counter
*/
void wait_for_io(uint32 timer_count)
{
	while (1) {
		asm volatile("nop");
		timer_count--;
		if (timer_count <= 0)
			break;
	}
}

void sleept() {//Yes you are seeing this correctly
	//idk how sleep() works but spamming it stops key duplication so...
	sleep(0x02FFFFFF);
	sleep(0x02FFFFFF);
	sleep(0x02FFFFFF);
	sleep(0x02FFFFFF);
	sleep(0x02FFFFFF);
	sleep(0x02FFFFFF);
	sleep(0x02FFFFFF);
	sleep(0x02FFFFFF);
	sleep(0x02FFFFFF);
	sleep(0x02FFFFFF);
}

void tkbd() {
	char ch = kin();
	if (ch > 0) {
		pstring("Keyboard OK", 1);
	}
	else {
		int *NPTR = 0x0;
		kern_panic("KEYBOARD FAILED", NPTR);
	}
}
