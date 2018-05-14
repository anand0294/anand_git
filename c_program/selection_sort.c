/*******************************************************************/
/* This program explains to sort the array in ascending order using*/
/* selection sort method. please refer smallest_swap_array0.c inmy */
/******** git repository before going through this module.**********/
/***************** AUTHOR : ANAND MOHAN TIWARI *********************/
/*******************************************************************/

#include<stdio.h>

#define MAX 50

int main(void){
	int min=0, arr[MAX], size, i, j, tmp;
	printf("Enter the number of elements\n");
	scanf("%d", &size);
	printf("Enter array elements\n");
	for(i=0; i<size; i++)
		scanf("%d",&arr[i]);
	for(i=0; i<size; i++){
		min =i;
		for(j= i+1; j<size; j++){
			if(arr[min]>arr[j])
				min=j;
		}
		//Selection sort
		if(i!=min){
			tmp= arr[i];
			arr[i] = arr[min];
			arr[min] = tmp;
		}
	}
	printf("Sorted array is : \n");
	for(i=0; i<size; i++)
		printf("%d ", arr[i]);
	printf("\n");
return 0;
}
