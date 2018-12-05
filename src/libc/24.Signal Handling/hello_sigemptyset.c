#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void signal_set(void)
{
	sigset_t sig;
	int sigret;

	/* sig initializes - sigemptyset / sigfillset */

	if (sigemptyset(&sig) == -1) {
		perror("sigemptysig");
		exit(EXIT_FAILURE);
	}

	/* sig add */

	if (sigaddset(&sig, SIGINT) == -1) {
		perror("sigaddset");
		exit(EXIT_FAILURE);
	}

	sigret = sigismember(&sig, SIGINT);
	if (sigret == -1) {
		perror("sigismember");
		exit(EXIT_FAILURE);
	}

	if (sigret == 1)
		printf("SIGINT is not a member of sig\n");
	else
		printf("SIGINT is a member of sig\n");

	/* sig del */

	if (sigdelset(&sig, SIGINT) == -1) {
		perror("sigdelset");
		exit(EXIT_FAILURE);
	}

	sigret = sigismember(&sig, SIGINT);
	if (sigret == -1) {
		perror("sigismember");
		exit(EXIT_FAILURE);
	}

	if (sigret == 1)
		printf("SIGINT is not a member of sig\n");
	else
		printf("SIGINT is a member of sig\n");

}

int main(void)
{
	signal_set();
	return 0;
}

// http://man7.org/linux/man-pages/man3/sigemptyset.3p.html
// http://man7.org/linux/man-pages/man3/sigaddset.3p.html
// http://man7.org/linux/man-pages/man3/sigdelset.3p.html
// http://man7.org/linux/man-pages/man3/sigismember.3p.html
