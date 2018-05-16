/*******************************************************************/
/* This program Demonstrate how the value local variable is changed*/
/*******************************************************************/

#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

#define CHILD 0

int main(){
	pid_t pid;
	int k=10;
	int childstatus;
	printf("1.Parent pid : %d \n", getpid());
	pid = fork();

	printf("2. Current pid : %d \n", pid);

	if(pid == CHILD){
		printf("3. Child status pid : %d\n", getpid());
		k=44;
		printf("4.End of child K= %d\n", k);
		exit(100);
	}
	//parent
	else{

		printf("5. My pid = %d \n", getpid());
		printf("6.Newly created child pid = %d \n", pid);
		printf("7. *****of parent k = %d \n", k);
		wait(&childstatus);
		printf("8.End of parent k = %d\n ", k);
		printf("9.Child status = %d \n", WEXITSTATUS(childstatus));
	}

return 0;
}
