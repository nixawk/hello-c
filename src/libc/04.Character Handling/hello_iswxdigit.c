#include <wctype.h>
#include <stdio.h>

// int iswxdigit (wint_t wc)

// Returns true if wc is a hexadecimal digit. Hexadecimal digits include the normal 
// decimal digits ‘0’ through ‘9’ and the letters ‘A’ through ‘F’ and ‘a’ through ‘f’.

// This function can be implemented using

    // iswctype (wc, wctype ("xdigit"))

void iswxdigit_usage(void)
{
	wchar_t ch = L'f';

	if (iswxdigit(ch)) {
		printf("[%c] is a hexadecimal digit.\n", ch);
	}
}

int main(void)
{
	iswxdigit_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Wide-Characters.html#Classification-of-Wide-Characters
