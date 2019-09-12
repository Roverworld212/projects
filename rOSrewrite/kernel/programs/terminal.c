#include "TYPES.h"
#include "UIDEV.h"
#include "KUTILS.h"
#include "PANIC.h"
#include "IO.h"

int cwargs[99];//Store words for args
int cwargsnum = -1;//Used for cwargs array

int tmain(){//If this code is bad, then blame me
  sleept();
  char kcode;
  pstring(">", 1);
  while(1 == 1){
    kcode = kin();
    if(kcode == KEY_SPACE){
      int i = retcnum();
      if(cwargsnum != 0){
        cwargsnum++;
      }
      else{
      cwargsnum++;
      }
      cwargs[cwargsnum] = i;
      if(cwargsnum > 100){
        cwargsnum = 0;
      }
      rsetcn();
      sleept();
    }
    if(kcode == KEY_ENTER){
      cwargsnum++;
      pline();
      int i = retcnum();
      cwargs[cwargsnum] = i;
      rsetcn();
      ciarg();
      fcwargs();
    }else{
      char a = gac(kcode);
      pchar(a);
    }
    sleept();
  }
}

void sleept(){//Still dont know how sleep() works, it didnt have any comments on it or documentation
  sleep(0x02FFFFFF);
  sleep(0x02FFFFFF);
  sleep(0x02FFFFFF);
  sleep(0x02FFFFFF);
  sleep(0x02FFFFFF);
  sleep(0x02FFFFFF);
}

void fcwargs(){//Set all nums in the cwargs array to 0
  int i = 0;
  while(cwargs[i]){
    cwargs[i] = 0;
    i++;
  }
  cwargsnum = -1;
}

void ciarg(){//cinterp with args
  pstring("CWARGS1:", 0);
  pint(cwargs[0], 0);
  pstring("   CWARGS2: ", 0);
  pint(cwargs[1], 1);
  switch (cwargs[0]) {
    case 270://KPANIC
    kpanic();
    break;
    case 170://CLS
    //cls();
    break;
    case 265://DREGS (ARG1) This is a test command for arg input
    if(cwargs[1] == 0){
      pstring("No args! usage: DREGS ARG1", 1);
      break;
    }
    if(cwargs[1] == 165){
      pstring("REGISTER 0: 0x0", 1);//Not actually getting register 0's value just for testing
      break;
    }
    break;
    case 320://DVARS
    break;
    case 205://HELP
    pstring("Commands: KPANIC CLS DVARS HELP", 1);
    break;
    default://DEFAULT
    pstring("Invalid cmd", 1);
    break;
  }
  pstring(">", 0);
}
