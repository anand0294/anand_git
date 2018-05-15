/*******************************************************************/
/* This program shows how to pass a pointer containig function's   */
/****************      address as an argument     ******************/
/****************   AUTHOR : ANAND MOHAN TIWARI   ******************/
/*******************************************************************/

#include<stdio.h>

void func(char, void (*fp)(float));
void func1(float);

int main(){
	void (*fp)(float);
	fp = func1;
	printf("Function main() called : \n");
	func('b', fp);
return 0;
}

void func(char x, void (*fp)(float)){

	printf("Function func() called : \n");
	(*fp)(8.7); //calling function indirectly using function pointer
return;
}

void func1(float x){

	printf("Function func1 called : \n");
return;
}
