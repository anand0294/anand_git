/********************************************************/
/* This program count even and odd numbers in an array */
/*******************************************************/

#include<stdio.h>

#define SIZE 10

int main(void){

	int i, even=0, odd=0, arr[SIZE];
	printf("Enter the elements of the array\n");
	for(i=0; i<10; i++){
		scanf("%d", &arr[i]);
		if(arr[i]%2==0)
			even++;
		else
			odd++;
	}
	printf("Number of odd elements : %d and no of even elements : %d\n",
							 odd, even);
	return 0;
}

