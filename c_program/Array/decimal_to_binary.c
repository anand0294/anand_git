/*******************************************************************/
/****** This program converts decimal no into binary number ********/
/*******************************************************************/

#include<stdio.h>

#define SIZE 15 //take size depends on requirement

int main(Void){
	int num,i=0, j, arr[SIZE];
	printf("Enter the number : \n");
	scanf("%d", &num);
	while(num>0){
		arr[i]=num%2;
		num/=2;
		i++;
	}
	printf("Binary form of above number is : \n");
	for(j= (i-1); j>=0; j--){
		printf("%d ", arr[j]);
	}
	printf("\n");
	return 0;
}
