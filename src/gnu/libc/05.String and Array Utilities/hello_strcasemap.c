#include <string.h>
#include <stdio.h>

// int strcasecmp (const char *s1, const char *s2)

// This function is like strcmp, except that differences in case are ignored,
// and its arguments must be multibyte strings. How uppercase and lowercase
// characters are related is determined by the currently selected locale.
// In the standard "C" locale the characters Ä and ä do not match but in
// a locale which regards these characters as parts of the alphabet they do match.

// strcmp VS strcasecmp

void strcasecmp_usage(void)
{
	char *s1 = "Hello";
	char *s2 = "hello";

	if (0 == strcasecmp(s1, s2)) {
		printf("s1 == s2\n");
	}
}

int main(void)
{
	strcasecmp_usage();
	return 0;
}

// http://www.gnu.org/software/libc/manual/html_mono/libc.html#Representation-of-Strings
