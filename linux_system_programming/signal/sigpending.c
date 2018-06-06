/*******************************************************************/
/* This program show how to check the pending signals 		   */
/****************** AUTHOR: ANAND MOHAN TIWARI  ********************/
/*******************************************************************/

#include<stdio.h>
#include<signal.h>

void check_pending_signal(sigset_t s){
	//sigset_t s;
	int res, i;
	sigprocmask(SIG_BLOCK, NULL, &s);
	for(i=0; i<=5; i++){
		res = sigismember(&s, i);
		if(res)
			printf("Signal : %d is in pending state\n", i);
		else
			printf("Signal : %d is not in pending state \n", i);
	}
	printf("\n");

return;
}

void sig_handler(){
	printf("I'am in signal handler\n");
return;
}

int main(){
	sigset_t s_set, s;
	signal(1,sig_handler);
	sigemptyset(&s_set);
	sigaddset(&s_set, 1);
	sigprocmask(SIG_BLOCK|SIG_SETMASK,&s_set, NULL);
	printf(" Send me signal one and see the effect now \n");
        getchar();
        getchar();
	sigpending(&s);
	check_pending_signal(s);
        getchar();
        sigprocmask(SIG_UNBLOCK,&s_set,NULL);
        printf(" Now signals are unblocked \n");
        while(1);
return 0;
}
