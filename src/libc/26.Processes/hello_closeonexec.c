#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int flags;

	if (argc > 1) {
		flags = fcntl(STDOUT_FILENO, F_GETFD);
		if (flags == -1) {
			perror("fcntl - F_GETFD");
			exit(EXIT_FAILURE);
		}

		flags |= FD_CLOEXEC;	/* Turn on FD_CLOEXEC, not CLOSEXEC */
		if (fcntl(STDOUT_FILENO, F_SETFD, flags) == -1) {
			perror("fcntl - F_SETFD");
			exit(EXIT_FAILURE);
		}

	}

	execlp("ls", "ls", "-l", argv[0], (char *)NULL);
	exit(EXIT_SUCCESS);
}

/*

$ ./a.out 
-rwxr-xr-x 1 root root 7528 Jan  3 23:18 ./a.out

$ ./a.out 1
ls: write error: Bad file descriptor

*/

// http://man7.org/linux/man-pages/man3/exec.3.html
