// Function: int __freadable (FILE *stream)
// Function: int __fwritable (FILE *stream)

// This function is declared in stdio_ext.h

#include <stdio.h>
#include <stdio_ext.h>

void is_stdin_readable(void)
{
	if (__freadable(stdin)) {
		printf("stdin is readable.\n");
	} else {
		printf("stdin is not readable\n");
	}
}

void is_stdout_writeable(void)
{
	if (__fwritable(stdout)) {
		printf("stdout is writable.\n");
	} else {
		printf("stdout is not writable\n");
	}
}

int main(void)
{
	is_stdin_readable();
	is_stdout_writeable();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Opening-Streams.html#Opening-Streams
