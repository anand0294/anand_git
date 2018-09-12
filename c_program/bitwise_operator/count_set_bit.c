/*******************************************************************/
/* This program shows to count the number of set bits in an integer*/
/********************* AUTHOR: ANAND MOHAN TIWARI ******************/
/*******************************************************************/

#include<stdio.h>


int main(){
	unsigned int num, mask, count=0,i ;
	printf("Enter the number \n");
	scanf("%d", &num);
	for(i=0; i<32; i++){
		mask = 1<<i;
		if((num&mask) != 0 )
			count++;
	}
	printf("Number of bits set is %d  \n", count);
/*
Another approach
	while(num!=0){
		if(num&1)//checking set bit
			++count;
		num>>=1;
	}
	printf("No of set bit is %d\n", count);
*/

/*
//Another approach
	while(num!=0){
		++count;
		num=(num&(num-1));//clearing the rightmost set bit one by one
	}


*/
return 0;
}
