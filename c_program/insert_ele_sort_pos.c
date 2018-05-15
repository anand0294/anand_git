/*******************************************************************/
/* This program demonstrate to insert an item in an sorted array at*/
/*     the proper place by shifting other element to the right     */
/******************** AUTHOR : ANAND MOHAN TIWARI ******************/
/*******************************************************************/

#include<stdio.h>

#define MAX 15

int main(){
	int arr[MAX], size, i, item ;
	printf("Enter number of elements\n");
	scanf("%d", &size);

	printf("Enter elements of array \n");
	for(i=0; i<size-1; i++)
		scanf("%d", &arr[i]); //last element must be empty to insert a new element
	
	printf("Enter the item to insert : \n");
	scanf("%d", &item);

	for(i=size-2; item < arr[i] && i>=0; i--)
		arr[i+1] = arr[i]; // shift elements to right 
		arr[i+1] = item;

	printf("Array in sorted form is : \n");
	for(i=0; i<size; i++)
		printf("%d ", arr[i]);
		printf("\n");
return 0;
}
