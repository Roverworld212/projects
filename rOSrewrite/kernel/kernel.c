#include "PANIC.h"
#include "KUTILS.h"

void kernel_main() {
	setup();//Lets setup the kernel
	tmain();
	kpanic();//Panic when terminal returns (That should not happen)
}
