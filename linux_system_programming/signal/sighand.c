/*******************************************************************************/
/* This program show the how to handle signal no 9 and 19 i.e.SIGKILL, SIGSTOP */
/**********************		AUTHOR: ANAND MOHAN TIWARI 	****************/
/*******************************************************************************/

#include<stdio.h>
#include<signal.h>

/* sig hand for one */

void sh_for_one(int arg){
		printf("I'm in signal handler number one (%d)", arg);
}
/* below is the handler for signal's 9*/
void sh_for_nine(int signum){
	printf("I'm in signal handler number nine (%d)", signum);
}

int main(){
	signal(1,sh_for_one); //Use SIGHUP instead of 1.
	signal(SIGKILL, sh_for_nine);
	perror("siginstall : ");
	getchar();
	getchar();
/* use macros instead of constants as signal numbers to improve redability */
	while(1){
                printf(" I am happy now , I will do same work forever\n");
        }
return 0;
}

//Result we cannot handle SIGKILL AND SIGSTOP as these are high priority interrupts
