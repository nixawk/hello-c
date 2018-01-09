#include <locale.h>
#include <stdio.h>

// struct lconv * localeconv (void)

// The localeconv function returns a pointer to a structure whose components
// contain information about how numeric and monetary values should be
// formatted in the current locale. You should not modify the structure
// or its contents. The structure might be overwritten by subsequent calls
// to localeconv, or by calls to setlocale, but no other function in the
// function in the library overwrites this value.

void
localeconv_usage(void)
{
    struct lconv *lc;

    setlocale(LC_ALL, "en_US.UTF-8");
    lc = localeconv();
    printf("en_US currency_symbol: %s\n", lc->currency_symbol);

    // $ gcc hello_localeconv.c
    // $ ./a.out
    // en_US currency_symbol: $
}


int
main(void)
{
    localeconv_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Locales
// http://en.cppreference.com/w/c/locale/lconv