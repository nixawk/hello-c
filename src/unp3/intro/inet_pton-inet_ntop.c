#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

// int inet_pton(int af, const char *src, void *dst);
// const char *inet_ntop(int af, const void *src, char *dst, socklen_t size);

#ifndef MAXLINE
#define MAXLINE 255
#endif

int main(int argc, const char *argv[])
{
	struct sockaddr_in addr;
	char buff[MAXLINE];

	if (argc != 3) {
		printf("[*] Usage: %s <host> <port>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	addr.sin_family = AF_INET;
	addr.sin_port = htons(atoi(argv[2]));

	if (inet_pton(AF_INET, argv[1], &addr) < 1) {
		perror("inet_pton");
		exit(EXIT_FAILURE);
	}
	printf("[*] ip -> inet_pton -> sockaddr_in\n");
	printf("%s:%d\n", argv[1], atoi(argv[2]));

	if (inet_ntop(AF_INET, &addr, buff, sizeof(buff)) == NULL) {
		perror("inet_ntop");
		exit(EXIT_FAILURE);
	}
	printf("[*] sockaddr_in -> inet_pton -> ip\n");
	printf("%s\n", buff);

	exit(EXIT_SUCCESS);
}
