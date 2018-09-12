/*****************************************************************************/
/* This program shows to check which signal is blocked state or Unblock state*/
/********************** AUTHOR: ANAND MOHAN TIWARI  **************************/
/*****************************************************************************/

#include<stdio.h>
#include<signal.h>

void check_block_signal(){
	sigset_t s;
	int res, i;
	sigprocmask(SIG_BLOCK, NULL, &s);
	for(i=1; i<=5; i++){
		res= sigismember(&s,i);
		if(res)
			printf("Signal : %d is blocked\n",i);
		else
			printf("Signal : %d is not blocked\n",i);
	}
	printf("\n");
return;
}

int main(){
	sigset_t s_set;
	sigemptyset(&s_set);
	sigaddset(&s_set, 1);
	sigaddset(&s_set, 4);
	sigprocmask(SIG_BLOCK|SIG_SETMASK,&s_set,NULL);
	check_block_signal();
	sigemptyset(&s_set);
	sigaddset(&s_set, 2);
	sigprocmask(SIG_BLOCK|SIG_SETMASK, &s_set, NULL);
	check_block_signal();
return 0;
}

/* output of above program is shown below :
1st sigprocmask api call output
Signal : 1 is blocked
Signal : 2 is not blocked
Signal : 3 is not blocked
Signal : 4 is blocked
Signal : 5 is not blocked

2nd sigprocmask api call output
Signal : 1 is not blocked
Signal : 2 is blocked
Signal : 3 is not blocked
Signal : 4 is not blocked
Signal : 5 is not blocked

This time SIG_SETMASK set the new changed signal configuration so we get the output.
*/ 
