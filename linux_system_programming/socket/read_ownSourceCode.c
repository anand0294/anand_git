/*
 * Author: Anand Mohan Tiwari
 * Description: C program to read it's own Source Code
 */

#include <stdio.h>

int main(void){
	FILE * fp;
	char c;
	fp = fopen(__FILE__, "r");
	
	do{
		c = fgetc(fp);
		putchar(c);
	}while(c!=EOF);
	fclose(fp);

	return 0;
}
