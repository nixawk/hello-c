#include <stdio.h>
#include <wchar.h>

// wint_t getwc (FILE *stream)

// This is just like fgetwc, except that it is permissible for it to be implemented as a macro that 
// evaluates the stream argument more than once. getwc can be highly optimized, so it is usually 
// the best function to use to read a single wide character.

// wint_t getwc_unlocked (FILE *stream)

void getwc_usage()
{
	putwc(getwc(stdin), stdout);
}

int main(void)
{
	getwc_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Character-Input.html#Character-Input
