/*******************************************************************/
/* Program to read from a file and write into another file         */
/*******************************************************************/

#include<unistd.h>
#include<fcntl.h>

#define SIZE 4096

int main(int argc, char * argv[]){
	int nb, fdin, fdout;
	char buff[SIZE];

	fdin = open(argv[1], O_RDONLY);
	fdout = open(argv[2], O_RDWR|O_CREAT|O_TRUNC, S_IRWXU); 
		//permission must be necessary while creating file i.e S_IRWXU

	while((nb = read(fdin, buff, sizeof(buff)))>0)
		write(fdout, buff, nb);
	close(fdin);
	close(fdout);
return 0;
}
