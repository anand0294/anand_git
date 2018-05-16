/*******************************************************************/
/*      This programs shows the basic use of fork() system call    */
/*******************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

#define CHILD 0

int main(){
	pid_t pid;
	
	printf("Parent pid : %d\n", getpid());
	pid = fork();
	printf("Current pid : %d\n", pid);
	getchar();
	if(pid == CHILD){
//		getchar();
		printf("Child pid : %d\n", getpid());
		//while(1);
	}
	
	//Parent
	else{
	//	getchar();
		printf("Parent Pid : %d\n", getpid());
		printf("Newly created Child pid : %d\n", pid);
		//while(1);
	}	
	
	
	
	return 0;
}
