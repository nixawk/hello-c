#define _GNU_SOURCE

#include <string.h>
#include <stdio.h>


// char * strfry (char *string)

// strfry creates a pseudorandom anagram of a string, replacing the input
// with the anagram in place. For each position in the string, strfry swaps
// it with a position in the string selected at random (from a uniform
// distribution). The two positions may be the same.

// The return value of strfry is always string.

#define SIZE 512


void
strfry_usage(void)
{
	char seed[SIZE] = "abcdefgh";
	char *s = strfry(seed);

	printf("%s\n", s);
}


int
main(void)
{
	strfry_usage();
	return 0;
}


// http://www.gnu.org/software/libc/manual/html_mono/libc.html#Representation-of-Strings