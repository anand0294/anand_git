/**************************************************************/
/* This program shows how to pass individual elements of an   */
/************* array into the function ************************/
/**************************************************************/

#include<stdio.h>

#define SIZE 10

void func(int);

int main(void){
	int i, arr[SIZE];
	printf("Enter elements of an array : \n");
	for(i=0; i<SIZE; i++){
		scanf("%d", &arr[i]);
	}
	for(i=0; i<SIZE; i++){
		func(arr[i]);
	}
	return 0;
}

void func(int num){
	if(num%2 == 0)
		printf("Number is Even : %d \n", num);
	else
		printf("Number is odd : %d \n", num);
	return;
}
