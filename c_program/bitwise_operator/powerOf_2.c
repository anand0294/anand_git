/*******************************************************************/
/* This program shows to find whether a number is exact poer of 2  */
/******************** AUTHOR: ANAND MOHAN TIWARI  ******************/
/*******************************************************************/

#include<stdio.h>
 int main(){
	unsigned int num;
	printf("Enter the positive number:\n");
	scanf("%d", &num);
	if((num & (num-1)) == 0)
		printf("Number is exact power of two\n");
	else
		printf("Number is not a power of two \n");
/*
	unsigned int mask = 0x80000000;
	if(x&mask == 1 )
		printf("Number is power of two")
	else 
		printf("Number is not a power of two");



*/
return 0;
}
