#include <stdio.h>
#include <string.h>
int main(){

	char str1[50] = "This Program is written by Anand Mohan Tiwari";
	char str2[5] = "by";
	char * res;
	res = strstr(str1, str2);
	printf( "First occurence of '%s' in '%s' is\n %s \n", str2, str1, res );
	return 0;
}
