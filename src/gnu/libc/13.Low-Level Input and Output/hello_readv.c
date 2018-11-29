#include <sys/uio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 128
#define IOVCNT 3

void readv_usage(void)
{
	int fd;
	ssize_t nread, total_requires;
	struct iovec iov[IOVCNT];	/* iovcnt = 3 */

	struct stat buf1;	/* First buffer */
	int buf2;		/* Second buffer */
	char buf3[SIZE];	/* Third buffer */

	fd = open("/etc/passwd", O_RDONLY, S_IRUSR);
	if (fd == -1) {
		perror("open");
		exit(EXIT_FAILURE);
	}

	total_requires = 0;

	iov[0].iov_base = &buf1;
	iov[0].iov_len = sizeof(struct stat);

	iov[1].iov_base = &buf2;
	iov[1].iov_len = sizeof(int);

	iov[2].iov_base = buf3;
	iov[2].iov_len = SIZE;

	total_requires += sizeof(struct stat);
	total_requires += sizeof(int);
	total_requires += SIZE;

	nread = readv(fd, iov, IOVCNT);
	if (nread == (ssize_t) - 1) {
		perror("readv");
		exit(EXIT_FAILURE);
	}

	if (nread < total_requires) {
		printf("Read fewer bytes than requested\n");
	}

	printf("total bytes requested: %ld; bytes read: %ld\n",
	       (long)total_requires, (long)nread);
	exit(EXIT_SUCCESS);
}

int main(void)
{
	readv_usage();
	return 0;
}

// http://man.he.net/?topic=readv&section=all
