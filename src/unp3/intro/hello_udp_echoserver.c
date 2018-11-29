#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFSIZE 1024

void udp_echoserver(int port)
{
	int sockfd;
	struct sockaddr_in servaddr;
	struct sockaddr_in cliaddr;
	char buf[BUFSIZE];
	ssize_t nr;
	ssize_t ns;

	sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (sockfd == -1) {
		perror("socket()");
		exit(EXIT_FAILURE);
	}

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(port);

	if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
		perror("bind()");
		exit(EXIT_FAILURE);
	}

	printf("[*] udp_echoserver port: %d...\n", port);

	for (socklen_t addrlen = sizeof(cliaddr);;) {
		memset(buf, 0, BUFSIZE);
		nr = recvfrom(sockfd, buf, sizeof(buf), 0,
			      (struct sockaddr *)&cliaddr, &addrlen);
		if (nr == -1) {
			perror("recvfrom()");
			exit(EXIT_FAILURE);
		}

		printf("[<=] nr = %ld, buf = [%s]\n", nr, buf);

		ns = sendto(sockfd, buf, nr, 0, (struct sockaddr *)&cliaddr,
			    addrlen);
		if (ns == -1) {
			perror("sendto()");
			exit(EXIT_FAILURE);
		}

		printf("[=>] ns = %ld, buf = [%s]\n", ns, buf);
	}

	if (close(sockfd) == -1) {
		perror("close()");
		exit(EXIT_FAILURE);
	}
}

int main(int argc, const char *argv[])
{
	if (argc != 2) {
		printf("[*] Usage: %s <port>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	udp_echoserver(atoi(argv[1]));
	exit(EXIT_SUCCESS);
}
