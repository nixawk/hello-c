#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int pause (void)

// The [pause] function suspends program execution until a sihnal arrives
// whose action is either to execute a handler function, or to terminate
// the process.

// If the [signal] causes a handler function to be executed, then [pause]
// returns. This is consiered an unsucessful return (since "successful"
// behavior would be to suspend the program forever), so the return value
// is -1. Even if you specify that other primitives should resume when a
// system handler returns, this has no effect on [pause]; it always fails
// when a signal is handled.

void signal_callback(int signum)
{
	printf("%s\n", strsignal(signum));
}

unsigned int mysleep(unsigned int seconds)
{
	printf("sleeping... %d seconds\n", seconds);
	if (signal(SIGALRM, signal_callback) == SIG_ERR) {
		return seconds;
	}

	alarm(seconds);		/* start the timer */
	pause();		/* next caught signal wakes us up */
	return (alarm(0));	/* turn off timer, return unslept time */
}

int main(void)
{
	mysleep(3);
	return 0;
}

// https://www.gnu.org/s/libc/manual/html_node/Using-Pause.html
