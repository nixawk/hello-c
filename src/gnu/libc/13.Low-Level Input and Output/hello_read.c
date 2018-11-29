#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// ssize_t read (int filedes, void *buffer, size_t size)

// The read function reads up to [size] bytes from the file with descriptor fiedes,
// storing the results in the buffer.

// The return value is the number of bytes actually read.
// This might be less than size; for example, if there aren't that many bytes left
// in the file or if there aren't that many bytes immediately available. The
// exact behavior depends on what kind of file it is. Note that reading less than
// [size] bytes is not an error.

// If [read] returns at least one character, there is no way you can tell whether
// end-of-file was reached. But if you did reach the end, the next read will
// return zero.

// In case of an error, read returns -1. The following [errno] error conditions
// are defined for this function:

    // EAGAIN
    // EBADF
    // EINTR
    // EIO
    // EINVAL 

#define SIZE 8192

void read_usage(void)
{
	int fd;
	char *ptr;
	ssize_t n;

	fd = open("/etc/passwd", O_RDONLY, S_IRWXU);
	if (fd == -1) {
		fprintf(stderr, "creat() failed\n");
	} else {
		ptr = (char *)calloc(SIZE, sizeof(char));
		if (ptr == NULL) {
			fprintf(stderr, "calloc() failed\n");
		} else {
			n = read(fd, ptr, SIZE);
			printf("read bytes: [%lu]\noutput: %s\n", n, ptr);
			free(ptr);
		}
		close(fd);
	}
}

int main(void)
{
	read_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/I_002fO-Primitives.html#I_002fO-Primitives
