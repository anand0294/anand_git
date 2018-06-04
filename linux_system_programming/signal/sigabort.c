/*******************************************************************/
/* This program shows an example of when sigabort will be generated*/
/**************** AUTHOR : ANAND MOHAN TIWARI **********************/
/*******************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void signalabort(int signum){
	  printf(" abort signal received \n");
	  printf(" We can use this to perform clean up operation's\n");
return;
}

int main(){
	signal(SIGABRT, signalabort);
	printf(" some thing has gone worng\n");
        abort();
        printf(" can you see this\n");

return 0;
}
