/*
The utilites for the kernel and other OS programs
*/

void kern_panic(char *str,int *pntr) {
	pstring("KERNEL PANIC", 1);
	pstring("NFIPT: ", 0);
	pint(pntr, 1);
	pstring("REASON: ", 1);
	pstring(str, 1);
}
