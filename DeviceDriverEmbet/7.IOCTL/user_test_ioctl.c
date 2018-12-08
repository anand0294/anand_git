/*
 * This program is used to test ioctl call implemented in driver
 * AUTHOR: ANAND MOHAN TIWARI
 */

#include <stdio.h>
#include <sys/types.h>/*All below header files for open API*/
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>/*For Ioctl call*/
#include <unistd.h> //for read, close, write call
#include <stdlib.h>

#define AMT_READ _IOR('a', 'a', int32_t *)
#define AMT_WRITE _IOW('a', 'b', int32_t *)

int main( void ){
	int32_t number, value;
	int fd;
	printf("/****************************************************************************************/\n");
	printf("/**********************MOHAN IOCTL IMPLEMENTATION CALL***********************************/\n");
	printf("/******** https://github.com/anand0294/anand_git/tree/master/DeviceDriverEmbet **********/\n");
	printf("/****************************************************************************************/\n");

	printf("\nOpening Driver\n");
	fd = ("/dev/MOHAN_CHAR_DRIVER", O_RDWR );
	if( fd < 0 ){
		printf("Failed to open character Driver\n");
		exit(-1);
	}
	printf("Enter the value to Send in Driver\n");
	scanf( "%d", &number );
	printf("Writing value to Driver\n");
	ioctl(fd, AMT_WRITE, (int32_t *)&number );

	printf("Reading value from Driver\n");
	ioctl(fd, AMT_READ, (int32_t *)&value );
	printf("You have read : %d from driver\n", value );

	printf("Closing Driver\n");
	close(fd);

return 0;
}
