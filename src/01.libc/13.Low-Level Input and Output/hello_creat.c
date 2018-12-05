#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

// int creat (const char *filename, mode_t mode)

    // is equivalent to

// int open (filename, O_WRONLY | O_CREAT | O_TRUNC, mode)

// If on a 32 bit machine the sources are translated with _FILE_OFFSET_BITS == 64 
// the function creat returns a file descriptor opened in the large file mode which 
// enables the file handling functions to use files up to 2^63 in size and offset 
// from -2^63 to 2^63. This happens transparently for the user since all of the 
// low-level file handling functions are equally replaced.

// int creat64 (const char *filename, mode_t mode)

void creat_usage(void)
{
	int fd;

	fd = creat("/tmp/testfile", S_IRWXU);	/* Linux System Call */
	if (fd != -1) {
		printf("file descriptor: %d\n", fd);
		close(fd);
	}
}

int main(void)
{
	creat_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Opening-and-Closing-Files.html#Opening-and-Closing-Files
// https://www.gnu.org/software/libc/manual/html_node/File-Status-Flags.html#File-Status-Flags
