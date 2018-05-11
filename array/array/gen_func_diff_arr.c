/*******************************************************************/
/* This program clearly explains the working of general functions **/
/*                on different size of array                      **/
/*******************************************************************/

#include<stdio.h>

int add(int *, int);

int main(void){
	int a[5]={1, 2, 3, 4, 5};
	int b[6]={1, 2, 3, 4, 5, 6};
	int c[10]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	printf("Sum of elements of array is : %d \n", add(a, 5));
	printf("Sum of elements of array is : %d \n", add(b, 6));
	printf("Sum of elements of array is : %d \n", add(c, 10));
	return 0;
}

int add(int arr[], int size){
	int i, sum=0;
	for(i=0; i<size; i++)
		sum+=arr[i];
	return sum;

}
