/*
The utilites for the kernel and other OS programs
*/

#define KERN_SUCCESS 1
#define KERN_FAILURE 0

void kern_panic(char *str, int *rn,char *lcaller) {
	pline();
	pstring("KERNEL PANIC", 1);
	pstring("RN: ", 0);
	pint(rn, 1);
	pstring("CALLER: ", 0);
	pstring(lcaller, 0);
	pstring(", 0x", 0);
	pint(&lcaller, 1);
	pstring("REASON: ", 0);
	pstring(str, 1);
	pline();
	pstring("HANGING", 1);
	while (1 == 1) {
	}
}
void haltkern() {
	pstring("Halting Kernel", 1);
	pstring("This will require a reboot!", 1);
	while (1 == 1) {
		//Usless command but im using it for testing cmd input
	}
}

//Dumps all vars that the kernel is using
//Useful for debugging
void dkvar() {
	//Add code here
}