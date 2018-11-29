#include <wctype.h>
#include <stdio.h>

// int iswprint (wint_t wc)

// Returns true if wc is a printing character. Printing characters include all the graphic characters,
// plus the space (‘ ’) character.

// This function can be implemented using

    // iswctype (wc, wctype ("print"))

void iswprint_usage(void)
{
	wchar_t ch = L' ';

	if (iswprint(ch)) {
		printf("[%c] is a printing character.\n", ch);
	}
}

int main(void)
{
	iswprint_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Wide-Characters.html#Classification-of-Wide-Characters
