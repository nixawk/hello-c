#include <wchar.h>
#include <string.h>
#include <stdio.h>

// A string is a null-terminated array of type char, including the terminating
// null byte. String-valued variables are usually declared to be pointers of
// char *. Such variable do not include space for the next of a string; that
// has to be stored somewhere else -- in an array variable, a string constant,
// or dynamically allocated memory. It's up to you to store the address of the
// address of the chosen memory space into the pointer variable. Alternatively
// you can store a null pointer in the pointer variable. The mull pointer does
// not point anywhere, so attempting to reference the string it points to get
// an error.

// A multibyte character is a sequence of one or more bytes that represents a
// single character using the locale's encoding scheme; a null byte always
// represents the null character. A multiple string is a string that consists
// entirely of multibyte characters. In contrast, a wide string is a
// null-terminated sequence of wchar_t objects. A wide-string variable is
// usually declared to be a pointer of type wchar_t *, by analogy with string
// variables and char *.

void hello_string(void)
{
	char *ch = "hello, world";
	wchar_t *ws = L"hello, world";

	printf("ch length: %lu\n", strlen(ch));
	printf("ws length: %lu\n", wcslen(ws));
}

int main(void)
{
	hello_string();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Character-Handling
