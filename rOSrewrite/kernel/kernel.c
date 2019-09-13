#include "PANIC.h"
#include "KUTILS.h"
#include "KERNEL.h"

void kernel_main() {
	if(bargs.SBARGS != 1){
	setbargs();//Set the boot args before anything else
	}
	setup();//Lets setup the kernel
	if(bargs.VGAENABLE == 1){
	tmain();
	}
	else{
		while(1 == 1){
			//Let the daemons run (When I have them)
		}
	}
	kpanic();//Panic when terminal returns (That should not happen)
}

void setbargs(){
	bargs.GDTENABLE = 1;
	bargs.DBENABLE = 1;
	bargs.BOOTDENABLE = 1;
	bargs.MTENABLE = 1;
	bargs.VGAENABLE = 1;//Probably don't want to set this to zero, but I wont stop you
	bargs.SBARGS = 1;
}
