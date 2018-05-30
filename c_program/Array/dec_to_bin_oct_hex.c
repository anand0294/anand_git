/*******************************************************************/
/** This program converts decimal no to binary, octal, hexadecimal */
/*******************************************************************/

#include<stdio.h>

void func(int, int);

int main(){

	int base, num;
	printf("Enter the number\n");
	scanf("%d", &num);
	printf(" 1.Binary \n 2.octal \n 3.Hexa decimal \n");
	printf("Enter your choice \n");
	scanf("%d", &base);
	switch(base){
	case 1: printf("Binary Equivalent is : \n");
			func(num, 2);
			break;
	case 2: printf("Octal Equivalent is : \n");
		func(num, 8);
		break;
	case 3: printf("Hexa decimal equivalent is : \n");
		func(num, 16);
		break;
	}
	return 0;
}


void func(int num, int base){
	int arr[20], rem, i=0, j;
	while(num>0){
		rem=num%base;
		num/=base;
		if(rem>9 && rem<16)
			arr[i++]= rem - 10 + 'A';
		else
			arr[i++] = rem + '0';
	}
	for(j=i-1; j>=0; j--)
		printf("%c ",arr[j] );
	printf("\n");


}
