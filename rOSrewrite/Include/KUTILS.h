#define KERN_SUCCESS 1
#define KERN_FAILURE 0
#define USER_STACK_BOTTOM 0xAFF00000
#define USER_STACK_TOP    0xB0000000
#define SHM_START         0xB0000000
#include "TYPES.h"

/* /kernel/kutils.c */
extern void *memset(void *dest, char val, size_t count);
extern unsigned short * memsetw(unsigned short * dest, unsigned short val, int count);

/* /kernel/setup.c */
extern void setup();
