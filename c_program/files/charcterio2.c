/* This program demonstrate the use fgetc() function *
 * Author: ANAND MOHAN TIWARI
 */
#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE * fp;
	int ch;
	fp = fopen("text.txt", "r");
	if(fp==NULL){
		perror("open failed\n");
	}
	while((ch=fgetc(fp))!=EOF)
	printf("%c", ch);
	fclose(fp);
return 0;
}
