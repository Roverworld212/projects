#include "IO.h"
#include "TYPES.h"
int kpressed = 0;
int cmdnum = 0;

char gac(uint8 key_code)
{
	switch (key_code) {
		case KEY_A://Add 5
    ccn(5);
    kpressed++;
		sleepk();
  	return 'A';
  	case KEY_B://Add 10
    ccn(10);
    kpressed++;
		sleepk();
    return 'B';
  	case KEY_C://Add 15
    ccn(15);
    kpressed++;
		sleepk();
    return 'C';
  	case KEY_D://Add 20
    ccn(20);
		sleepk();
		return 'D';
  	case KEY_E://Add 25
    ccn(25);
		sleepk();
		return 'E';
  	case KEY_F://Add 30
    ccn(30);
		sleepk();
		return 'F';
  	case KEY_G://Add 35
    ccn(35);
		sleepk();
		return 'G';
  	case KEY_H://Add 40
    ccn(40);
		sleepk();
		return 'H';
  	case KEY_I://Add 45
    ccn(45);
		sleepk();
		return 'I';
  	case KEY_J://Add 50
    ccn(50);
		sleepk();
		return 'J';
  	case KEY_K://Add 55
    ccn(55);
		sleepk();
		return 'K';
  	case KEY_L://Add 60
    ccn(60);
		sleepk();
		return 'L';
  	case KEY_M://Add 65
    ccn(65);
		sleepk();
		return 'M';
  	case KEY_N://Add 70
    ccn(70);
		sleepk();
		return 'N';
  	case KEY_O://Add 75
    ccn(75);
		sleepk();
		return 'O';
  	case KEY_P://Add 80
    ccn(80);
		sleepk();
		return 'P';
  	case KEY_Q://Add 85
    ccn(85);
		sleepk();
		return 'Q';
  	case KEY_R://Add 90
    ccn(90);
		sleepk();
		return 'R';
  	case KEY_S://Add 95
    ccn(95);
		sleepk();
		return 'S';
  	case KEY_T://Add 100
    ccn(100);
		sleepk();
		return 'T';
  	case KEY_U://Add 105
    ccn(105);
		sleepk();
		return 'U';
  	case KEY_V://Add 110
    ccn(110);
		sleepk();
		return 'V';
  	case KEY_W://Add 115
    ccn(115);
		sleepk();
		return 'W';
  	case KEY_X://Add 120
    ccn(120);
		sleepk();
		return 'X';
  	case KEY_Y://Add 125
    ccn(125);
		sleepk();
		return 'Y';
  	case KEY_Z://Add 130
    ccn(130);
		sleepk();
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

void ccn(int nta){//Count cmdnum
	cmdnum = cmdnum + nta;
	/*Debug Commands
	//pstring("(", 0);
	//pint(nta, 0);
	//pstring(")", 0);
	*/
	sleep(0x02FFFFFF);
}

int retcnum(){
	return cmdnum;
}

void sleepk(){
	sleep(0x02FFFFFF);
	sleep(0x02FFFFFF);
	sleep(0x02FFFFFF);
	sleep(0x02FFFFFF);
}

void rsetcn(){
	cmdnum= 0;
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
