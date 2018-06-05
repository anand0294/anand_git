/*******************************************************************/
/* This program show the use of signal handler SIGALRM 		   */
/****************      AUTHOR: ANAND MOHAN TIWARI    ***************/
/*******************************************************************/

#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sig_alarm(int sig_num){
	printf("I have to wake up boss now\n");
	alarm(5);
}

int main(){
	signal(SIGALRM, sig_alarm);
	alarm(5);
	while(1){

	}
return 0;
}
