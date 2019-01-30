#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <netinet/in.h>

#include <string.h>

int main( int argc, char *argv[] ) {
   int sockfd, newsockfd, portno, clilen;
   char buffer[256], buf[10];
   struct sockaddr_in serv_addr, cli_addr;
   int  n;
//mohan declaration starts
	unsigned int crc, len, tmp;
//mohan declaration ends   
   /* First call to socket() function */
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   
   if (sockfd < 0) {
      perror("ERROR opening socket");
      exit(1);
   }
   
   /* Initialize socket structure */
   bzero((char *) &serv_addr, sizeof(serv_addr));
   portno = 5001;
   
   serv_addr.sin_family = AF_INET;
   serv_addr.sin_addr.s_addr = INADDR_ANY;
   serv_addr.sin_port = htons(portno);
   
   /* Now bind the host address using bind() call.*/
   if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
      perror("ERROR on binding");
      exit(1);
   }
      
   /* Now start listening for the clients, here process will
      * go in sleep mode and will wait for the incoming connection
   */
   
   listen(sockfd,5);
   clilen = sizeof(cli_addr);
while(1){   
   	/* Accept actual connection from the client */
   	newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
	
	 if (newsockfd < 0) {
      		perror("ERROR on accept");
      		exit(1);
   		}
   
   	/* If connection is established then start communicating */
   	bzero(buffer,256);

//mohan starts
   	bzero(buf,10);
	n= read(newsockfd, buf, 10);
	if(n < 0 ){
		perror("Error reading from socket\n");
		exit(1);
	}
	if(strcmp(buf, "#update") == 0 ){
		n = write(newsockfd, "Send Crc", 8);
		if(n < 0 ){
				perror("ERROR in writing to socket");
				exit(1);
		}
#if 0
//	char s[] = "45";
//	int num = atoi(s); //convert string into number;
#endif
		n = read(newsockfd, buf, 10 );
		if( n < 0){
			perror("ERROR reading from socket");
			exit(1);
		}
		crc = atoi(buf);
		bzero(buf, 10);
		write(newsockfd, "Send Length of file", 19);
		read(newsockfd, buf, 10);
		len = atoi(buf); 
		char file_buff[len];
		write(newsockfd, "Send File", 9);
		n = read(newsockfd, file_buff , len+1 );
	}
//mohan end
   		n = read( newsockfd,buffer,255 ); 
  	 	if (n < 0) {
      			perror("ERROR reading from socket");
      			exit(1);
   		}
   
  	 	printf("Here is the message: %s\n",buffer);
   	/* Write a response to the client */
   		n = write(newsockfd,"I got your message",18);
   
  	 if (n < 0) {
      		perror("ERROR writing to socket");
      		exit(1);
   		}
     }
   return 0;
}
