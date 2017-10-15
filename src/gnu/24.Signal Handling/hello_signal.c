#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// sighandler_t signal (int signum, sighandler_t action)

// The [signal] function establishes action as the action for the signal [signum].
// The first argument, [signum], identifiers the signal whose behavior you want to
// control, and should be a signal number.

// If you set the action for a signal to [SIG_IGN], or if you set it to [SIG_DFL]
// and the default action is to ignore that signal, then any pending signals of
// that type are discarded (even if they are blocked). Discarding the pending 
// signals means that they will never be delivered, not even if you subsequently 
// specify another action and unblock this kind of signal.

void
signal_callback(int signum)
{
    printf("PID: %d, SIGNUM: %s\n", getpid(), strsignal(signum));
}


void
signal_usage(void)
{
    if (signal(SIGINT, signal_callback) == SIG_ERR)
    {
        printf("can't catch SIG_INT\n");
        exit(1);
    }

    for (;;)
    {
        pause();
    }
}


int
main(void)
{
    signal_usage();
    return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Signal-Handling.html
// https://www.gnu.org/software/libc/manual/html_node/Basic-Signal-Handling.html#Basic-Signal-Handling
