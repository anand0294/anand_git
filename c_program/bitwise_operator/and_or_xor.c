/*******************************************************************/
/* This program demonstrate the OR, AND, XOR operations in bitwise */
/*     operator and diplays the value in binary form.              */
/******************AUTHOR : ANAND MOHAN TIWARI *********************/
/*******************************************************************/

#include<stdio.h>

void display(unsigned int );

int main(){
	 int x, y;
	printf("Enter two numbers in hex form: \n");	
	scanf("%x%x", &x, &y);
	printf("Value of x : %x\n", x);
	display(x);
	printf("Value of y : %x\n", y);
	display(y);
	printf("Value of X&Y : %x\n", x&y);
	display(x&y);
	printf("Value of X|Y : %x\n", x|y);
	display(x|y);
	printf("Value of X^Y : %x\n", x^y);
	display(x^y);
	printf("Value of ~X : %x\n", ~x);
	display(~x);
	printf("Value of ~Y : %x\n", ~y);
	display(~y);
	

return 0;
}


void display(unsigned int x){
	unsigned int mask = 0x80000000;
	/*while(mask>0){
		if(x&mask){
			printf("1");
		}
		else
			printf("0");
		mask=mask>>1;
	}
	printf("\n");*/

	int i;
	for(i=31; i>=0; i--)
	{
		mask = 1<<i;
		putchar((x&mask)?'1':'0');
		if(i%8 ==  0)
			putchar(' ');


	}
	printf("\n");
return;
}
