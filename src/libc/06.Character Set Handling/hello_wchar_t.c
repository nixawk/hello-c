#include <stddef.h>
#include <wchar.h>
#include <stdio.h>

    // Data type: wchar_t

// This data type is used as the base type for wide character strings. In other words,
// arrays of objects of this type are the equivalent of char[] for multibyte character
// strings. The type is defined in [stddef.h]

// The ISO C90 standard, where wchar_t was introduced, does not say anything specific
// about the representation. It only requires that this type is capable of storing all
// elements of the basic character set. Therefore it would be legitimate to define
// wchar_t as char, which might make sense for embedded systems.

// But in the GNU C Library wchar_t is always 32 bits wide and, therefore, capable of
// representing all UCS-4 values and, therefore, covering all of ISO 10646. Some Unix
// systems define wchar_t as a 16-bit type and thereby follow Unicode very strictly.
// This definition is perfectly fine with the standard, but it also means that to
// represent all characters from Unicode and ISO 10646 one has to use UTF-16 surrogate
// characters, which is in fact a multi-wide-character encoding. But resorting to
// multi-wide-character encoding contradicts the purpose of the wchar_t type.

    // Data type: wint_t

// wint_t is a data type used for parameters and variables that contain a single wide
// character. As the name suggests this type is the equivalent of int when using the
// normal char strings. The types wchar_t and wint_t often have the same representation
// if their size is 32 bits wide but if wchar_t is defined as char the type wint_t must
// be defined as int due to the parameter promotion.

// This type is defined in wchar.h and was introduced in Amendment 1 to ISO C90.

    // wint_t WCHAR_MIN
    // wint_t WCHAR_MAX
    // wint_t WEOF

void wchar_t_usage(void)
{
	wchar_t wc = L'A';
	wint_t wi = L'A';

	printf("WCHAR_MIN: %d\n", WCHAR_MIN);
	printf("WCHAR_MAX: %d\n", WCHAR_MAX);
	printf("WEOF     : %d\n", WEOF);
}

int main(void)
{
	wchar_t_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Extended-Char-Intro.html#Extended-Char-Intro
