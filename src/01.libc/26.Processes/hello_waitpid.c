#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

// These functions described in this section are used to wait for a child process to
// terminate or stop, and determine its status.

    // pid_t waitpid (pid_t pid, int *status-ptr, int options)

// The [waitpid] function is used to request status information from a child process
// whose process ID is pid. Normally, the calling process is suspended until the
// child process makes status information available by terminating.

// If [status] information for a child process is available immediately, this function
// returns immediately without waiting. If more than one eligible child process has status
// information available, one of them is chosen randomly, and its status is returned immediately.
// To get the status from the other eligible child processes, you need to call [waitpid] again.

// The [options] argument is a cancellation point in multi-threaded programs. This is a problem
// if the thread allocates some resources (like memory, file descriptors, semaphores or whatever)
// at the time [waitpid] is called. If the thread gets canceled these resources stay allocated
// until the program ends. To avoid this call to [waitpid] should be protected using cancellation
// handlers.

// The return value is normally the process ID of the child process whose status is reported.
// If there are child processes but none of them is waiting to be noticed, [waitpid] will block
// until one is. However, if the [WNOHANG] option was specified, waitpid will return zero instead
// of blocking.

// Some of the more commonly used signals:
     // 1       HUP (hang up)
     // 2       INT (interrupt)
     // 3       QUIT (quit)
     // 6       ABRT (abort)
     // 9       KILL (non-catchable, non-ignorable kill)
     // 14      ALRM (alarm clock)
     // 15      TERM (software termination signal)

// int WIFEXITED (int status)
// This macro returns a nonzero value if the child process terminated normally with exit or _exit.

// int WEXITSTATUS (int status)
// If WIFEXITED is true of status, this macro returns the low-order 8 bits of the exit status value
// from the child process.

// int WIFSIGNALED (int status)
// This macro returns a nonzero value if the child process terminated because it received a signal
// that was not handled.

// int WTERMSIG (int status)
// If WIFSIGNALED is true of status, this macro returns the signal number of the signal that terminated the child process.

// int WCOREDUMP (int status)
// This macro returns a nonzero value if the child process terminated and producted a core dump.

// int WIFSTOPPED (int status)
// This macro returns a nonzero value if the child process id stopped.

// int WSTOPSIG (int status)
// If WIFSTOPPED is true of status, this macro returns the signal number of the signal that caused the child process to stop.

void signal_handler(pid_t pid)
{
	pid_t wpid;
	int status;

	do {
		wpid = waitpid(pid, &status, WUNTRACED | WCONTINUED);
		if (wpid < 0) {
			fprintf(stderr, "fork() failed.\n");
			exit(EXIT_FAILURE);
		} else if (WIFEXITED(status)) {
			printf("exited, status=%d\n", WEXITSTATUS(status));
		} else if (WIFSIGNALED(status)) {
			printf("killed by signal %d\n", WTERMSIG(status));
		} else if (WIFCONTINUED(status)) {
			printf("continued\n");
		} else if (WIFSTOPPED(status)) {
			printf("stopped: %d\n", WSTOPSIG(status));
		}
	} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}

void waitpid_usage(void)
{
	pid_t cpid;

	cpid = fork();
	if (cpid < 0) {
		fprintf(stderr, "fork() failed.\n");
		exit(EXIT_FAILURE);
	} else if (cpid == 0) {	/* child process */
		printf("Child PID is %d\n", getpid());
		pause();
	} else {		/* parent process */

		signal_handler(cpid);
	}
}

int main(void)
{
	waitpid_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Process-Completion.html#Process-Completion
// https://www.gnu.org/software/libc/manual/html_node/Process-Completion-Status.html#Process-Completion-Status
// http://www.tutorialspoint.com/unix_system_calls/waitpid.htm
