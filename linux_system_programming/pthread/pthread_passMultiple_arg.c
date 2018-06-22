/******************************************************************************
* FILE: pthread_passMultiple_arg.c
* DESCRIPTION:
*   A "hello world" Pthreads program which demonstrates another safe way
*   to pass arguments to threads during thread creation.  In this case,
*   a structure is used to pass multiple arguments.
* AUTHOR: ANAND MOHAN TIWARI
* LAST REVISED: 22/06/2018
******************************************************************************/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS	8

struct pthread_data{
	int data;
	int sum;
	char * msg;
};

char * messages[NUM_THREADS];

struct pthread_data data_array[NUM_THREADS];

void * helloworld(void * threadarg){

	long data1;
	int  sum1;
	char * msg1;

	struct pthread_data * hi;
	hi = (struct pthread_data *)threadarg;

	data1 = hi->data;
	sum1 =  hi->sum;
	msg1 = hi->msg;
	printf("thread id = %ld, data = %d, message = %s \n", data1, sum1, msg1);
	pthread_exit(NULL);
}

int main(){
	pthread_t threadid[NUM_THREADS];
	int sum2, rc, t;
	sum2 = 0;
	messages[0] = "English: Hello World!";
	messages[1] = "French: Bonjour, le monde!";
	messages[2] = "Spanish: Hola al mundo";
	messages[3] = "Klingon: Nuq neH!";
	messages[4] = "German: Guten Tag, Welt!"; 
	messages[5] = "Russian: Zdravstvytye, mir!";
	messages[6] = "Japan: Sekai e konnichiwa!";
	messages[7] = "Latin: Orbis, te saluto!";
	for(t=0; t<NUM_THREADS; t++){
		sum2 += t;
		data_array[t].data = t+1;
		data_array[t].sum = sum2;
		data_array[t].msg = messages[t]; 
		rc=pthread_create(&threadid[t], NULL, helloworld, (void *)&data_array[t]);
		if(rc<0){
			perror("Thread creation failed : \n");
			exit(EXIT_FAILURE);
		}
		pthread_join(threadid[t], NULL);
	}
	pthread_exit(NULL);
return 0;
}
