#include <wctype.h>
#include <stdio.h>

// int iswctype (wint_t wc, wctype_t desc)

// This function returns a nonzero value if wc is in the character class specified by desc.
// desc must previously be returned by a successful call to wctype.

void iswctype_usage(void)
{
	wchar_t ch = L'a';

	if (iswctype(ch, wctype("lower"))) {
		printf("[%c] is a lower wide char.\n", ch);
	}
}

int main(void)
{
	iswctype_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Wide-Characters.html#Classification-of-Wide-Characters
// http://www.cplusplus.com/reference/cwctype/iswctype/
