/*****************************************************************************/
/* This program shows to check which signal is blocked state or Unblock state*/
/******************** AUTHOR: ANAND MOHAN TIWARI  ****************************/
/*****************************************************************************/

#include<stdio.h>
#include<signal.h>

void check_block_signal(){
	sigset_t s;
	int i, res;
	sigprocmask(SIG_BLOCK, NULL, &s);
	for(i=1; i<=5; i++){
		res = sigismember(&s, i);
		if(res)
			printf("Signal Number : %d is Blocked\n", i);
		else
			printf("Signal number : %d is not blocked\n", i);
	}
return;
}



int main(){
	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set, 1);
	sigaddset(&set, 4);
	sigprocmask(SIG_BLOCK|SIG_SETMASK, &set, NULL);
	check_block_signal();
	sigprocmask(SIG_UNBLOCK, &set, NULL);
	printf("\n\n");
	check_block_signal();
return 0;
}
