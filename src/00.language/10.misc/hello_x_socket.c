#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#ifndef CHUNK_SIZE
#define CHUNK_SIZE 256
#endif

int connect_to(char *, int);
ssize_t send_all(int, char *);
ssize_t recv_all(int, int);

int connect_to(host, port)
char *host;
short int port;
{
	int socket_fd;
	int s;
	struct sockaddr_in addr;	// struct sockaddr address;

	socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_fd == -1)
		exit(EXIT_FAILURE);

	addr.sin_addr.s_addr = inet_addr(host);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);

	// s = inet_pton(AF_INET, host, &addr.sin_addr);
	// if (s <= 0)
	//     exit(EXIT_FAILURE);

	s = connect(socket_fd, (struct sockaddr *)&addr,
		    sizeof(struct sockaddr));
	if (s == -1)
		exit(EXIT_FAILURE);

	return socket_fd;
}

ssize_t send_all(socket_fd, data)
int socket_fd;
char *data;
{
	ssize_t ns;
	int i, l;

	// struct timeval timeout;
	// timeout.tv_sec = 10;
	// timeout.tv_usec = 0;

	// set send timeout
	// if (setsockopt (socket_fd, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout,
	//             sizeof(timeout)) < 0)
	//     perror("setsockopt failed\n");

	// strlen(data) < CHUNK_SIZE
	// strlen(data) = CHUNK_SIZE
	// strlen(data) > CHUNK_SIZE

	for (i = 0, ns = 0, l = strlen(data); i < l; i += CHUNK_SIZE) {
		ns += send(socket_fd,
			   data + i,
			   (l - i > CHUNK_SIZE) ? CHUNK_SIZE : (l - i), 0);
	}

	return ns;
}

ssize_t recv_all(socket_fd, timeout_sec)
int socket_fd;
int timeout_sec;		// seconds
{
	char chunk[CHUNK_SIZE] = { 0 };
	ssize_t i, nr;
	struct timeval timeout;

	// set recv timeout
	timeout.tv_sec = timeout_sec;
	timeout.tv_usec = 0;
	if (setsockopt(socket_fd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout,
		       sizeof(timeout)) < 0)
		perror("setsockopt failed\n");

	for (i = CHUNK_SIZE, nr = 0; i == CHUNK_SIZE;) {
		i = recv(socket_fd, chunk, i, 0);
		nr += i;

		// do with socket buffer
		printf("[recv] %ld - %s\n", i, chunk);
	}

	return nr;
}

int main(int argc, const char *argv[])
{
	int socket_fd;
	ssize_t ns, nr;

	socket_fd = connect_to("127.0.0.1", 4444);

	ns = send_all(socket_fd, "This is a demo string.\n");
	nr = recv_all(socket_fd, 5);
	close(socket_fd);

	printf("[*] send = %ld, recv = %ld\n", ns, nr);

	return 0;
}

/*

typedef unsigned short __kernel_sa_family_t;
typedef __kernel_sa_family_t    sa_family_t;

struct sockaddr {
    sa_family_t sa_family;      // address family, AF_xxx
    char        sa_data[14];    // 14 bytes of protocol address
};

struct sockaddr_in {
  __kernel_sa_family_t  sin_family;     // Address family
  __be16                sin_port;       // Port number
  struct in_addr        sin_addr;       // Internet address

  // Pad to size of `struct sockaddr'
  unsigned char     __pad[__SOCK_SIZE__ - sizeof(short int) -
            sizeof(unsigned short int) - sizeof(struct in_addr)];
};

*/

// https://elixir.bootlin.com/linux/latest/source/include/uapi/linux/in.h#L232
// https://stackoverflow.com/questions/18609397/whats-the-difference-between-sockaddr-sockaddr-in-and-sockaddr-in6
// https://stackoverflow.com/questions/21099041/why-do-we-cast-sockaddr-in-to-sockaddr-when-calling-bind
// https://stackoverflow.com/questions/13479760/c-socket-recv-and-send-all-data
// https://www.binarytides.com/receive-full-data-with-recv-socket-function-in-c/
// https://stackoverflow.com/questions/4181784/how-to-set-socket-timeout-in-c-when-making-multiple-connections
