/*******************************************************************/
/*	This program show the use of clone system call 		   */
/*			AUTHOR: ANAND MOHAN TIWARI		   */
/*******************************************************************/
#define _GNU_SOURCE

#include<stdio.h>
#include<sched.h>
#include<stdlib.h>
#define STACK_SIZE 16000

int dosomething(void * arg){
	printf("\nYor are in child process\n");
	getchar();
return 0;
}


int main(){
	void * stack_size = malloc(STACK_SIZE);
	if(stack_size == NULL){
		printf("\nError in allocating Stack size\n ");
		exit(1);
	}
	clone(dosomething, stack_size+STACK_SIZE, CLONE_VM|CLONE_FILES, NULL);
	getchar();
	printf("\nIn parent process\n");	

return 0;
}
