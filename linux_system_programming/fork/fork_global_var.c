/******************************************************************/
/* This program shows the sharing of global variable in both(C &P)*/
/******************** AUTHOR: ANAND MOHAN TIWARI ******************/
/******************************************************************/


#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>

#define CHILD 0

int global;

int main(){
	int childstatus;
	pid_t pid;
	//global =1;
	pid = fork();
	global= 1;
	if(pid == CHILD){
		printf("Child pid is : %d \n ", getpid());
		printf("Fork return value in child : %d \n", pid);
		printf("Global variable value before changement in child :%d\n", global);
		global = 25;
		printf("Value after changement : %d \n", global);
	}
	else{
		wait(&childstatus);
		printf("Parent pid : %d \n", getpid());
		printf("Fork return value in parent : %d \n", pid);
		printf("Global varaible in parent :%d \n", global);


	}
return 0;
}

/* This program after executing clearly demonstrate that the changed value
in child is not used by the parent. Parent is accessing only global variable*/
