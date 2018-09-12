/*******************************************************************/
/** This program shows how to pass whole array and find the sum ****/
/***** sum of square of individual elements of the array ***********/
/*******************************************************************/

#include<stdio.h>

#define SIZE 10

void func(int *);

int main(void){
	int  arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	func(arr);	
	return 0;
}

void func(int arr[]){
		int i, sum=0;
		for(i=0; i<SIZE; i++){
			arr[i] = arr[i]*arr[i];
			sum += arr[i];
		}
		printf("Sum of square of individual elements of array is :\
							 %d \n", sum);
	return;
}
