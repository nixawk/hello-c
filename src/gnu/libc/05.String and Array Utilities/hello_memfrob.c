#define _GNU_SOURCE

#include <string.h>
#include <stdio.h>

// void * memfrob (void *mem, size_t length)

// memfrob transforms (frobnicates) each byte of the data structure at mem,
// which is length bytes long, by bitwise exclusive oring it with binary
// 00101010. It does the transformation in place and its return value is
// always mem.

// Note that memfrob a second time on the same data structure returns it
// to its original state.

// This is a good function for hiding information from someone who doesn't
// want to see it or doesn't want to see it very much. To really prevent
// people from retrieving the information, use stronger encryption such
// as that described in See [Cryptographic Functions].

#define SIZE 512

void memfrob_usage(void)
{
	char string[SIZE] = "hello";
	printf("%p - %s\n", string, string);

	char *s = memfrob(string, strlen(string));
	printf("%p - %s\n", s, s);
}

int main(void)
{
	memfrob_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Character-Handling
