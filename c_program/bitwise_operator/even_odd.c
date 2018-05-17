/*******************************************************************/
/* This demonstrate how to check that number is even or odd        */
/******************* AUTHOR: ANAND MOHAN TIWARI ********************/
/*******************************************************************/

#include<stdio.h>
int main(){
	int num;
	printf("Enter the number : \n");
	scanf("%d", &num);
	if( num & 0x1 )
		printf("Number is ODD \n");
	else 
		printf("Number is EVEN\n");


return 0;
}
