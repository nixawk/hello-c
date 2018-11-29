#include <wctype.h>
#include <stdio.h>

// int iswcntrl (wint_t wc)

// Returns true if wc is a control character (that is, a character that is not a printing character).

// This function can be implemented using

    // iswctype (wc, wctype ("cntrl"))

void iswcntrl_usage(void)
{
	wchar_t ch = L'\b';

	if (iswcntrl(ch)) {
		printf("[\\b] is a control character.\n");
	}
}

int main(void)
{
	iswcntrl_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Wide-Characters.html#Classification-of-Wide-Characters
