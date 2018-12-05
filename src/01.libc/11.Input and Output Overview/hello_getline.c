#include <stdio.h>
#include <stdlib.h>

#define SIZE 512

// ssize_t getline (char **lineptr, size_t *n, FILE *stream)

// When getline is successful, it returns the number of characters read (including the newline, 
// but not including the terminating null). This value enables you to distinguish null characters
// that are part of the line from the null character inserted as a terminator.

// If an error occurs or end of file is reached without any by bytes read, getline returns -1. 

// ssize_t getdelim (char **lineptr, size_t *n, int delimiter, FILE *stream)

void getline_usage(void)
{
	char *ptr = NULL;
	size_t n = SIZE;

	ptr = (char *)calloc(SIZE, sizeof(char));
	if (ptr != NULL) {
		n = getline(&ptr, &n, stdin);
		if (n != -1) {
			printf("read [%lu] bytes from stdin\n", n);
			printf("getline: %s\n", ptr);
		}
		free(ptr);
	}
}

int main(void)
{
	getline_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Line-Input.html#Line-Input
// http://www.cplusplus.com/reference/string/string/getline/
