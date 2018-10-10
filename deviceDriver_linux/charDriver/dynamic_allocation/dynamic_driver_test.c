/*
 * AUTHOR : ANAND MOHAN TIWARI
 * This program is written to communicate with the device file
 * /dev/dynamic_device and write data into it and read data from driver
 */

#include<stdio.h>
#include<string.h>
/*For open Call include all these three libraries*/
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
/*For Close and write Api*/
#include<unistd.h>
/*For exit call*/
#include<stdlib.h>

char write_buf[1500];
char read_buf[1500]/*, * x*/;

int main(){

int fd;
char option;

	printf("##################################################\n");
	printf("########## Welcome Anand MOhan Tiwari ############\n");
	fd = open("/dev/dynamic_device",O_RDWR);
	if(fd<0){
		printf("Failed to open device file /dev/dynamic_device\n");
		return 0;
	}

	while(1){
		printf("Please Enter the option\n");
		printf("1. Write\n");
		printf("2. Read\n");
		printf("3. Exit\n");
		scanf("%c", &option);
		switch(option){
			case '1': printf("Enter the string to write into driver :");
                                scanf("  %[^\t\n]s", write_buf);
                                printf("Data Writing ...");
                                write(fd, write_buf, strlen(write_buf)+1);
                                printf("Done!\n");
                                break;

			 case '2':
                                printf("Data Reading ...");
                                read(fd, read_buf, 1000);
                                printf("Done!\n\n");
                                printf("Data = %s Fd Value = %d\n\n", read_buf, fd);
                                break;
                        case '3':
                                close(fd);
                                exit(1);
                                break;
                        default:
                                break;


		}

	}
close(fd);
return 0;
}
