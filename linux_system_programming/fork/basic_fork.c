/*******************************************************************/
/* This program demonstrate the basic implementation of fork().    */
/* fork() calls takes nothing as argument but returns the pid of   */
/* process. Header file's in which fork system call is defined is  */
/* #include<sys/types.h> and #include<unistd.h>. This is above line*/
/* Explains the very basic idea to implement the fork call. Fork() */
/* will create a replica of main process and takes all info of main*/
/*******************************************************************/
/****************** AUTHOR : ANAND MOHAN TIWARI ********************/
/*******************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
//	pid_t pid;
	fork();
	printf("PID of Child Process is : %d \n",getpid());

return 0;
}

/***********************************************************************/
/* fork is one of those system calls which is called once but ret- *****/
/* twice!. After fork both parent and child executes the same prog-*****/
/* ram. On success it will return the pid twice and on error return -1 */
/***********************************************************************/
