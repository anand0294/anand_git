/*******************************************************************/
/**** This program shows to search a element in the array using ****/
/**********            binary search method             ************/
/**********           AUTHOR : ANAND MOHAN TIWARI       ************/
/*******************************************************************/

#include<stdio.h>

#define MAX 50

int binary_search(int *, int , int);

int main(){
	int arr[MAX], item, i, index, size;
	printf("Enter number of elements : \n");
	scanf("%d", &size);
	printf("Enter array elements\n");
	for(i=0; i<size; i++)
		scanf("%d", &arr[i]);
	printf("Enter the item to search\n");
	scanf("%d", &item);
	index = binary_search(arr, size, item);
	if(index == -1){
		printf("Item not found\n");
	}
	else
		printf("%d found at position %d \n ", item, index);
return 0;
}

int binary_search(int arr[], int size, int item){
	int up, low, mid;
	low=0;
	up = size-1;
	while(low<=up){
		mid = (( low + up )/2);
		if( item>arr[mid] )
			low= mid + 1;  //Search in right half
		else if( item < arr[mid] )
				up = mid - 1; //search in left half
		else
			return mid;
	}

return -1;
}
