#define _GNU_SOURCE
#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void make_zombie(void)
{
	char cmd[_POSIX2_LINE_MAX];
	pid_t childpid;

	setbuf(stdout, NULL);	/* Turn buffering off */

	printf("Parent PID=%d\n", getpid());

	switch (childpid = fork()) {
	case -1:
		perror("fork");
		exit(EXIT_FAILURE);

	case 0:		/* Child: immediately exits to become zombie */
		printf("Child PID=%d\n", getpid());
		_exit(EXIT_SUCCESS);

	default:
		sleep(3);	/* Give child a chance to start and exit */
		snprintf(cmd, _POSIX2_LINE_MAX, "ps | grep %s", program_invocation_short_name	/* defined in errno.h */
		    );
		cmd[_POSIX2_LINE_MAX - 1] = '\0';
		system(cmd);

		/* Now send the kill signal to the zombie */
		if (kill(childpid, SIGKILL) == -1) {
			perror("kill");
		}

		sleep(3);
		printf("After sending SIGKILL to zombie (PID=%d):\n", childpid);
		system(cmd);

		exit(EXIT_SUCCESS);
	}
}

int main(void)
{
	make_zombie();
	return 0;
}

/*

$ ./a.out 
Parent PID=30747
Child PID=30748
30747 pts/0    00:00:00 a.out
30748 pts/0    00:00:00 a.out <defunct>
After sending SIGKILL to zombie (PID=30748):
30747 pts/0    00:00:00 a.out
30748 pts/0    00:00:00 a.out <defunct>

*/

// https://linux.die.net/man/3/program_invocation_short_name
// https://github.com/hyperion-project/hyperion/issues/693
