#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int memcmp (const void *a1, const void *a2, size_t size)
// int wmemcmp (const wchar_t *a1, const wchar_t *a2, size_t size)
// int strcmp (const char *s1, const char *s2)
// int wcscmp (const wchar_t *ws1, const wchar_t *ws2)
// int strcasecmp (const char *s1, const char *s2)
// int wcscasecmp (const wchar_t *ws1, const wchar_t *ws2)
// int strncmp (const char *s1, const char *s2, size_t size)
// int wcsncmp (const wchar_t *ws1, const wchar_t *ws2, size_t size)
// int strncasecmp (const char *s1, const char *s2, size_t n)
// int wcsncasecmp (const wchar_t *ws1, const wchar_t *s2, size_t n)
// int strverscmp (const char *s1, const char *s2)
// int bcmp (const void *a1, const void *a2, size_t size)

void strcmp_usage(char *inputstr)
{
	char flag[] = "hello";
	int ret = strcmp(flag, inputstr);
	// If the two strings are equal, strcmp returns 0.

	printf("%d\n", ret);	/* ret = s1 - str */
}

int main(int argc, const char *argv[])
{
	if (argc != 2) {
		printf("[*] %s <hello>", argv[0]);
		exit(0);
	}

	strcmp_usage((char *)argv[1]);

	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/String_002fArray-Comparison.html#String_002fArray-Comparison
