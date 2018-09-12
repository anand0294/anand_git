/*****************************************************************************/
/*This program shows the status of all 32GPIO signal(i.e.blocked orunblocked)*/
/*********************** AUTHOR : ANAND MOHAN TIWARI  ************************/
/*****************************************************************************/

#include<stdio.h>
#include<signal.h>

void check_block_signal(){
	sigset_t s;
	int res, i;
	sigprocmask(SIG_BLOCK, NULL, &s);
	for(i=1; i<=32; i++){
		res = sigismember(&s, i);
		if(res)	
			printf("Signal: %d is Blocked\n", i);
		else
			printf("Signal: %d is Not Blocked\n", i);
	}
	printf("\n");
return;
}

int main(){
	sigset_t s_set;
	//sigemptyset(&s_set);
	sigfillset(&s_set);
	sigprocmask(SIG_BLOCK|SIG_SETMASK, &s_set, NULL);
	check_block_signal();
return 0;
}

/* Output of above program is shown below. We can not block signal no 9 & 19
   as these are high priority signal
Signal: 1 is Blocked
Signal: 2 is Blocked
Signal: 3 is Blocked
Signal: 4 is Blocked
Signal: 5 is Blocked
Signal: 6 is Blocked
Signal: 7 is Blocked
Signal: 8 is Blocked
Signal: 9 is Not Blocked
Signal: 10 is Blocked
Signal: 11 is Blocked
Signal: 12 is Blocked
Signal: 13 is Blocked
Signal: 14 is Blocked
Signal: 15 is Blocked
Signal: 16 is Blocked
Signal: 17 is Blocked
Signal: 18 is Blocked
Signal: 19 is Not Blocked
Signal: 20 is Blocked
Signal: 21 is Blocked
Signal: 22 is Blocked
Signal: 23 is Blocked
Signal: 24 is Blocked
Signal: 25 is Blocked
Signal: 26 is Blocked
Signal: 27 is Blocked
Signal: 28 is Blocked
Signal: 29 is Blocked
Signal: 30 is Blocked
Signal: 31 is Blocked
Signal: 32 is Not Blocked
*/
