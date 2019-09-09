#include "UTILS.h"
#include "TYPES.h"

char *strcat(char *dest, const char *src)
{
    int i,j;
    for (i = 0; dest[i] != '\0'; i++)
        ;
    for (j = 0; src[j] != '\0'; j++)
        dest[i+j] = src[j];
    dest[i+j] = '\0';
    return dest;
}

void sleep(uint32 timer_count)
{
	wait_for_io(timer_count);
}

int ruses = 0;

int rand(int i,int b){//Simple implementation of Rand() function
  ruses++;
  int o;
  o = i * 10 *b;
  o = o * i + ruses;
  o = ruses * o;
  o = o/2;
  o = i * 10 *b;
  o = o * i + ruses;
  o = ruses * o;
  o = o/2;
  return o;
}

int strcmp(const char* s1, const char* s2)
{
    while(*s1 && (*s1==*s2))
        s1++,s2++;
    return *(const unsigned char*)s1-*(const unsigned char*)s2;
}

uint32 strlen(const char* str)
{
	uint32 length = 0;
	while (str[length]) {
		length++;
	}
	return length;
}

void itoa(int num, char *number)
{
	int dgcount = digit_count(num);
	int index = dgcount - 1;
	char x;
	if (num == 0 && dgcount == 1) {
		number[0] = '0';
		number[1] = '\0';
	}
	else {
		while (num != 0) {
			x = num % 10;
			number[index] = x + '0';
			index--;
			num = num / 10;
		}
		number[dgcount] = '\0';
	}
}
