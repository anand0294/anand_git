#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
void * func1(void * p){
	printf("You are in thread 1\n");
return;
}
void * func2(void * p){
	printf("You're in thread 2\n");
return;
}
int main(){
	
	pthread_t id1, id2;
	
	id1=pthread_create(&id1, NULL, func1, NULL);
	if(id1){
		printf("thread 1 creation failed :\n");
		exit(-1);
}
	pthread_join(id1, NULL);
	id2= pthread_create(&id2, NULL, func2, NULL);
	if(id2){
		perror("Thread 2 creation fail\n");
		exit(-1);
	}
	pthread_join(id2, NULL);
	pthread_exit(NULL);
return 0;
}
