/******************************************************************************
* FILE: hello_arg1.c
* DESCRIPTION:
*   A "hello world" Pthreads program which demonstrates one safe way
*   to pass arguments to threads during thread creation.
* AUTHOR: Blaise Barney
* LAST REVISED: 18/06/18
******************************************************************************/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREAD 8

char * messages[NUM_THREAD];

void * printhellow(void * threadid){
	pthread_t tid;
	tid = (pthread_t)threadid;
	printf("Thread %ld: %s\n", tid+1, messages[tid]);
	pthread_exit(NULL);
}

int main(int argv, char * argc){
	pthread_t tid[NUM_THREAD];
	long taskid;
	int rc, t;
	messages[0] = "English: Hello World!";
	messages[1] = "French: Bonjour, le monde!";
	messages[2] = "Spanish: Hola al mundo";
	messages[3] = "Klingon: Nuq neH!";
	messages[4] = "German: Guten Tag, Welt!"; 
	messages[5] = "Russian: Zdravstvuyte, mir!";
	messages[6] = "Japan: Sekai e konnichiwa!";
	messages[7] = "Latin: Orbis, te saluto!";
	for(t=0; t<NUM_THREAD; t++){
	printf("Creating Thread : %d\n",t+1);
	rc = pthread_create(&tid[t], NULL,printhellow,(void *)t);
	if(rc){
		printf("Error in creating thread : return value of pthread_create is %d", rc);
		exit(-1);
	}
	pthread_join(tid[t], NULL);
	}
	pthread_exit(NULL);
return 0;
}
