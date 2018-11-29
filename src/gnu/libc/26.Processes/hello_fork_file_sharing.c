#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>

void fork_file_sharing(void)
{
	pid_t childpid;
	int fd, flags;
	char template[] = "/tmp/testXXXX";

	setbuf(stdout, NULL);	/* Disable buffering of stdout */

	fd = mkstemp(template);
	if (fd == (int)-1) {
		perror("mkstemp");
		exit(EXIT_FAILURE);
	}

	flags = fcntl(fd, F_GETFL);
	if (flags == (int)-1) {
		perror("fcntl");
		exit(EXIT_FAILURE);
	}

	printf("File Offset before fork(): %lld\n",
	       (long long)lseek(fd, 0, SEEK_CUR));
	printf("File O_APPEND flag before fork() is : %s\n",
	       (flags & O_APPEND) ? "on" : "off");

	switch (childpid = fork()) {
	case -1:
		perror("fork");
		exit(EXIT_FAILURE);

	case 0:
		if (lseek(fd, 1000, SEEK_SET) == (int)-1) {
			perror("child process - lseek");
			exit(EXIT_FAILURE);
		}

		flags = fcntl(fd, F_GETFL);
		if (flags == (int)-1) {
			perror("child process - fcntl (F_GETFL)");
			exit(EXIT_FAILURE);
		}

		flags |= O_APPEND;	/* Turn O_APPEND om */
		if (fcntl(fd, F_SETFL, flags) == (int)-1) {
			perror("child process - fcntl (F_SETFL)");
			exit(EXIT_FAILURE);
		}

		printf("child process - turn O_APPEND on\n");
		exit(EXIT_SUCCESS);

	default:
		if (wait(NULL) == (pid_t) - 1) {
			perror("parent process - wait");
			exit(EXIT_FAILURE);
		}

		printf("child process - exited\n");

		flags = fcntl(fd, F_GETFL);
		if (flags == (int)-1) {
			perror("parent process - fcntl");
			exit(EXIT_FAILURE);
		}

		printf("File Offset in parent : %lld\n",
		       (long long)lseek(fd, 0, SEEK_CUR));
		printf("File O_APPEND flag in parent is : %s\n",
		       (flags & O_APPEND) ? "on" : "off");

		exit(EXIT_SUCCESS);
	}
}

int main(void)
{
	fork_file_sharing();
	return 0;
}

/*

$ ./a.out

File Offset before fork(): 0
File O_APPEND flag before fork() is : off
child process - turn O_APPEND on
child process - exited
File Offset in parent : 1000
File O_APPEND flag in parent is : on

*/

// http://man7.org/linux/man-pages/man3/setbuf.3.html
// http://man7.org/linux/man-pages/man2/waitpid.2.html
