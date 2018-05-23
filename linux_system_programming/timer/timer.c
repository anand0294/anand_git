#include<stdio.h>
//#include<stdlib.h>
#include<sys/time.h>

void differ_time(long differ){

	printf(" The generated delay is : %ld seconds \n", differ/1000);

}

int main(void){

	struct timeval tv;
	double current_time, last_triggerTime, differ;
	long triggerTime = 5000;
	gettimeofday(&tv, NULL);
	last_triggerTime = ((tv.tv_sec * 1000)+(tv.tv_usec/1000));
	printf("Previously Triggered time is : %ld\n", last_triggerTime);
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
	printf("Current time : %ld\n", current_time);
	printf("Timer Ended\n");

return 0;
}
