#include<stdio.h>
#include<string.h>

void reverse(char *, int , int);

int main(){
	char str[50];
	int len, i;
	printf("Enter the string\n");
	scanf("%s",str);
	for(len=0; str[len]!= '\0'; len++);
	i=len;
	reverse(str, 0, i-1 );
	printf("%s\n",str);
return 0;
}

void reverse(char str[], int index, int len){
	char tmp;
		tmp=str[index];
		str[index]=str[len-index];
		str[len-index] = tmp;
	if(index==len/2){
		return;
	}
 	reverse(str, index+1, len);
return;
}
