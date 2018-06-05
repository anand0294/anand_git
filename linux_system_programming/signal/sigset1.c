/*******************************************************************/
/* This program demonstrate how to use sigset structure 	   */
/********** AUTHOR: ANAND MOHAN TIWARI			************/
/*******************************************************************/

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void sig_handler(int sig_num){
	printf("I am in sighandler \n");
return;
}
int main(){
	sigset_t set;
	signal(62, sig_handler);
	sigemptyset(&set);
	sigaddset(&set, 3);
	perror("sig3 : ");
	sigaddset(&set, 4);
	perror("sig4 : ");
	sigprocmask(SIG_BLOCK|SIG_SETMASK, &set, NULL);
	perror("sigmask : ");
	getchar();
	getchar();
	sigprocmask(SIG_UNBLOCK, &set, NULL);
	printf("Now signals are  unblocked \n");
	while(1);
return 0;
}
