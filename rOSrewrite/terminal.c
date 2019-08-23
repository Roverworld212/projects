char icmd;
char kcode;

int terminal() {//rewriting this function because honestly im not even sure
	char ch[0];
	int i = 0;
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
