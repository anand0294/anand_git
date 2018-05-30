/*******************************************************************/
/***This program demonstrate to sort array elements in ascending ***/
/*************** order using bubble sort method ********************/
/*************** AUTHOR : ANAND MOHAN TIWARI    ********************/
/*******************************************************************/

#include<stdio.h>

#define MAX 100

int main(){
	int arr[MAX], i, tmp, k, size;
	printf("Enter number of elements \n");
	scanf("%d", &size);
	printf("Enter array elemets : \n");
	for(i=0; i<size; i++)
		scanf("%d", &arr[i]);
	for( k=0; k<size-1; k++ ){
		for(i=0; i<size-k-1; i++){
			if(arr[i] > arr[i+1]){
				tmp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = tmp;
			}
		}

	} 
	printf("Sorted array is : \n");
	for(i=0; i<size; i++)
		printf("%d ", arr[i]);
	printf("\n");
return 0;
} 
