
// A pipe is a mechanism for interprocess communication; data written to the
// pipe by one process can be read by another process. The data is handled in
// a first-in, first-out (FIFO) order. The pipe has no name; it is created
// for one use and both ends must be inherited from the single process which
// created the pipe.

// A FIFO  special file is similar to a pipe, but instead of being an
// anonymous, temporary connection, a FIFO has a name or names like any other
// file. Processes open the FIFO by name in order to communicate through it.

// A pipe or FIFO has to be open at both ends simulaneously. If you read from
// a pipe or FIFO file that doesn't have any processes writing to it (perhaps
// because they have all closed the file, or exited), the read returns
// end-of-file. Writing to a pipe or FIFO that doesn't have a reading process
// is treated as an error condition; it generates a SIGPIPE signal, and fails
// with error code EPIPE if the signal is handled or blocked.

// Neither pipes nor FIFO special files allow file positioning. Both reading
// and writing operations happen sequentially; reading from the beginning of
// the file and writing at the end.

// It is not very useful for a single process to use a pipe to talk to itself.
// In typical use, a process creates a pipe just before it forks one or more
// child processes. The pipe is then used for communication either between
// the parent or child processes, or between two sibling processes.

    // int pipe (int filedes[2])

// The pipe function creates a pipe and puts the file descriptors for the
// reading and writing ends of the pipe (respectively) into filedes[0] and
// filedes[1]. An easy way to remember that the input end comes first is
// that file descriptor 0 is standard input, and file descriptor 1 is
// standard output.

// If successful, pipe returns a value of 0. On failure, -1 is returned.
// The following errno error conditions are defined for this function:

    // EMFILE - The process has too many files open.
    // ENFILE - There are too many open files in the entire system.

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/* Read characters from the pipe and echo them to stdout */
void read_from_pipe(int fd)
{
	FILE *stream;
	int c;
	stream = fdopen(fd, "r");
	while ((c = fgetc(stream)) != EOF) {
		putchar(c);
	}
	fclose(stream);
}

/* Write some random text to the pipe */
void write_to_pipe(int fd)
{
	FILE *stream;
	stream = fdopen(fd, "w");
	fprintf(stream, "hello, world\n");
	fprintf(stream, "goodbye !\n");
	fclose(stream);
}

int main(void)
{
	pid_t pid;
	int mypipe[2];

	/* Create the pipe */
	if (pipe(mypipe)) {
		fprintf(stderr, "Pipe failed.\n");
		return EXIT_FAILURE;
	}

	/* Create the child process */
	pid = fork();
	if (pid == (pid_t) 0) {
		/* This is the child process, Close other end first */
		close(mypipe[1]);
		read_from_pipe(mypipe[0]);
		return EXIT_SUCCESS;
	} else if (pid < (pid_t) 0) {
		/* The fork failed. */
		fprintf(stderr, "Fork failed.\n");
		return EXIT_FAILURE;
	} else {
		/* This is the parent process. Close other end first */
		close(mypipe[0]);
		write_to_pipe(mypipe[1]);
		return EXIT_SUCCESS;
	}
}

// https://www.gnu.org/software/libc/manual/html_node/Creating-a-Pipe.html#Creating-a-Pipe
// https://stackoverflow.com/questions/13614040/what-is-difference-between-file-descriptor-and-fildes
// https://linux.die.net/man/3/fdopen
