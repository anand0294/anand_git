/*******************************************************************/
/* Function pointer can be used in application's where we don't kn-*/
/* ow in advance which function will be called. In that case we can*/
/* take the address of different functions in an array and then    */
/* call the appropriate function depending on some index number    */
/*******************************************************************/
/**************** AUTHOR : ANAND MOHAN TIWARI **********************/
/*******************************************************************/

#include<stdio.h>

float add(float, float);
float sub(float, float);
float mul(float, float);
float div(float, float);

int main(){
	float a, b;
	int i;
	float (*fp [])(float, float) = { add, sub, mul, div};
	char * operation[] = { "Add", "SUB", "MUL", "DIV"};
	
	printf("Enter numbers : \n");
	scanf("%f%f", &a, &b);
	for(i=0; i<4; i++)
		printf("%s : %f\n", operation[i], (*fp [i] ) (a,b));
	return 0;

}

float add(float x, float y){

	return x + y;
}


float sub(float x, float y){

	return x - y;
}


float mul(float x, float y){

	return x * y;
}


float div(float x, float y){

	return x / y;
}

