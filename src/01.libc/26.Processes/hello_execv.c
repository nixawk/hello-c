#include <unistd.h>
#include <stdio.h>

    // int execv (const char *filename, char *const argv[])

// The [execv] function executes the file named by [filename] as a new process image.

// The [argv] argument is an array of null-terminated strings that is used to provide a value
// for the [argv] argument to the [main] function of the program to be executed.
// The last element of this array must be a null pointer.
// The first element of this array is the file name of the program sans directory names.

// The function normally don't return, since execution of a new program causes
// the currently executing program to go away completely. A value of -1 is
// returned in the event of a failure.

    // int execl (const char *filename, const char *arg0, …)

// This is similar to [execv], but the [argv] strings are specified individually instead of
// as an array. A null pointer must be passed as the last such argument.

    // int execve (const char *filename, char *const argv[], char *const env[])

// This is similar to [execv], but permits you to specify the environment for the new program
// explicitly as the [env] argument. This should be an array of strings in the same format as
// for the [environ] variable.

    // int execle (const char *filename, const char *arg0, …, char *const env[])

// This is similar to execl, but permits you to specify the environment for the new program
// explicitly. The environment argument is passed following the null pointer that marks the
// last [argv] argument, and should be an array of strings in the same format as for the
// [environ] variable.

    // int execvp (const char *filename, char *const argv[])

// The [execvp] is similar to execv, except that it searches the directories listed in the [PATH]
// environment variable to find the full file name of a file from filename if filename
// does not contain a slash.

    // int execlp (const char *filename, const char *arg0, …)

// This function is like execl, except that it performs the same file name searching as the execvp function.

// The size of the argument list and environment list taken together must not be greater than
// [ARG_MAX] bytes. Other systems may have somewhat different rules for counting.

// Executing a new process image completely changes the content of memory, copying only the argument
// and environemnt strings to new locations. But many other attributes if the process are unchanged:

    // The process ID and the parent process ID.
    // Session and process group membership.
    // Real user ID and group ID, and supplementary group IDs.
    // Pending alarms.
    // Current working directory and root directory.
    // File mode creation mask.
    // Process signal mark.
    // Pending signals.
    // Elapsed processor time associated with the process.

void execv_usage(void)
{
	pid_t pid = fork();
	char *argv[] = {
		"/bin/",
		NULL
	};

	if (pid == (pid_t) 0) {	/* child process */
		execv("/bin/ls", argv);
	} else if (pid > (pid_t) 0) {
		printf("parent process ID: %d\n", pid);
	} else {
		fprintf(stderr, "fork() failed.\n");
	}
}

int main(void)
{
	execv_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Executing-a-File.html#Executing-a-File
