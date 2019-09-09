#include "PANIC.h"
extern void setup();

void kernel_main() {
	setup();//Lets setup the kernel
	while(1 == 1){
		kpanic();
	}
}
