/* This program demonstrate the use of fputc() function *
 * Author: ANAND MOHAN TIWARI
 */

#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE * fp;
	int ch;
	fp = fopen("123.txt", "w");
	if(fp==NULL){
		perror("Failed to open\n");
	}
	printf("Enter text : \n");
	while((ch=getchar())!=EOF)
		fputc(ch, fp);
	fclose(fp);
return 0;
}
