#include "TYPES.h"
#include "UIDEV.h"
#include "UTILS.h"
#include "KUTILS.h"
#include "KERNEL.h"
#include "PANIC.h"
#include "IO.h"

int cwargs[99];//Store words for args
int cwargsnum = -1;//Used for cwargs array

int tmain(){//If this code is bad, then blame me
  sleept();
  char kcode;
  pstring(">", 0);
  while(1 == 1){
    kcode = kin();
    if(kcode == KEY_BACKSPACE){
      backspace();
      sleept();
    }
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

/*
I understand that using a huge switch statement is not the best solution
After time and enough commands it can become slow
This also wouldn't support custom command like packages from APT example: GCC
I will change it later for better support with APT and other package installers
Also my way of knowing what word was used is bad, numbers can be repeated and make some command incompatible
I will also fix this, for now this is the best solution I could find
I only started working on this OS so I could better learn their internals and understand them better
I hope you can be patient as I try my best to learn as I go
*/

void ciarg(){//cinterp with args
  dcwargs();
  switch (cwargs[0]) {
    case 270://KPANIC
    kpanic();
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
    case 460://SYSINF
    SYSINF();
    break;
    case 330://SBARGS
    sbargs();
    break;
    case 235://USAGE
    usage();
    break;
    case 320://DVARS
    break;
    case 205://HELP
    pstring("Commands: KPANIC CLS DVARS HELP DREGS USG SBARGS, SYSINF", 1);
    break;
    case 170://CLS
    cls();
    break;
    default://DEFAULT
    pstring("Invalid cmd", 1);
    break;
  }
  pstring(">", 0);
}

void SYSINF(){
  pstring("Kernel name: Roman", 1);
  pstring("Kernel version: 4.0", 1);//I may forget to update this value
  pstring("OS name: rOS (RoverOS)", 1);
}

void dcwargs(){
  if(bargs.DBENABLE == 1){
  pstring("CWARGS1:", 0);
  pint(cwargs[0], 0);
  pstring("   CWARGS2: ", 0);
  pint(cwargs[1], 1);
  pstring("CWARGS3:", 0);
  pint(cwargs[3], 0);
  pstring("   CWARGS4: ", 0);
  pint(cwargs[4], 1);
  }
}

void sbargs(){
  switch (cwargs[1]) {
    case 410://Disable VGA
    bargs.VGAENABLE = 0;
    break;
    case 225://Change DBENABLE with cwargs[3]
    if(cwargs[3] > 1){
      pstring("Inavlid 3rd Operand!", 1);
      break;
    }
    if(cwargs[3] < 0){
      pstring("Inavlid 3rd Operand!", 1);
      break;
    }
    bargs.DBENABLE = cwargs[3];
    break;
    case 350://Change GDTENABLE
    if(cwargs[3] > 1){
      pstring("Inavlid 3rd Operand!", 1);
      break;
    }
    if(cwargs[3 < 0]){
      pstring("Inavlid 3rd Operand!", 1);
      break;
    }
    bargs.GDTENABLE = cwargs[3];
    break;
    case 0://No second arg
    pstring("No 2nd arg!", 1);
    break;
    default:
    pstring("No args! See usage for help", 1);
    break;
  }
}

void usage(){//Used to help for the USG command
  switch (cwargs[1]) {
    case 270://KPANIC
    pstring("NO ARGS", 1);
    break;
    case 460://SYSINF
    pstring("NO ARGS", 1);
    break;
    case 265://DREGS (ARG1) This is a test command for arg input
    pstring("DREGS (REGISTER)", 1);
    break;
    case 235://USAGE
    pstring("USAGE (COMMAND)", 1);
    break;
    case 320://DVARS
    pstring("NO ARGS", 1);
    break;
    case 205://HELP
    pstring("NO ARGS", 1);
    break;
    case 330:
    pstring("SBARS (BOOT ARG) (1, 0)", 1);
    break;
    case 170://CLS
    pstring("NO ARGS", 1);
    break;
    default://DEFAULT
    pstring("Not a command", 1);
  }
}
