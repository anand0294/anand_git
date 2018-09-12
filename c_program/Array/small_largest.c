/****************************************************************/
/* This program finds the smallest and largest no in an arrray **/
/****************************************************************/

#include<stdio.h>

#define SIZE 10

int main(void){
	int small, large, i, arr[SIZE];
	printf("Enter the elements of the array : \n");
	for(i=0; i<10; i++)
		scanf("%d", &arr[i]);
	small=arr[0];
	large=arr[0];
	for(i=0; i<10; i++){
		if(small>arr[i])
			small=arr[i];
		if(arr[i]>large)
			large=arr[i];
	}
	printf("Largest number is: %d and smallest no is : %d\n", large, small);
return 0;
}
