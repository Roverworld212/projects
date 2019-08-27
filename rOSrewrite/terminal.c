char icmd;
char kcode;

int terminal() {//rewriting this function because honestly im not even sure
	char ch[0];
	int i = 0;
	sleept();
	while (1 == 1) {
		kcode = kin();
		if(kcode == KEY_ENTER){
			sleept();
			pline();
			cmd_interpreter();
			sleept();
		}
		else{
			ch[0] = gac(kcode);
			pchar(ch[0]);
			sleept();
		}
	}
	sleept();
	return 1;
}

void cmd_interpreter(){
  int a = 0;
switch (cmdnum) {
  case 445://HALTKERN
  haltkern();
  case 270://KPANIC
  kern_panic("COMMAND", 0, __FUNCTION__);
  case 195://CLEAR
  clear_vga_buffer(&vga_buffer, WHITE, BLACK);
	return;
  default:
  dkvar(__FUNCTION__);
  pstring("BAD CMD", 1);
  pstring(">", 0);
  cmdnum = 0;
  kpressed = 0;
  return;
}
}

void cmd_iointerp(){//Interprets CMDS with spaces for inputs

}
