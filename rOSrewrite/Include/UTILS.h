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

void cmd_interpreter(){
  int a = 0;
switch (cmdnum) {
  case 445://HALTKERN
  haltkern();
  case 270://KPANIC
  kern_panic("COMMAND", 0, __FUNCTION__);
  case 220://CLEAR
  while(a != 11){
  pline();
  a++;
  }
  default:
  dkvar(__FUNCTION__);
  pstring("BAD CMD", 1);
  pstring(">", 0);
  cmdnum = 0;
  kpressed = 0;
  return;
}
}
