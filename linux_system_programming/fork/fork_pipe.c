/*
 * FIFO's
 * Author : ANAND MOHAN TIWARI
 * have your program Create a node using mkfifo or mknod function
 * call. Fork and then have the child stuff a message in the FIFO and
 * have the parent read it and print it out.
 */



#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<stdlib.h>
#include<stdio.h>

#define FIFO_NAME "/tmp/myfifo2"
#define DEATH(mess) { perror(mess); exit(errno);}

int main(int argc, char *argv[]){
	char  message[] = "Child will write this message to parent";
	int fd;
	pid_t pid;
	
	if(mkfifo(FIFO_NAME, 0666)<0)   /* creating pipe using mkfifo function*/
		DEATH(FIFO_NAME);
	printf("Created pipe : %s \n", FIFO_NAME);
	fflush(stdout);
	
	pid= fork();
	
	if(pid == 0){ /* Child*/
		fd = open(FIFO_NAME, O_WRONLY);
		printf("\nChild is sending to fifo %s *********\n", message);
		if(write (fd, message, sizeof(message)) < 0 )
			DEATH("write error from CHILD to FIFO");

		close(fd);
		exit(EXIT_SUCCESS);
	}

	else{

		fd = open(FIFO_NAME, O_RDONLY);

		if(read(fd, message, sizeof(message)) <0 )
			DEATH("Read error from Parent to FIFO");
	
		printf("Parent Recieved : %s \n",FIFO_NAME);
		printf("Message : %s\n", message);
		close(fd);
		if(unlink(FIFO_NAME))
		DEATH("HAD trouble in removing FIFO \n");
		exit(EXIT_SUCCESS);
	}
	DEATH("fork");


return 0;
}
