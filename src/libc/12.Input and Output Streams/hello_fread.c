#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef BUF_SIZE		/* overwritten with 'cc -D' */
#define BUF_SIZE 4096
#endif

// size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
// size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);

void fread_usage(const char *filename)
{
	FILE *stream;
	char *buf;
	size_t nread;

	stream = fopen(filename, "r");
	if (stream == NULL) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	buf = (char *)malloc(BUF_SIZE);
	if (buf == NULL) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	memset(buf, '\0', BUF_SIZE);

	while (!(feof(stream) || ferror(stream))) {
		nread = fread(buf, BUF_SIZE, 1, stream);
		// printf("%ld\n read", nread * BUF_SIZE);
		printf("%s\n", buf);
	}

	free(buf);
	fclose(stream);
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("[*] Usage: %s <FILE>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	fread_usage(argv[1]);

	exit(EXIT_SUCCESS);
}

// http://man7.org/linux/man-pages/man3/fread.3.html
// http://www.cplusplus.com/reference/cstdio/fread/
// http://en.cppreference.com/w/c/io/fread
