#include<stdio.h>
int display_binary(unsigned int x){
	unsigned int mask=0x80000000;
	int count=0;
	while(mask>0){
		if(x&mask){
			printf("1");
			++count;

	}
		else printf("0");
		mask=mask>>1;
	}
		printf("\n No of bit set are :%d", count);
/*unsigned int mask;
int i;
	for(i=31; i>=0; i--){
	mask=1<<i;
		putchar((x&mask)? '1':'0');
		if(i%8==0)
		putchar(' ');
}*/
	printf("\n");
return 0;
}

int reverse(unsigned int d){
	unsigned int mask =0x00000001;
	while(mask>0){
	if(d&mask)
		printf("1");
	else
		printf("0");	
	mask=mask<<1;
}
printf("\n");
return 0;
}
void print_ones(unsigned int d){
	int count=0;
	while(d>0){
	d=d&(d-1);
	++count;
	}
	if(count==1)
		printf("It is a power of 2\n");
	else 	printf("Not a power of 2\n");


return;
}
int main(){
	int x;
	printf(" size of int is :%ld\n", sizeof(int));
	printf("Enter value of x");
	scanf("%d",&x);
	display_binary(x);
	reverse(x);
print_ones(x);
return 0;
}
