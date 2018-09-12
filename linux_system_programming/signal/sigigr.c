/*******************************************************************/
/* This program show how to handle signals 			   */
/******************	AUTHOR: ANAND MOHAN TIWARI	************/
/*******************************************************************/

#include<stdio.h>
#include<signal.h>

int main(){
	/* install signal handlers for 1 , 2 and 3 */
	signal(1, SIG_IGN);
	signal(2, SIG_DFL);
	signal(SIGPIPE, SIG_DFL);
/* use macros instead of constants as signal numbers to improve redability */
while(1){
                printf(" I am happy now , I will do same work forever\n");
        }

return 0;
}
