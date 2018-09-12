/*******************************************************************/
/* This program will show how to catch interrupt signal		   */
/* 			AUTHOR: ANAND MOHAN TIWARI		   */
/*******************************************************************/

#include<stdio.h>
#include<signal.h>

void signal_handler(int arg){
	printf("Interrupt signal received \n");
return;
}

int main(){
	signal(SIGINT, signal_handler);	
	while(1){
//		printf("You're in infinite loop\n");
	}
return 0;
}
