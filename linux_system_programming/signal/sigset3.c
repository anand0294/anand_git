/*******************************************************************************/
/*This program shows to check which signal is in blocked state or Unblock state*/
/******************* 	AUTHOR: ANAND MOHAN TIWARI	    ********************/
/*******************************************************************************/

#include<stdio.h>
#include<signal.h>

void check_signal_block(){
	sigset_t s;
	int res, i;
	sigprocmask(SIG_BLOCK, NULL, &s);//First parameter is not considered, we're checking old signal param
	for(i=1; i<=5; i++){
		res = sigismember(&s, i);
		if(res)
			printf("Signal : %d is blocked\n", i);
		else
			printf("Signal : %d is Unblocked\n", i);
	}
	printf("\n");
return;
}

int main(){
	sigset_t s_set;
	sigemptyset(&s_set);
	sigaddset(&s_set, 1);
	sigaddset(&s_set, 4);
	sigprocmask(SIG_BLOCK|SIG_SETMASK, &s_set, NULL);
	sigemptyset(&s_set);
	sigaddset(&s_set, 2);
	sigprocmask(SIG_BLOCK, &s_set, NULL);
	check_signal_block();
return 0;
}

/*use SIG_SETMASK store the previous result of s_set structure even after doing empty.
  again put SET_SIGMASK in second sigprocmask call and see the result
*/     
