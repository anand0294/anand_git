/*******************************************************************/
/********* Program to understand dynamic memory allocation *********/
/**********	    AUTHOR : ANAND MOHAN TIWARI         ************/
/*******************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(void){
	int n, i, *p;
	printf("Enter the number of integers to be entered : \n");
	scanf("%d", &n);
	
	p=(int *)malloc(n*sizeof(int));
	printf("Enter integers : \n");
	for(i=0; i<n; i++)
		scanf("%d", (p+i));
	printf("You Entered : \n");
	for(i=0; i<n; i++)
		printf("%d ", *(p+i));
	printf("\n");
return 0;
} 
