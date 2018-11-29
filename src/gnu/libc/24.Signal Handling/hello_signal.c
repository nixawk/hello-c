#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// typedef void (*sighandler_t)(int);
// sighandler_t signal(int signum, sighandler_t handler);

static int c;			/* ctrl-c count */

void handler(int sig)
{
	printf("\tCtrl + C catched\n");
	c++;
	if (c > 3) {
		printf("exit the program\n");
		exit(EXIT_SUCCESS);
	}
}

int main(void)
{
	if (signal(SIGINT, handler) == SIG_ERR) {
		perror("signal");
		exit(EXIT_FAILURE);
	}

	for (;;) {
		printf("waiting for singal...\n");
		sleep(1);
	}

	exit(EXIT_SUCCESS);
}

// http://man7.org/linux/man-pages/man7/signal.7.html
// https://www.gnu.org/software/libc/manual/html_node/Signal-Handling.html
// https://www.gnu.org/software/libc/manual/html_node/Basic-Signal-Handling.html#Basic-Signal-Handling
