/*******************************************************************/
/* This program shows how to handle signals using fork() sys call  */
/********************** AUTHOR: ANAND MOHAN TIWARI *****************/
/*******************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

#define CHILD 0

int childstatus;

void sighand(int signum){
	printf("I am in signal Handler\n");
	wait(&childstatus);
}

int main(){
	pid_t pid;
	
	pid = fork();

	if(pid == CHILD){
		printf("I'm in Child Task\n");
	}

	else{
		printf("I'm in parent task\n");
		signal(SIGCHLD, sighand);
		printf("I'm in parent task1\n");
//		while(1);

	}

return 0;
}
