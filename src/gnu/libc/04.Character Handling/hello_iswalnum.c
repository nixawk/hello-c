#include <wctype.h>
#include <stdio.h>

// int iswalnum (wint_t wc)

// This function returns a nonzero value if wc is an alphanumeric character (a letter or number); in other words,
// if either iswalpha or iswdigit is true of a character, then iswalnum is also true.

// This function can be implemented using:

    // iswctype (wc, wctype ("alnum"))

void iswalnum_usage(void)
{
	wchar_t ch = L'a';

	if (iswalnum(ch)) {
		printf("[%c] is an alphanumeric wide character.\n", ch);
	}
}

int main(void)
{
	iswalnum_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Wide-Characters.html#Classification-of-Wide-Characters
