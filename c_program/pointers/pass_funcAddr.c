/*******************************************************************/
/* This program show how to send a fuction address to another func */
/******************* AUTHOR : ANAND MOHAN TIWARI *******************/
/*******************************************************************/

#include<stdio.h>

void func(char, void (*fp)(float));
void func1(float);

int main(){
	printf("Function main() called : \n");
	func('a', func1);
return 0;
} 

void func( char x, void (* fp)(float)){

	printf("You are in func function : \n");
	(*fp)(9.7);
return;
}

void func1(float a){
	printf("Function func1() called : \n");
return;
}
