#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
/*Daemon output id
//[i]=Info
//[e]=Error
//[p]=Proccess
//[c]=Critical Error
*/
//PublicDaemonVars
char rsl[] = "";//Enter dir to create log at w/.txt at the end
char dwd[]= "";//Working directory for the daemon
//MainFunc
int main(void){
pid_t pid, sid;
/* Fork off the parent process */
pid = fork();
printf("%d\n", pid);
if (pid < 0) {
exit(EXIT_FAILURE);
}
/* If we got a good PID, then
we can exit the parent process. */
if (pid > 0) {
exit(EXIT_SUCCESS);
}
/* Change the file mode mask */
umask(0);
/* Open any logs here */
if( access( rsl, F_OK ) != -1 ) {
remove(rsl);
}
FILE *fp = NULL;
fp = fopen(rsl ,"a");
/* Create a new SID for the child process */
sid = setsid();
if (sid < 0) {
exit(EXIT_FAILURE);
}
/* Change the current working directory */
if ((chdir(dwd)) < 0) {
exit(EXIT_FAILURE);
}
/* Close out the standard file descriptors */
close(STDIN_FILENO);
close(STDOUT_FILENO);
close(STDERR_FILENO);
/* Daemon-specific initialization goes here */
fprintf(fp, "[i]Daemonized!\n");
fprintf(fp, "[i]Log_start\n");
/* The Big Loop */
while (1) {
fprintf(fp, "[i]Task_start\n");
fprintf(fp, "[i]Task_end\n");//Runs at the end of process
fclose(fp);
sleep(30); /* wait 30 seconds */
}
exit(EXIT_SUCCESS);
}
