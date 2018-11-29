#include <stdlib.h>
#include <stdio.h>

//  int putenv (char *string)

// The [putenv] function adds or removes definitions from the environment.
// If the string is of the form 'name=value', the definition is added to
// the environment. Otherwise, the string is interpreted as the name of
// an environment variable, and any definition for this variable in the
// environment is removed.

// If the function is successful it returns 0. Otherwise the return value is
// nonzero and [errno] is set to indicate the error.

void putenv_usage(void)
{
	if (0 == putenv("LL='ls -l'")) {
		printf("LL=%s\n", getenv("LL"));
	}
}

int main(void)
{
	putenv_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Environment-Access.html#Environment-Access
