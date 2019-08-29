/*
Utilites to launch background programs (daemons)
Required .h Files: (UTILS.h)
*/

#define PID int

int apid[99];//100 max programs including the kernel

int assign_pid(){//Returns an avalible PID
  PID i = rand(10, 30);//Starts with rand number for PID
  int a = 1;//Used for while statment
  while(apid[99]){//Checks for conflicting PIDS
    if(a == 0){//Cannot overwrite the kernels PID
      a++;
    }
    if(i == apid[a]){
      i = rand(a, 15);//If a PID is unavalible it regenerates a new PId using i
    }
    a++;
  }
  return i;
}

int startd(){//Start a file to run in the background

}
