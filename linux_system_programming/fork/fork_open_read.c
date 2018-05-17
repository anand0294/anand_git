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

/* So when the first time read operation is performed in child, the file
offset is at position 0 offset then after performing 2 bytes read operation
 it's position i.e offset reaches to 2 and then we arre executing close.
This will close read the child read process and that will not affect the read call
 in parent because child copy is closed and aprent copy is still open as it is not sharing
the copied resources.
They are not sharing the same file descriptor. so if they are not sharing the same file descriptor
& read operation is valid then it must read yo in place of reading 're but it's reading 'r.
see man 2 notes :**************************
Under linux  fork() is implemented using copy o write pages, so the only penality that inoccurs
is the time and memory required to duplicate the parent's page table & to create a unique task 
structure for the child . *******************
The child has acquired fd in open state and close call is creating copy on write operation.
So, ANy change in the state will create a new copy and that copy is closed which means 
after read call in child, the parent and child is sharing the same copy and that is the reason
parent reads from fd.

So initiating a open or close operation will trigger copy on write operation .

So if we want that parent and child would not share current offset so we use pread and pwrite 
operation.  
*/


