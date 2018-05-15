/*******************************************************************/
/*   This program demonstrate how to print the function address    */
/*****************  AUTHOR : ANAND MOHAN TIWARI  *******************/
/*******************************************************************/

#include<stdio.h>

void func(void);

int main(){
	printf("Address of main function is : %p\n", main);
	printf("Address of func function is : %p\n", func);
return 0;
}

void func(){
	printf("You are in func function\n");
return; 
}
