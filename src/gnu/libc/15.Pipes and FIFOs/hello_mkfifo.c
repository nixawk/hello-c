// A FIFO special file is similar to a pipe, except that it is created in a
// different way. Instead of being an anonymous communications channel, a FIFO
// special file is entered into the file system by calling mkfifo.

// Once you have created a FIFO special file in this way, any process can open
// it for reading or writing, in the same way as an ordinary file. However, it
// has to be open at both ends simulanelusly before you can proceed to do any
// input or output operations on it. Opening a FIFO for reading normally blocks
// until some other process opens the same FIFO for writing, and vice versa.

// The mkfifo function is declared in the header file sys/stat.h

    // int mkfifo(const char *filename, mode_t mode)

// The mkfifo function makes a FIFO special file with name filename. The mode
// argument is used to set the file's permissions;

// The normal, successful return value from mkfifo is 0. In the case of an
// error, -1 is returned. In addition to the usual file name errors, the
// following errno error conditions are defined for this function:

    // EEXIST - The named file already exists
    // ENOSPC - The directory or file system cannot be extended
    // EROFS  - The directory that would contain the file resides on a read-only file system.

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 1024

/* Create a fifo file with mkfifo */
void create_fifo_file(const char *fifo)
{
	if (mkfifo(fifo, S_IWUSR | S_IRUSR | S_IRUSR) != 0) {
		fprintf(stderr, "mkfifo failed\n");
		exit(EXIT_FAILURE);
	}
}

/* Write data into fifo file */
void write_data(const char *fifo)
{
	FILE *stream;
	if ((stream = fopen(fifo, "w")) == NULL) {
		fprintf(stderr, "fopen failed\n");
		exit(EXIT_FAILURE);
	}
	fputs("hello, fifo\n", stream);
	fclose(stream);
}

/* Read data from fifo file */
void read_data(const char *fifo)
{
	FILE *stream;
	char buf[SIZE] = { '\0' };

	if ((stream = fopen(fifo, "r")) == NULL) {
		fprintf(stderr, "fopen failed\n");
		exit(EXIT_FAILURE);
	}

	if (fgets(buf, SIZE, stream) == NULL) {
		fprintf(stderr, "fgets failed\n");
		exit(EXIT_FAILURE);
	}

	printf("%s\n", buf);
	fclose(stream);
}

int main(void)
{
	pid_t pid;
	const char *fifo = "fifo";

	create_fifo_file(fifo);

	pid = fork();
	if (pid > (pid_t) 0) {
		// printf("parent process\n");
		write_data(fifo);
	} else if (pid == (pid_t) 0) {
		// printf("child process\n");
		read_data(fifo);
	} else {
		fprintf(stderr, "fork() failed\n");
		exit(EXIT_FAILURE);
	}

	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/FIFO-Special-Files.html#FIFO-Special-Files
// http://pubs.opengroup.org/onlinepubs/7908799/xsh/sysstat.h.html
