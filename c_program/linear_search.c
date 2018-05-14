/**********************************************************************/
/*This program search the given item from begining to end in an arrray*/
/**********************************************************************/

#include<stdio.h>

#define SIZE 50

int linear_search(int *, int, int);


int main(){
	int arr[SIZE], n, i, index, item, len=0;
	printf("Enter the number of elements of array\n");
	scanf("%d", &n);
	printf("Enter array elements\n");
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
		len++;
	}
	printf("Enter the item to search\n");
	scanf("%d", &item);
	index=linear_search(arr, len, item);
	if(index==-1)
		printf("%d not found \n", item);
	else
		printf("%d found at %d position \n", item, index);
	return 0;
}

int linear_search(int arr[], int size, int item){
	int i=0;
	while( i<size && item !=arr[i])
		i++;
		if(arr[i]==item)
			return i+1;
		else
			return -1;

	return 0;
}
