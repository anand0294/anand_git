/******************************************************/
/*This program shows how to generate delay in linux OS*/
/*		AUTHOR: ANAND MOHAN TIWARI 	       */
/*******************************************************/

#include<stdio.h>
#include<sys/time.h>
#include<time.h> //for use of function ctime

void differ_time(double differ){

	printf(" The generated delay is : %g seconds \n", differ/1000);
return;
}

int main(void){

	struct timeval tv;
	double current_time, last_triggerTime, differ;
	long triggerTime = 5000;
	gettimeofday(&tv, NULL);
	last_triggerTime = ((tv.tv_sec * 1000)+(tv.tv_usec/1000));
	printf("previous time :%s\n", ctime(&(tv.tv_sec)));
	while(1){
		gettimeofday(&tv, NULL);
		current_time = ((tv.tv_sec*1000) + (tv.tv_usec/1000));
		differ = current_time - last_triggerTime;
		if( differ >=triggerTime ){
			differ_time(differ);
			gettimeofday(&tv, NULL);
			last_triggerTime = ((tv.tv_sec*1000) + (tv.tv_usec/1000));
			differ = 0;
		}

	}
	printf("current time :%s\n", ctime(&(tv.tv_sec)));
	printf("Timer Ended\n");

return 0;
}
