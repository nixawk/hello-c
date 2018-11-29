#include <stdio.h>
#include <wchar.h>

// wint_t fgetwc (FILE *stream)

// This function reads the next wide character from the stream stream and returns its value.
// If an end-of-file condition or read error occurs, WEOF is returned instead.

// wint_t fgetwc_unlocked (FILE *stream)

void fgetwc_usage(void)
{
	putwc(fgetwc(stdin), stdout);
}

int main(void)
{
	fgetwc_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Character-Input.html#Character-Input
