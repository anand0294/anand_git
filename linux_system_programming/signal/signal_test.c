/*******************************************************************/
/* This program demonstrate the basic test of signal;the idea is to*/
/* block the execution of application. AUTHOR : ANAND MOHAN TIWARI */
/*******************************************************************/

#include<stdio.h>

int main(){
	printf("\n In application\n");
	getchar();
return 0;
}

/*##################################################################*/
/*just compile and try kill -1 pidno, again compile and try pkill -2*/
/* process name : which must be unique e.g. pkill -2 a.out and      */
/* and observe the result carefully.                                */
/*##################################################################*/
