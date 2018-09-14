/* This is the test program which invokes the static character driver
 * and write data from user space to kernel space and read the same
 * sent data.
 *AUTHOR: ANAND  MOHAN TIWARI
*/

#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>

int main(){
	int fd;
	ssize_t retbyte;
	char buf[100];
	char buff[100] = "Hi Anand you successfully test the character driver program implemention. 'Congrats'";
	fd = open("/dev/static_charDev", O_RDWR);
	if(fd<0){
		printf("Failed to open\n");
	}
	/*Writing the content of buff into the device*/
	write(fd, buff, 100);
	/*Reading the content from the device*/
	printf("Reading the content from the device\n");
	retbyte = read(fd, buf, 3000);
	if(retbyte<0){
		printf("Failed to read\n");
	}
	printf("You have read %s \n",buff);
	close(fd);
return 0;
}
