/*******************************************************************/
/* This program demonstrate how to insert the element at a partic- */
/* ular position in an array. The last element must be empty to do.*/
/******************* AUTHOR : ANAND MOHAN TIWARI *******************/
/*******************************************************************/

#include<stdio.h>

#define MAX 15

int main(){
	int arr[MAX], i, size, index, item;

	printf("Enter the number of elements\n");
	scanf("%d", &size);

	printf("Enter the elements of array\n");
	for(i=0; i<size-1; i++)
	scanf("%d", &arr[i]); //must have empty space at last to insert

	printf("Enter the item to insert\n");
	scanf("%d", &item);

	printf("Enter the position(minus 1) at which you want to enter\n");
	scanf("%d", &index);

	for(i=size-2; i>=index; i--)
		arr[i+1] = arr[i];
		arr[index]=item;
	printf("New array after insertion is : \n");
	for(i=0; i<size; i++)
		printf("%d ", arr[i]);
	printf("\n");

return 0;
} 
