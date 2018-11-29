#include <time.h>
#include <stdio.h>
#include <string.h>

// Function: char * strptime (const char *s, const char *fmt, struct tm *tp)

// The strptime function processes the input string from right to left.
// Each of the three possible input elements (white space, literal, or format)
// are handled one after the after. If the input cannot be matched to the
// format string the function stops. The remainder of the format and input
// strings are not processed.

const char *parse_date(const char *input, struct tm *tm)
{
	const char *cp;

	/* First clear the result structure.  */
	memset(tm, '\0', sizeof(*tm));

	/* Try the ISO format first.  */
	cp = strptime(input, "%F", tm);	// %F = %Y-%m-%d
	if (cp == NULL) {
		/* Does not match.  Try the US form.  */
		cp = strptime(input, "%D", tm);	// %D = %m/%d/%y.
	}

	return cp;
}

int main(void)
{
	const char *s = "2017-12-27 04:15:48-0500";
	struct tm tp;
	const char *cp = parse_date(s, &tp);

	if (cp != NULL) {
		printf("%s\n", cp);
	}
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Low_002dLevel-Time-String-Parsing.html#Low_002dLevel-Time-String-Parsing
