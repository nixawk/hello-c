#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define HOST "127.0.0.1"
#define PORT 4444
#define SIZE 1024

void socket_client(void)
{
	struct sockaddr_in address, serv_addr;
	int client_fd = 0, valread;
	char hello[] = "hello from client";
	char buffer[SIZE] = { 0 };

	if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket failed");
		exit(EXIT_FAILURE);
	}

	memset(&serv_addr, 0, sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	// Convert IPv4 and IPv6 addresses from text to binary from
	if (inet_pton(AF_INET, HOST, &serv_addr.sin_addr) <= 0) {
		perror("inet_pton failed");
		exit(EXIT_FAILURE);
	}

	if (connect
	    (client_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))) {
		perror("connect failed");
		exit(EXIT_FAILURE);
	}

	printf("Connection to %s %d port [tcp/*] succeeded!\n", HOST, PORT);
	send(client_fd, hello, strlen(hello), 0);
	printf("Hello message sent\n");
	valread = read(client_fd, buffer, 1024);
	printf("%s\n", buffer);

	close(client_fd);
}

int main(int argc, const char *argv[])
{
	socket_client();
	return 0;
}

// http://www.geeksforgeeks.org/socket-programming-cc/
