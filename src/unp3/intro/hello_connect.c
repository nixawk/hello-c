#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// $ ./a.out xxx.xxx.xxx.xxx port

#define MAXLINE 255

void print_host_port(struct sockaddr_in sin)
{
	char ipbuff[MAXLINE] = { 0 };

	inet_ntop(AF_INET, &sin.sin_addr, ipbuff, sizeof(ipbuff));

	printf("%s:%d\n", ipbuff, ntohs(sin.sin_port)
	    );
}

int main(int argc, const char *argv[])
{
	int sockfd;
	struct sockaddr_in servaddr_in;
	struct sockaddr_in sockname_in;	// getsockname
	struct sockaddr_in peername_in;	// getpeername
	int l = sizeof(sockname_in);

	if (argc != 3) {
		printf("[*] Usage: %s <host> <port>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sockfd == -1) {
		perror("socket");
		exit(EXIT_FAILURE);
	}

	servaddr_in.sin_family = AF_INET;
	servaddr_in.sin_port = htons(atoi(argv[2]));

	if (inet_pton(AF_INET, argv[1], &servaddr_in.sin_addr) <= 0) {
		perror("inet_pton");
		exit(EXIT_FAILURE);
	}
	// The client does not have to call bind before calling connect:
	// the kernel will choose both an ephemeral port and the source IP
	// address if necessary.
	if (connect
	    (sockfd, (struct sockaddr *)&servaddr_in,
	     sizeof(servaddr_in)) == -1) {
		perror("connect");
		exit(EXIT_FAILURE);
	}

	printf("[*] getsockname\n");	// local
	if (getsockname
	    (sockfd, (struct sockaddr *)&sockname_in,
	     (socklen_t *) & l) == -1) {
		perror("getsockname()");
		exit(EXIT_FAILURE);
	}
	print_host_port(sockname_in);

	printf("[*] getpeername\n");	// remote
	if (getpeername
	    (sockfd, (struct sockaddr *)&peername_in,
	     (socklen_t *) & l) == -1) {
		perror("getpeername()");
		exit(EXIT_FAILURE);
	}
	print_host_port(peername_in);

	exit(EXIT_SUCCESS);
}
