#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
	int sockfd;
	int len;
	struct sockaddr_in address;
	int result;
	//char ch = 'A';

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = htons(4000);
	len = sizeof(address);
    
	result = connect(sockfd, (struct sockaddr *)&address, len);
	if (result == -1)
    	{
        	perror("oops: client1");
		exit(1);
	}

	char * read_buf = malloc(1024);
	char * write_buf = malloc(1024);
	memset(read_buf,0,1024);
	memset(write_buf,'A',1024);

	char * ptr = write_buf;
        int nread = 0;
        int nwrite = 0;
        int nleft = 1024;

        while(nleft > 0)
        {
                nwrite = write(sockfd,ptr,1024);

                if (nwrite < 0)
                {
                        printf("error in write().\n");
			break;
                }

                ptr += nwrite;
                nleft -= nwrite;
        }

        ptr = read_buf;

	while((nread = read(sockfd,ptr,1024 - nread)) > 0)
        {
                ptr += nread;
        }

        if (nread == -1)
        {
                printf("error in read().\n");
        }
        else
        {
                printf("server write: %s.\n",read_buf);
        }

	return 0;
}

