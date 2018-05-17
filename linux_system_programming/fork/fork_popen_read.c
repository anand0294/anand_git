/*******************************************************************/
/* 	See fork_open_read and the execute these programs 	   */
/*************	AUTHOR: ANAND MOHAN TIWARI		************/
/*******************************************************************/

#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>

#define CHILD 0

int main(){

	int childstatus, fd;
	char buf[20];
	pid_t pid;
	pid = fork();
	fd= open("./test.txt", O_RDONLY);

	if(pid == CHILD){
		pread(fd, buf, 2, 0);
		printf("CHILD status buf[0] : %c\n", buf[0]);
		printf("CHILD status buf[1] : %c\n", buf[1]);
		close(fd);
	}
	else {
		wait(&childstatus);
		pread(fd, buf, 2, 0);
		printf("Parent status buf[0] : %c\n", buf[0]);
		printf("Parent status buf[1] : %c\n", buf[1]);
		close(fd);
		}
return 0;
}
