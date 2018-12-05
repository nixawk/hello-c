#include "unix_domain.h"

int main(int argc, const char *argv[])
{
	struct sockaddr_un saddr, caddr;	/* socket sockaddr */
	int sfd;
	char buf[BUF_SIZE];
	ssize_t nrecv;
	socklen_t structlen;

	sfd = socket(AF_UNIX, SOCK_DGRAM, 0);
	if (sfd == -1) {
		perror("socket");
		exit(EXIT_FAILURE);
	}

	if (remove(UNIX_SOCK_FILE) == -1 && errno != ENOENT) {
		perror("remove");
		exit(EXIT_FAILURE);
	}

	memset(&saddr, 0, sizeof(struct sockaddr_un));
	saddr.sun_family = AF_UNIX;
	strncpy(saddr.sun_path, UNIX_SOCK_FILE, sizeof(saddr.sun_path) - 1);

	if (bind(sfd, (struct sockaddr *)&saddr, sizeof(struct sockaddr_un)) ==
	    -1) {
		perror("bind");
		exit(EXIT_FAILURE);
	}

	for (;;) {
		structlen = sizeof(struct sockaddr_un);
		nrecv =
		    recvfrom(sfd, buf, BUF_SIZE, 0, (struct sockaddr *)&caddr,
			     &structlen);
		if (nrecv == -1) {
			perror("recvfrom");
			exit(EXIT_FAILURE);
		}

		printf("Server received %ld bytes from %s\n", (long)nrecv,
		       caddr.sun_path);

		if (sendto
		    (sfd, buf, nrecv, 0, (struct sockaddr *)&caddr,
		     structlen) != nrecv) {
			perror("sendto");
			exit(EXIT_FAILURE);
		}
	}

	if (close(sfd) == -1) {
		perror("close");
		exit(EXIT_FAILURE);
	}

	return 0;
}
