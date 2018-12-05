#include <locale.h>
#include <stdio.h>

// char * setlocale (int category, const char *locale)

// The function setlocale sets the current locale for category category
// to locale.

// If category is LC_ALL, this specifies the locale for all purposes. The other
// possible values of category specify a single purpose.

// You can also use this function to find out the current locale by passing
// a null pointer as the locale argument. In this case, setlocale returns
// a string that is the name of the locale currently selected for category
// category.

// When the locale argument is not a null pointer, the string returned by
// setlocale reflects the newly-modified locale.

// If you specify an empty string for locale, this means to read the
// appropriate environment variable and use its value to select the locale
// for category.

// If a nonempty string is given for locale, then the locale of that name
// is used if possible.

// The effective locale name must be a valid locale name. If you specify an
// invalid locale name, setlocale returns a null pointer and leaves the
// current locale unchanged.

// Standard Locales

    // C - This is the standard C locale. The attributes and behavior it
    //     provides are specified in the ISO C standard. When your program
    //     starts up, it initially uses this locale by default.

    // POSIX - This is the standard POSIX locale. Currently, it is an alias
    //     for the standard C locale.

    // "" - The empty name says to select a locale based on environment
    //     variables.

// Locale Names

    // The following command prints a list of locales supported by the system:
    // $ locale -a

    // Locale names which are longer than an implementation-defined limit are
    // invalid and cause setlocale to fail.

void setlocale_usage(void)
{
	char *locale = setlocale(LC_ALL, NULL);

	printf("current locale: %s\n", locale);	// current locale: C
}

int main(void)
{
	setlocale_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Locales
