#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// ssize_t read (int filedes, void *buffer, size_t size)
// ssize_t pread (int filedes, void *buffer, size_t size, off_t offset)
// ssize_t pread64 (int filedes, void *buffer, size_t size, off64_t offset)

// The [pread] function is similar to the [read] function.
// The first three arguments are identical, and the return values and error codes also correspond.

// The different is the fourth argument and its handling. The data block is not read from the current
// position of the file descriptor filedes. Instead the data is read from the file starting at position
// offset. The position of the file descriptor itself is not affected by the operation. The value is the
// same as before the call.

#define SIZE 512

void pread_usage(void)
{
	int fd;
	char *ptr;
	ssize_t n;

	off_t offset = 64;

	fd = open("/etc/passwd", O_RDONLY, S_IRWXU);
	if (fd == -1) {
		fprintf(stderr, "open() failed\n");
	} else {
		ptr = (char *)calloc(SIZE, sizeof(char));
		if (ptr == NULL) {
			fprintf(stderr, "calloc() failed\n");
		} else {
			n = pread(fd, ptr, SIZE, offset);
			printf("read bytes: [%lu]\noutput: %s\n", n, ptr);
			free(ptr);
		}
		close(fd);
	}

}

int main(void)
{
	pread_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/I_002fO-Primitives.html#I_002fO-Primitives
