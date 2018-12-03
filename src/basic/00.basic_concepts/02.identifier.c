/*
 * An identifier is an arbitrarily long sequence of digits, underscores,
 * lowercase and uppercase Latin letters, and Unicode characters specified
 * using \u and \U escape notation (since C99). A valid identifer must begin
 * with a non-digit character (Latin letter, underscore, or Unicode non-digit
 * character (since C99)). Indentifiers are case-senstive (lowercase and
 * uppercase letters are distinct).
 *
 * Every identifier other than macro name or macro parameter name has scope.
 * belongs to a name space, and may have linkage. The same identifier can
 * denote different entities at different points in the program, or may denote
 * different entities at the same point if the entities are in different name
 * spaces.
 */

#include <stdio.h>

int main(void)
{
	int my_identifier = 10;
	printf("my_identifier: %d\n", my_identifier);
	return 0;
}

/* https://en.cppreference.com/w/c/language/identifier */
