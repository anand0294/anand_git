/* This program demonstrate to copy the source file into destination
 * Author: ANAND MOHAN TIWARI
 */

#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE * sptr;
	FILE *dptr;
	int ch;
	sptr = fopen("source.txt", "r");
	if(sptr == NULL ) {
		perror("Open failed\n");
		exit(1);
	}
	dptr = fopen("destination.txt", "w");
	if( dptr == NULL ) {
		perror("Open failed\n");
		exit(1);
	}
	while( ( ch = fgetc( sptr )) !=EOF ) 
		fputc( ch, dptr );
	fclose(sptr);
	fclose(dptr);
return 0;
}
