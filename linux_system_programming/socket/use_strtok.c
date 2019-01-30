#include<stdio.h>
#include<string.h>

int main( void ){
	char str[80] = "This is - www.github.com/anand0294 - website";
	char s[2] = "-";	
	char * token;

	token = strtok(str, s);
	while( token!= NULL ){
		printf("%s \n", token);
		token = strtok(NULL, s);
	}
	return 0;
}
