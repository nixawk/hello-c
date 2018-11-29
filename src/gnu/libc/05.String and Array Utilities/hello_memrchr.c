#define _GNU_SOURCE

#include <string.h>
#include <stdio.h>

    // void * memrchr (const void *block, int c, size_t size)

// The function memrchr is like memrchr, except that it searches backwards
// from the end of the block defined by block and size (instead of forwards
// from the front).

void memrchr_usage(void)
{
	char *s = "hello, world";

	char *s1 = memchr(s, 'l', strlen(s));
	if (s1 != NULL) {
		printf("%s\n", s1);
	}
	// This function is a GNU extension.
	char *s2 = memrchr(s, 'l', strlen(s));
	if (s2 != NULL) {
		printf("%s\n", s2);
	}
}

int main(void)
{
	memrchr_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Character-Handling
