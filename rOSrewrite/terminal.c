char cmd[200];

int terminal() {//rewriting this function because honestly im not even sure
	sleept();
	char kcode;
	char ch[0];
	int i = 0;

	while (1 == 1) {
		kcode = kin();
		if (kin == KEY_ENTER) {
			process_cmd();
		}
		else {
			ch[0] = gac(kcode);
			cmd[i] = ch[0];
			pchar(cmd[i]);
			i++;
			sleept();
		}
		
	}
	return 1;
}

void process_cmd() {
	if (STRCMP(cmd, "HALTKERN") == 0) {
		haltkern();
	}
	else {
		pstring("Invalid command: ", 0);
		pstring(cmd, 1);
		pstring(">", 0);
	}
	sleept();
}

