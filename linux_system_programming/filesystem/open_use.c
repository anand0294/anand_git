/*******************************************************************/
/* This program reads a file and write into another created file   */
/* Usage : int open (const char *filename, int flag, mode_t mode)  */
/*******************************************************************/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char * argv[]){
	int rb, fdin, fdout;
	char buff[4096];
	fdin = open(argv[1], O_RDONLY);
	printf("FDin o/p : %d\n", fdin);
	fdout = open(argv[2], O_RDWR|O_CREAT|O_TRUNC, S_IRWXU);
	/*must give permission while creating new file otherwise
	 it will open in protected mode*/
	while((rb = read(fdin, buff, sizeof(buff)))>0)
		write(fdout, buff, rb);
	close(fdin);
	close(fdout);


return 0;
}
