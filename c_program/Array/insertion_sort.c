/*******************************************************************/
/*********** Program of sorting using insertion sort ***************/
/****************** AUTHOR : ANAND MOHAN TIWARI ********************/
/*******************************************************************/

#include<stdio.h>

#define MAX 100

int main(){
	int arr[MAX], i, j, k , size;
	
	printf("Enter number of elements in an array : \n");
	scanf("%d", &size);
	
	printf("Enter array elements \n");
	for(i=0; i<size; i++)
	scanf("%d", &arr[i]);
	
	//logic of insertion sort

	for(i=1; i<size; i++){

			k = arr[i];
			for(j = i-1; j>=0 && k<arr[j]; j--)	
					arr[j+1] = arr[j];
					arr[j+1] =k; 
	}

	printf("Sorted array is : \n");
	for(i=0; i<size; i++)
		printf("%d ", arr[i]);
	printf("\n");
		
return 0;
}
