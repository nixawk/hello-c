#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Execute the command using this shell program.  */

#define SHELL "/bin/sh"

/* similar to system in stdlib.h */

int my_system(const char *command)
{
	int status;
	pid_t pid;

	if (command == NULL)
		return 1;

	switch (pid = fork()) {
	case -1:
		return -1;

	case 0:		/* child process */
		execl(SHELL, SHELL, "-c", command, (char *)NULL);
		_exit(127);	/* Failed exec */

	default:		/* parent process */
		if (waitpid(pid, &status, 0) == -1)
			return -1;
		else
			return status;
	}
}

int main(int argc, char *argv[])
{
	int i;

	if (argc < 2) {
		printf("[*] %s <command> <command> ...\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	for (i = 1; i < argc; i++) {
		printf("$ %s\n", argv[i]);
		my_system(argv[i]);
	}

	exit(EXIT_SUCCESS);
}

// https://www.gnu.org/software/libc/manual/html_node/Process-Creation-Example.html#Process-Creation-Example
// http://pubs.opengroup.org/onlinepubs/009695399/functions/system.html
