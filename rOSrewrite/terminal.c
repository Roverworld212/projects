char cmd[200];

int terminal() {
	pstring("Terminal Loaded", 1);
	do {
		pstring(">", 1);
		if (getcmd() == 1) {
			return 1;
		}
		else {
			if (interpretcmd(cmd) == 1) {
				return 1;
			}
		}
	} while (1 == 1);
	return 1;
}

int getcmd() {
	//Get keycode inputs and stores them
	char ch[1];
	char keycode = 0;
	int i = 0;
	do {
		ch[1] = get_ascii_char(keycode);
		cmd[i] = ch[1];
		++i;
		sleept(2);
	} while (keycode != KEY_ENTER);
	return 0;
}

int interpretcmd(char *str) {
	//Reads string and runs appropriate command
}