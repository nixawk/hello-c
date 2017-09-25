#include <wctype.h>
#include <stdio.h>

// wctype_t wctype (const char *property)

// wctype returns a value representing a class of wide characters which is identified by the string property.
// Besides some standard properties each locale can define its own ones.
// In case no property with the given name is known for the current locale selected for the LC_CTYPE category,
// the function returns zero.


// The properties known in every locale are:

// "alnum" "alpha" "cntrl" "digit"
// "graph" "lower" "print" "punct"
// "space" "upper" "xdigit"


void
wctype_usage(void)
{
    printf("%u\n", wctype("alnum"));
    printf("%u\n", wctype("alpha"));
    printf("%u\n", wctype("cntrl"));
    printf("%u\n", wctype("digit"));
    printf("%u\n", wctype("graph"));
    printf("%u\n", wctype("lower"));
    printf("%u\n", wctype("print"));
    printf("%u\n", wctype("punct"));
    printf("%u\n", wctype("space"));
    printf("%u\n", wctype("upper"));
    printf("%u\n", wctype("xdigit"));
}


int
main(void)
{
    wctype_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Classification-of-Wide-Characters.html#Classification-of-Wide-Characters
// http://www.cplusplus.com/reference/cwctype/wctype_t/
// http://www.cplusplus.com/reference/cwctype/iswctype/