#include "unix_domain.h"

int main(int argc, const char *argv[])
{
	struct sockaddr_un addr;	/* unix sockaddr_un */
	int sfd;		/* server file descriptor */
	ssize_t nread;		/* count of read */
	char buf[BUF_SIZE];	/* buffer */

	sfd = socket(AF_UNIX, SOCK_STREAM, 0);
	if (sfd == -1) {
		perror("socket");
		exit(EXIT_FAILURE);
	}

	/* Construct server address, and make the connection */

	memset(&addr, 0, sizeof(struct sockaddr_un));
	addr.sun_family = AF_UNIX;
	strncpy(addr.sun_path, UNIX_SOCK_FILE, sizeof(addr.sun_path) - 1);

	if (connect(sfd, (struct sockaddr *)&addr, sizeof(struct sockaddr_un))
	    == -1) {
		perror("connect");
		exit(EXIT_FAILURE);
	}

	/* Copy stdin to socket */

	while ((nread = read(STDIN_FILENO, buf, BUF_SIZE)) > 0) {
		if (write(sfd, buf, nread) != nread) {
			perror("write");
			exit(EXIT_FAILURE);
		}
	}

	if (nread == -1) {
		perror("read");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
