/*******************************************************************/
/* This program show how to use sigaction api 			   */
/************* 	AUTHOR: ANAND MOHAN TIWARI	********************/
/*******************************************************************/

#include<stdio.h>
#include<signal.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h> //for memset
#include<unistd.h> //for sleep

#define DEATH(mess) {perror(mess); exit(errno);}

/* Install signal handlers */

void sig_init(int sig_num){
	printf ("We have received SIGINT: Will sleep for 2 seconds and continue\n");
    	sleep (10);
    	printf (" done sleeping 2 seconds\n");
}

void sig_quit(int sig_num){
	printf("We have received SIGQUIT: Aborting \n");
	abort();
}

int main(int argc, char * argv[]){
	struct sigaction act;

	memset(&act, 0, sizeof(act));

	/* Install signal handlers */
	act.sa_handler = sig_init;

	if((sigaction(SIGINT, &act, NULL))<0) /* for CTRL-C */
		DEATH("sigaction : ");
	printf("Successfully installed signal handler for SIGINT\n");
	
	act.sa_handler = sig_quit;

	if((sigaction(SIGQUIT, &act, NULL))<0)
		DEATH("sigaction : ");

	 /* Do something pointless, forever */
    for (;;) {
        printf ("This is a pointless message.\n");
        sleep (1);
    }

    exit (0);
}


/*USE pkill or kill to test this program*/
