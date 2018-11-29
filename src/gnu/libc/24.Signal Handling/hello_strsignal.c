#include <signal.h>
#include <string.h>
#include <stdio.h>

// char * strsignal (int signum)

// This function returns a pointer to a statically-allocated string containing
// a message describing the signal [signum]. You should not modify the contents
// of this string; and, since it can be rewritten on subsequent calls, you should
// save a copy of it if you need to reference it later.

// void psignal (int signum, const char *message)

// This function prints a message describing the signal signum to the standard error
// output stream stderr.

// If you call [psignal] with a [message] that is either a null pointer or an empty
// string, [psingal] just prints the message corresponding to [signum], adding a
// trailing newline.

// If you supply a non-null message argument, then psignal prefixes its output with this string.
// It adds a colon and a space character to separate the message from the string corresponding to signum.

//    SIGFPE - Floating point exception: 8
//   SIGTERM - Terminated: 15
//    SIGINT - Interrupt: 2
//   SIGQUIT - Quit: 3
//   SIGKILL - Killed: 9
//    SIGHUP - Hangup: 1
//   SIGALRM - Alarm clock: 14
// SIGVTALRM - Virtual timer expired: 26
//   SIGPROF - Profiling timer expired: 27
//     SIGIO - I/O possible: 23
//    SIGURG - Urgent I/O condition: 16
//   SIGCHLD - Child exited: 20
//   SIGCONT - Continued: 19
//   SIGSTOP - Suspended (signal): 17
//   SIGTSTP - Suspended: 18
//   SIGTTIN - Stopped (tty input): 21
//   SIGTTOU - Stopped (tty output): 22
//   SIGPIPE - Broken pipe: 13
//   SIGXCPU - Cputime limit exceeded: 24
//   SIGXFSZ - Filesize limit exceeded: 25
//   SIGUSR1 - User defined signal 1: 30
//   SIGUSR2 - User defined signal 2: 31
//  SIGWINCH - Window size changes: 28
//   SIGINFO - Information request: 29

#define SIGCUSTOM 0xFF

void print_text(char *signal_name, char *signal_value)
{
	printf("%12s - %s\n", signal_name, signal_value);
}

void psignal_usage(void)
{
	psignal(SIGCUSTOM, "This is a custom signal message.");
}

void signal_usage(void)
{
	print_text("SIGFPE", strsignal(SIGFPE));
	print_text("SIGTERM", strsignal(SIGTERM));
	print_text("SIGINT", strsignal(SIGINT));
	print_text("SIGQUIT", strsignal(SIGQUIT));
	print_text("SIGKILL", strsignal(SIGKILL));
	print_text("SIGHUP", strsignal(SIGHUP));
	print_text("SIGALRM", strsignal(SIGALRM));
	print_text("SIGVTALRM", strsignal(SIGVTALRM));
	print_text("SIGPROF", strsignal(SIGPROF));
	print_text("SIGIO", strsignal(SIGIO));
	print_text("SIGURG", strsignal(SIGURG));
	// print_text("SIGPOLL", strsignal(SIGPOLL));
	print_text("SIGCHLD", strsignal(SIGCHLD));
	// print_text("SIGCLD", strsignal(SIGCLD));
	print_text("SIGCONT", strsignal(SIGCONT));
	print_text("SIGSTOP", strsignal(SIGSTOP));
	print_text("SIGTSTP", strsignal(SIGTSTP));
	print_text("SIGTTIN", strsignal(SIGTTIN));
	print_text("SIGTTOU", strsignal(SIGTTOU));
	print_text("SIGPIPE", strsignal(SIGPIPE));
	// print_text("SIGLOST", strsignal(SIGLOST));
	print_text("SIGXCPU", strsignal(SIGXCPU));
	print_text("SIGXFSZ", strsignal(SIGXFSZ));
	print_text("SIGUSR1", strsignal(SIGUSR1));
	print_text("SIGUSR2", strsignal(SIGUSR2));
	print_text("SIGWINCH", strsignal(SIGWINCH));
	print_text("SIGINFO", strsignal(SIGINFO));
}

int main(void)
{
	signal_usage();
	psignal_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Standard-Signals.html#Standard-Signals
// https://www.gnu.org/software/libc/manual/html_node/Signal-Messages.html#Signal-Messages
