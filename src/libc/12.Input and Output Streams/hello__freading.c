#include <stdio.h>
#include <stdio_ext.h>

void is_stdin_reading(void)
{
	if (__freading(stdin)) {
		printf("stdin was last read.\n");
	} else {
		printf("stdin wss not last read.\n");
	}
}

void is_stdout_writing(void)
{
	if (__fwriting(stdout)) {
		printf("stdout was last written.\n");
	} else {
		printf("stdout was not written.\n");
	}
}

int main(void)
{
	is_stdin_reading();
	is_stdout_writing();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Opening-Streams.html#Opening-Streams
