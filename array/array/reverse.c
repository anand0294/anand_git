/*******************************************************************/
/******  This program reverse the elements of the array ***********/
/******************************************************************/

#include<stdio.h>

#define SIZE 10

int main(){
	
	int i, j, tmp, arr[SIZE];
	printf("Enter the elements of the array : \n");
	for(i=0; i<10; i++){
		scanf("%d", &arr[i]);
	}
	for(i=0, j=9; i<j; i++, j--){
		tmp=arr[i];
		arr[i]=arr[j];
		arr[j]=tmp;
	}
	printf("Array in reverse order is :  ");
	for(i=0; i<10; i++){
		printf("%d  ", arr[i]);
	}
	printf("\n");
	return 0;
} 
