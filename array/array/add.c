/**************************************************/
/* This program shows how to add elements of array*/
/**************************************************/

#include<stdio.h>

#define SIZE 10

int main(void){
	int i, sum=0,arr[SIZE];
	printf("Enter the elements of array : \n");
	for(i=0; i<10; i++)
		scanf("%d", &arr[i]);
	//adding array elements
	for(i=0; i<10; i++)
		sum+=arr[i];
		printf("Sum of elements of array is : %d\n", sum);
return 0;
}
