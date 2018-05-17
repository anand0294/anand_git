/*******************************************************************/
/* This program shows how does bit pattern of n changes after      */
/* n=n&(n-1). i.e Clear rightmost 1 bit                            */
/******************** AUTHOR : ANAND MOHAN TIWARI ******************/
/*******************************************************************/

#include<stdio.h>

void display(unsigned int x){

	int i,mask;
	for(i=31; i>=0; i--){
	mask =i<<1;
	putchar((x&mask?'1' : '0'));
	if(i%8==0)
		putchar(' ');

	}
return ;

}

int main(){
	int num;
	printf("Enter number:\n");
	scanf("%d", &num);
	display(num);
	printf("\n");
	printf("Number after num&(num-1) : \n");
	num = num&(num-1);
	display(num);
//rightmost bit is cleared 

	printf("\n");


return 0;
}
