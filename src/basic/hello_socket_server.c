#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define PORT 4444
#define SIZE 1024

void socket_server(void)
{
	int server_fd, new_socket, valread;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer[SIZE] = { 0 };
	char hello[] = "hello from server";

	// Creating socket file descriptor
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
		perror("socket failed");
		exit(EXIT_FAILURE);
	}
	// Forcefully attaching socket to the port 8080
	if (setsockopt
	    (server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt,
	     sizeof(opt))) {
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	// Forcefully attaching socket to the port 8080
	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
		perror("bind failed");
		exit(EXIT_FAILURE);
	}

	if (listen(server_fd, 3) < 0) {
		perror("listen");
		exit(EXIT_FAILURE);
	}

	printf("Listening on [0.0.0.0] (family 0, port %d)\n", PORT);

	if ((new_socket =
	     accept(server_fd, (struct sockaddr *)&address,
		    (socklen_t *) & addrlen)) < 0) {
		perror("accept");
		exit(EXIT_FAILURE);
	}

	valread = read(new_socket, buffer, sizeof(buffer));
	printf("%s\n", buffer);
	send(new_socket, hello, strlen(hello), 0);
	printf("Hello message sent\n");

	close(new_socket);
	close(server_fd);
}

int main(int argc, const char *argv[])
{
	socket_server();
	return 0;
}

// http://www.geeksforgeeks.org/socket-programming-cc/
