/*******************************************************************/
/* Show what happen in child when open call is invoked in parent   */
/******************** AUTHOR : ANAND MOHAN TIWARI ******************/
/*******************************************************************/

#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/wait.h>

#define CHILD 0

int main(){
	int fd, childstatus;
	char buf[20];
	pid_t pid;

	pid = fork();

	if(pid == CHILD){
		read(fd, buf, 2);
		printf("Child status buf[0] is : %c \n", buf[0]);
		printf("Child status buf[1] is : %c \n", buf[1]);
		close(fd);
	}
	else {
		fd = open("./test.txt", O_RDONLY);
		wait(&childstatus);
		read(fd, buf, 2);
		printf("Parent status buf[0] is : %c \n", buf[0]);
		printf("Parent status buf[1] is : %c \n", buf[1]);
		close(fd);

	} 
return 0;
}

/*You will get one warning in this message as fd is used then initialized */
