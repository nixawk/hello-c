// Standard Streams

// FILE * stdin
// FILE * stdout
// FILE * stderr

#include <stdio.h>

void stdin_vs_STDIN_FILENO(void)
{
	printf("STDIN_FILENO, is a file descriptor, a number\n");
	printf("stdin       , is a file stream, a structure\n");
}

int main(void)
{
	stdin_vs_STDIN_FILENO();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Standard-Streams.html#Standard-Streams
