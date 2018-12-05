#include <wchar.h>
#include <stdio.h>

// Data type: wint_t

// wint_t is a data type used for parameters and variables that contain a
// single wide character. As the name suggests this type is the equivalent
// of int when using the normal char strings. The types wchar_t and wint_t
// often have the same representation if their size is 32 bits wide but if
// wchar_t is defined as char the type wint_t must be defined as int due to
// the parameter promotion.

// This type is defined in wchar.h and was introduced in Amendment 1 to
// ISO C90

void show_wint_t(void)
{
	wint_t wd = 1234;

	wprintf(L"wint_t wd: %lu\n", wd);
	wprintf(L"WCHAR_MIN: %lu\n", WCHAR_MIN);
	wprintf(L"WCHAR_MAX: %lu\n", WCHAR_MAX);
}

int main(void)
{
	show_wint_t();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Character-Handling
