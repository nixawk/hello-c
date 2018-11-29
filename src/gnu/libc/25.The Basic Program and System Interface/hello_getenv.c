#include <stdio.h>
#include <stdlib.h>

// char * getenv (const char *name)

// This function returns a string that is the value of the environment variable name.
// If the environment variable is not defined, the value is a null pointer.

// char * secure_getenv (const char *name)

// This function is similar to [getenv], but it returns a null pointer if the environment
// is untrusted. This happen when the program file has SUID or SGID bits set. General-purpose
// libraries should always prefer this function over [getenv] to avoid vulnerabilities if the
// library is referenced from a SUID/SGID program.

void getenv_usage(void)
{
	printf("[env] SHELL = %s\n", getenv("SHELL"));
}

int main(void)
{
	getenv_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Environment-Access.html#Environment-Access
