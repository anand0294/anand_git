/*******************************************************************/
/* This program shows how memory is divided into parent and child  */
/******************* AUTHOR : ANAND MOHAN TIWARI *******************/
/*******************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){

	int * p = (int * )malloc(sizeof(int));
	pid_t pid;
	
	pid = fork();
	if(pid ==0){

		*p =25;
		printf("Child pid is %d, value in pointer %d, address of pointer p is %p \n", getpid(), *p, p );
	}
	else{
		*p =15;
		printf("Parent pid is %d, value in pointer %d, address of p is %p \n", getpid(), *p, p);
	}
return 0;
}


// The memory address for both child and parent is same using pointers
