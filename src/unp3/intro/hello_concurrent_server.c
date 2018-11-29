#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAXLINE 255

int main(int argc, const char *argv[])
{
	int sockfd;
	int connfd;
	struct sockaddr_in servaddr_in;
	struct sockaddr_in cliaddr_in;
	char ipbuff[MAXLINE];
	char message[MAXLINE] = "Hello World\n";

	if (argc != 2) {
		printf("[*] Usage: %s <port>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sockfd == -1) {
		perror("socket()");
		exit(EXIT_FAILURE);
	}

	servaddr_in.sin_family = AF_INET;
	servaddr_in.sin_port = htons(atoi(argv[1]));
	servaddr_in.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(sockfd, (struct sockaddr *)&servaddr_in, sizeof(servaddr_in))
	    == -1) {
		perror("bind()");
		exit(EXIT_FAILURE);
	}

	printf("[*] Bind to 0.0.0.0:%s\n", argv[1]);

	// When a socket is created by the socket function, it is assumed
	// to be an active socket, that is, a client socket that will issue
	// a connect. The listen function converts an unconnected socket into
	// a passive socket, indicating that the kernel should accept incoming
	// connection requests directed to this socket.
	if (listen(sockfd, 10) == -1) {
		perror("listen()");
		exit(EXIT_FAILURE);
	}

	for (int clen = sizeof(cliaddr_in);;) {
		connfd =
		    accept(sockfd, (struct sockaddr *)&cliaddr_in,
			   (socklen_t *) & clen);
		if (connfd == -1) {
			perror("accept()");
			exit(EXIT_FAILURE);
		}

		memset(ipbuff, 0, sizeof(ipbuff));
		if (inet_ntop
		    (AF_INET, &cliaddr_in.sin_addr, ipbuff,
		     sizeof(ipbuff)) != NULL) {
			printf("[*] a new connection from %s:%d\n", ipbuff,
			       ntohs(cliaddr_in.sin_port)
			    );
		}

		switch (fork())	// concurrent server mode
		{
		case -1:
			perror("fork()");
			break;

		case 0:
			close(sockfd);	// close listening socket in child process
			write(connfd, message, strlen(message));
			close(connfd);
			exit(EXIT_SUCCESS);	// close child process
			break;

		default:
			break;
		}

	}

	exit(EXIT_SUCCESS);
}
