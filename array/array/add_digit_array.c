#include<stdio.h>

#define SIZE 50

int main(void){
	unsigned int i, sum=0, arr[SIZE];
	printf("Enter elements of array\n");
	for(i=0; i<SIZE; i++){
			scanf("%d", &arr[i]);
	}
		while(arr[i] >= 0 || arr[i] <=9){
			if(arr[i]>0)
				printf("%d ", arr[i]);
			//	printf("Cannot print leading zero's\n");
		else{
			printf("Number must be between 0 to 9 \n");
			return 0;
		}
		}
		
	for(i=0; i<SIZE; i++){
		sum += arr[i];
	}
	printf("%d\n", sum);

	return 0;
}
