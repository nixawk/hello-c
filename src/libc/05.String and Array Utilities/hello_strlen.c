#include <stdio.h>
#include <string.h>

// strlen, can get the length of a string.
// This function is declared in the header file "string.h"

// size_t strlen (const char *s)
// size_t wcslen (const wchar_t *ws)

// size_t strnlen (const char *s, size_t maxlen)
// size_t wcsnlen (const wchar_t *ws, size_t maxlen)

void string_array_length(void);
void string_pointer_length(void);

// When applied ti an array,
// [strlen] function returns the length of the string stored here.
// [sizeof] operator gets the allocated size of the array that holds a string.

void string_array_length(void)
{
	char string[32] = "hello, world";

	printf("strlen(array) = %lu\n", strlen(string));	// print 12 bytes
	printf("sizeof(array) = %lu\n", sizeof(string));	// print 32 bytes
}

void string_pointer_length(void)
{
	char string[32] = "hello, world";
	char *ptr = string;

	printf("strlen(ptr) = %lu\n", strlen(ptr));	// 12 bytes
	printf("sizeof(ptr) = %lu\n", sizeof(ptr));	// 8 bytes (IA64)
}

int main(void)
{
	string_array_length();
	string_pointer_length();

	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/String-Length.html#String-Length
