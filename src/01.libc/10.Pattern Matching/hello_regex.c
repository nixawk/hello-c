// The GNU C Library supports two interfaces for matching regular expressions.
// One is the standard POSIX.2 interface, and the other is what the GNU C
// Library has had for many years.

// Both interfaces are declared in the header file regex.h.
// If you define _POSIX_C_SOURCE, then only the POSIX.2 functions,
// structures, and constants are declared.

// int regcomp (regex_t *restrict compiled, const char *restrict pattern, int cflags)

// int regexec(const regex_t *preg, const char *string, size_t nmatch, regmatch_t pmatch[], int eflags);

#include <regex.h>
#include <stdio.h>
#include <stdlib.h>

void regex_match(const char *regex, const char *string, const int maxmatched)
{
	regex_t regbuf;		/* regex expression buf */
	// size_t nmatch = maxmatched;     /* num of matched */
	regmatch_t pmatch[maxmatched];	/* pmatch inclues regex start/end  */
	int i;			/* for loop */

	/* regcomp() is used to compile a regular expression into a form that is
	   suitable for subsequent regexec() searches. */

	if (regcomp(&regbuf, regex, REG_EXTENDED | REG_ICASE) != 0) {
		perror("regcomp");
		exit(EXIT_FAILURE);
	}

	/* regexec() tries to match the compiled regular expression against str */

	if (regexec(&regbuf, string, maxmatched, pmatch, 0) != 0) {
		perror("regexec");
		exit(EXIT_FAILURE);
	}

	/* output regex matched */

	// regmatch_t.rm_so - The offset in string of the beginning of a substring.
	//                    Add this value to string to get the address of that
	//                    part.

	// regmatch_t.rm_eo - The offset in string of the end of the substring.

	for (i = 0; i < maxmatched; i++) {
		printf
		    ("a matched substring \"%.*s\" is found at position %d to %d.\n",
		     pmatch[i].rm_eo - pmatch[i].rm_so,
		     &string[pmatch[i].rm_so], pmatch[i].rm_so,
		     pmatch[i].rm_eo - 1);
	}

	/* free compiled regular expression */

	regfree(&regbuf);
}

int main(int argc, const char *argv[])
{
	if (argc != 4) {
		printf("[*] Usage: %s regex string regex_max_matched\n",
		       argv[0]);
		exit(EXIT_FAILURE);
	}

	regex_match(argv[1], argv[2], atoi(argv[3]));
	return 0;
}

/*

$ ./a.out "hello(.*)" helloworld 6
a matched substring "helloworld" is found at position 0 to 9.
a matched substring "world" is found at position 5 to 9.
a matched substring "" is found at position -1 to -2.
a matched substring "" is found at position -1 to -2.
a matched substring "" is found at position -1 to -2.
a matched substring "" is found at position -1 to -2.

*/

// http://man7.org/linux/man-pages/man3/regex.3.html
// https://www.gnu.org/software/libc/manual/html_node/POSIX-Regexp-Compilation.html#POSIX-Regexp-Compilation
// https://www.gnu.org/software/libc/manual/html_node/Matching-POSIX-Regexps.html#Matching-POSIX-Regexps
// https://www.gnu.org/software/libc/manual/html_node/Regexp-Subexpressions.html#Regexp-Subexpressions
