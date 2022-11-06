#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <pthread.h>
#include <stdint.h>
#include <unistd.h>

int startup(uint16_t *port);
void accept_request(void * arg);

int main()
{
	int listenfd = -1;
	uint16_t port = 4000;
	int clientfd = -1;
	struct sockaddr_in client_addr;
	int len = sizeof(client_addr);
	char ipAddr[INET_ADDRSTRLEN];
	pthread_t new_thread;

	listenfd = startup(&port);
	
	printf("server is running in %d.\n",port);

	while(true)
	{
		clientfd = accept(listenfd,(struct sockaddr *)&client_addr,&len);
		if (clientfd == -1)
		{
			printf("error in accept().\n");
		}
		
		if (inet_ntop(AF_INET,&client_addr.sin_addr,ipAddr,sizeof(ipAddr)) == NULL)
		{
			printf("error in inet_ntop().\n");
		}
		
		printf("client is connecting from %s:%d.\n",ipAddr,ntohs(client_addr.sin_port));

		if (pthread_create(&new_thread,NULL,(void *)accept_request,(void *)(intptr_t)clientfd) != 0)
		{
			printf("error in pthread_create().\n");
		}
		
		pthread_detach(new_thread);
	}

	return 0;
}

int startup(uint16_t * port)
{
	int listenfd = 0;
	int on = 1;

	listenfd = socket(AF_INET,SOCK_STREAM,0);
	if (listenfd == -1)
	{
		printf("error in socket().\n");
	}

	struct sockaddr_in addr;
	int len = sizeof(addr);
	memset(&addr,0,sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(*port);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	if (setsockopt(listenfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on)) == -1)
	{
		printf("error in setsockopt().\n");
	}

	if (bind(listenfd,(struct sockaddr*)&addr,len) == -1)
	{
		printf("error in bind().\n");
	}

	if (*port == 0)
	{
		if (getsockname(listenfd,(struct sockaddr *)&addr,&len) == -1)
		{
			printf("error in getsockname().\n");
		}
		
		*port = ntohs(addr.sin_port);
	}

	if (listen(listenfd,30) == -1)
	{
		printf("error in listen().\n");
	}

	return listenfd;
}

void accept_request(void * arg)
{
	char * read_buf = malloc(1024);
	char * write_buf = malloc(1024);
	memset(read_buf,0,1024);
	memset(write_buf,'B',1024);
	
	char * ptr = read_buf;
	int clientfd = (intptr_t)arg;
	int nread = 0;
	int nwrite = 0;
	int nleft = 1024;

	
	while((nread = read(clientfd,ptr,1024 - nread)) > 0)
	{
		ptr += nread;
	}
	
	printf("H.\n");
	if (nread == -1)
	{
		printf("error in read().\n");
	}
	else
	{
		printf("client write: %s.\n",read_buf);
	}

	ptr = write_buf;

	while(nleft > 0)
	{
		nwrite = write(clientfd,ptr,1024);

		if (nwrite < 0)
		{
			printf("error in write().\n");
			break;
		}

		ptr += nwrite;
		nleft -= nwrite;
	}
	
	close(clientfd);
	
	pthread_exit(NULL);
}
