/****************************************************************************/
/* Inter process communication between child and parent using shared memory */
/***********************   AUTHOR : ANAND MOHAN TIWARI  *********************/
/****************************************************************************/

#include<sys/types.h>
#include<sys/mman.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
	int fd = -1, status, len = 4096;
	pid_t pid;
	char * area;

	area = mmap(NULL,len, PROT_READ | PROT_WRITE, MAP_SHARED| MAP_ANONYMOUS, fd, 0 );
	/* mmap(void * addr(if NULL kernel wil automatically take care of assigning virtual address in calling context), 
		len(size of page you want to allocate),
		int prot(permission regarding read or write), 
	   	int flag(Memory may be shared private or anonymous), 
		int fd(must be -1 for MAP_ANONYMOUS to take default values), 
		off_t offset(0 for starting position)) 
	returns the starting address */

	pid = fork();

	if(pid == 0){
		strcpy(area, "This is a message from child");
		printf("Child writes : %s\n", area);
		exit(0);
	}
	else{

		wait(&status);
		printf("Parent reads : %s\n", area);
		exit(0);
	}

	return 0;
}
