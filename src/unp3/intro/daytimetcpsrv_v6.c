#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#ifndef MAXLINE
#define MAXLINE 255
#endif

// $ lsb_release -a
// No LSB modules are available.
// Distributor ID: Ubuntu
// Description:    Ubuntu 18.04.1 LTS
// Release:    18.04
// Codename:   bionic

int main(int argc, const char *argv[])
{

	int listenfd;
	int connfd;
	int backlog = 5;

	struct sockaddr_in6 servaddr;
	time_t ticks;
	char buff[MAXLINE];
	ssize_t nwrite;

	if (argc != 2) {
		printf("[*] Usage: %s <port>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
#ifdef DEBUG
	printf("socket()\n");
#endif

	listenfd = socket(AF_INET6, SOCK_STREAM, 0);
	if (listenfd == -1) {
		perror("socket()");
		exit(EXIT_FAILURE);
	}

	servaddr.sin6_family = AF_INET6;
	servaddr.sin6_addr = in6addr_any;
	servaddr.sin6_port = htons(atoi(argv[1]));

#ifdef DEBUG
	printf("bind()\n");
#endif

	if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) ==
	    -1) {
		perror("bind()");
		exit(EXIT_FAILURE);
	}
#ifdef DEBUG
	printf("listen()\n");
#endif

	if (listen(listenfd, backlog) == -1) {
		perror("listen");
		exit(EXIT_FAILURE);
	}

	printf("[*] listening on :::%s\n", argv[1]);

	for (;;) {

#ifdef DEBUG
		printf("accept()\n");
#endif

		connfd = accept(listenfd, NULL, NULL);
		if (connfd == -1) {
			perror("accept");
			exit(EXIT_FAILURE);
		}

		ticks = time(NULL);
		snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
		if ((nwrite = write(connfd, buff, strlen(buff))) == -1) {
			perror("write()");
			exit(EXIT_FAILURE);
		}

		close(connfd);
	}

	exit(EXIT_SUCCESS);
}
