#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
	int sockfd;
	int len;
	struct sockaddr_in address;
	int result;

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

	char * send_buf = malloc(BUF_SIZE);
	char * recv_buf = malloc(BUF_SIZE);
	memset(send_buf,0,BUF_SIZE);
	memset(recv_buf,0,BUF_SIZE);

	char * ptr = send_buf;
        int nrecv = 0;
        int nsend = 0;
        int nleft = 0;

        sprintf(send_buf,"How are you?\n");
        printf("send: %s.\n",send_buf);
        //nleft = sizeof(send_buf);
        nleft = 13;
        printf("nleft is %d.\n",nleft);

	printf("ready to send.\n");

        while(nleft > 0)
        {
                nsend = send(sockfd,ptr,1,0);

                if (nsend < 0)
                {
                        printf("error in send().\n");
			break;
                }

                ptr++;
                nleft -= nsend;
        }
        
        printf("nleft is %d.\n",nleft);

        ptr = recv_buf;

	printf("ready to recv.\n");

	while(nrecv = recv(sockfd,ptr,1,0) > 0)
        {
                if (*ptr == '\n')
		{
			ptr++;
			break;
		}

                ptr++;
        }

        if (nrecv < 0)
        {
                printf("error in recv().\n");
        }
        else
        {
                //strcpy(ptr,'\n');
                printf("server send: %s\n",recv_buf);
        }

	return 0;
}

