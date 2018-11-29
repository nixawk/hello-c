#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 4096

// char * fgets (char *s, int count, FILE *stream)

void fgets_usage(void)
{
	char buf[BUF_SIZE];

	if (fgets(buf, BUF_SIZE, stdin) == NULL) {
		perror("fgets");
		exit(EXIT_FAILURE);
	} else {
		fputs(buf, stdout);
	}
}

int main(void)
{
	fgets_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Line-Input.html#Line-Input
// http://man7.org/linux/man-pages/man3/fgets.3.html
