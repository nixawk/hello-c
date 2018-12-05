#include <stdio.h>
#include <string.h>

// char * strcat (char *restrict to, const char *restrict from)
// wchar_t * wcscat (wchar_t *restrict wto, const wchar_t *restrict wfrom)

// The strcat function is similar to strcpy, except that the bytes [from]
// are concatenated or appended to the end of [to], instead of overwriting it.

// It is almost always unnecessary to use strcat.

#define SIZE 256

void strcat_usage()
{
	char dst[SIZE] = "hello, ";
	char src[SIZE] = "world";

	printf("before strcat: %s\n", dst);
	strcat(dst, src);
	printf("after  strcat: %s\n", dst);
}

int main(void)
{
	strcat_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Concatenating-Strings.html#Concatenating-Strings
