/* This program demonstrate how to create and terminate thread
Author: Anand Mohan Tiwari
*/

#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>

#define NPTHREAD 5

void * printhello(void * threadid){
	pthread_t tid;
	tid = (void *)*(long *)threadid;
	printf("hello thread #%ld \n",tid);
	pthread_exit(NULL);
}

int main(int argc, char * argv){
	pthread_t tid[NPTHREAD];
	int i, rc;
	for(i=0; i<NPTHREAD; i++){
	printf("In main thread #no : %d\n", i);
	rc = pthread_create(&tid[i], NULL, printhello, (void *)i );
	if(rc){
		printf("Fail to create thread, return value of pthread_create is %d\n", rc);
		exit(-1);
	}
	pthread_join(tid[i], NULL);	
	}
//last thing that main should do
	pthread_exit(NULL);
return 0;
}
