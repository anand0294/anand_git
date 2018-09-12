/*******************************************************************/
/* This program shows how to kill the process with pid. Use ps -Af */
/* to know the pid.  	AUTHOR: ANAND MOHAN TIWARI		   */
/*******************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main(){
	pid_t pid;
	int sig_no;
	printf("Enter the process id for which the signal needs to sends:\n");
	scanf("%ld", &pid);
	printf("Enter the signal number you want to send\n");
	scanf("%d", &sig_no);
	kill(pid, sig_no);
	perror("Sig_res: ");
return 0;
}
