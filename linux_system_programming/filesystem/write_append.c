/*******************************************************************/
/***   This program show how write works using append flag       ***/
/*******************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/stat.h>


int main(){
	int fd;
	off_t offset;
	fd = open("./newfile", O_RDWR|O_CREAT|O_APPEND,0766);
	/***************************************************/
	/* The file is opened in append mode. Before each  */
	/* write(2), the file offset is positioned at the  */
	/*       end of file, as if with lseek(2)          */
	/**************************************************/
	if(fd<0){
		perror("open() Fails\n");
		exit(1);
	}
	printf(".\n");
	write(fd, "one", 3);
	printf("..\n");
	offset = lseek(fd, 0, SEEK_CUR);
	printf("Current file pointer position is %ld \n", offset);
	write(fd, "Two", 3);
	write(fd, "Thr", 3);
	write(fd, "for", 3);
	offset = lseek(fd, 0, SEEK_CUR);
	printf("Current file pointer position is %ld \n", offset);
	write(fd, "fiv", 3);

return 0;
}
