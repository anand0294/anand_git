/*********************************************************************/
/* This program shows to exchange two adjacent array elements if 1st */
/******************  is greater than 2nd elemnt   ********************/
/******************* AUTHOR : ANAND MOHAN TIWARI  ********************/
/*********************************************************************/

#include<stdio.h>

#define MAX 50

int main(){
	int tmp, arr[MAX], i, j, size;

	printf("Enter number of elements: \n");
	scanf("%d", &size);

	printf("Enter array elements \n");
	for(i=0; i<size; i++)
		scanf("%d", &arr[i]);

	for(j=0; j<size-1; j++){
		if(arr[j] > arr[j+1 ] ){
			tmp = arr[j];
			arr[j] = arr[j+1];
			arr[j+1] = tmp;
		}
	}

	printf("Sorted array in ascending order is : \n");
	for(i=0; i<size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
return 0;
} 
