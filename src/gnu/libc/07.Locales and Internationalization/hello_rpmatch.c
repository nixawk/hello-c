#define _GNU_SOURCE
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <libintl.h>		// gettext

// int rpmatch (const char *response)

// The function rpmatch checks the string in response for whether or not it is
// a correct yes-or-no answer and if yes, which one. The check use the YESEXPR
// and NOEXPR data in the LC_MESSAGES category of the currently selected 
// locale. The return value is as follow:

    // 1 - The user entered an affirmative answer.
    // 0 - The user entered a negative answer.
    // -1 - The answer matched neither the YESEXPR nor the NOEXPR regular
    // expression

#define _POSIX2_LINE_MAX        2048

typedef enum {
	false,
	true
} bool;

void rpmatch_usage(void)
{
	/* Use a safe default */
	bool doit = false;
	char *line = NULL;
	size_t len = 0;

	fputs(gettext("Do you really want to do this ? "), stdout);
	fflush(stdout);

	/* Prepare the getline call */
	line = (char *)malloc(_POSIX2_LINE_MAX);
	while (getline(&line, &len, stdin) >= 0) {
		/*check the response */
		int res = rpmatch(line);
		if (res > 0) {
			printf("doit\n");
			doit = true;
			break;
		}
	}

	/* free what getline allocated */
	free(line);
}

int main(void)
{
	rpmatch_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Locales
