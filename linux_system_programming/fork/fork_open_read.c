/*************************************************************************/
/* This program show the behaviour of open and read api in child & parent*/
/**********************AUTHOR : ANAND MOHAN TIWARI ***********************/
/*************************************************************************/

#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/wait.h>

#define CHILD 0

int main(){
	int childstatus, fd;
	char buf[20];
	pid_t pid;
	
	fd = open("./test.txt", O_RDONLY);
	
	pid = fork();

	if(pid == CHILD){
		read(fd, buf, 2);
		printf("In child Buffer contains : %c \n", buf[0]);
		printf("In child Buffer contains : %c \n", buf[1]);
		close(fd);
	}
	
	else{
		wait(&childstatus);
		read(fd, buf, 2);
		printf("In Parent Buffer contains : %c \n", buf[0]);
		printf("In Parent Buffer contains : %c \n", buf[1]);
		close(fd);
	}
return 0;
}

/*************************************************************************/
/* Watch or Download test.txt file before executing this on gcc compiler */
/*************************************************************************/

//Why and how it's executing like this??? 
