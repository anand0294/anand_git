/*******************************************************************/
/* This program finds the smallest element of the array and swap   */
/************    it with 0th element of the array      *************/
/************     AUTHOR : ANAND MOHAN TIWARI          *************/
/*******************************************************************/

#include<stdio.h>

#define MAX 50

int main(){
	int arr[MAX], min=0, size, i;
	printf("Enter number of elements\n");
	scanf("%d", &size);
	printf("Enter array : \n");
	for(i=0; i<size; i++)
		scanf("%d", &arr[i]);
	for(i=0; i<size; i++){
		if( arr[min] > arr[i] )
			min=i;
	}
	int tmp;
	if(min!=0){
		tmp = arr[0];
		arr[0] = arr[min];
		arr[min] = tmp; 
	}
	printf("New array after swapping : \n");
	for(i=0; i<size; i++)
		printf("%d ", arr[i]);
return 0;
}    
