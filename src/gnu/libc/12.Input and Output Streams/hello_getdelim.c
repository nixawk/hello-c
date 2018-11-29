#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

// ssize_t getdelim (char **lineptr, size_t *n, int delimiter, FILE *stream)

/*

ssize_t
getline (char **lineptr, size_t *n, FILE *stream)
{
  return getdelim (lineptr, n, '\n', stream);
}

*/

int main(int argc, char *argv[])
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	int delim = ':';

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");
	if (stream == NULL) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	while ((nread = getdelim(&line, &len, delim, stream)) != -1) {
		printf("Retrieved line of length %zu:\n", nread);
		fwrite(line, nread, 1, stdout);
	}

	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}

// https://www.gnu.org/software/libc/manual/html_node/Line-Input.html#Line-Input
// http://man7.org/linux/man-pages/man3/getline.3.html
