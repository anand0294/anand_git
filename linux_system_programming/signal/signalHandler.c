/*******************************************************************/
/* This program will show how to handle more than one signal       */
/*		AUTHOR: ANAND MOHAN TIWARI			   */
/*******************************************************************/

#include<stdio.h>
#include<signal.h>

static int one_occured = 0;
static int tt_occured = 0;

/* below is the handler for signal 1 */

void sh_for_one(int arg){
	one_occured = 1;
	printf("This is handler for signal one\n");
return;
}

/* below is the handler for signal's 2 and 3*/

void sh_for_tt(int arg){
	tt_occured = 1;
	printf("This is handler for signal two and three\n");
return;
}

int main(){
        /* install signal handlers for 1 , 2 and 3 */
	signal(1, sh_for_one);
	signal(2, sh_for_tt);
	signal(3, sh_for_tt);
	/* use macros instead of constants as signal numbers to improve redability */
	while(1){
		printf("I'm happy, i'll do the same work forever\n");
		if(one_occured)
			goto bad_work;
	}
bad_work :
		while(1){
			printf("I'm doing bad work for my survival\n");
			if(tt_occured)
				goto die;
		}
die :
		while(1){
			printf("I'm Going to die some day\n");

		}

return 0;
}
