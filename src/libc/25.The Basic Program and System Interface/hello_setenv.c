#include <stdlib.h>
#include <stdio.h>

    // int setenv (const char *name, const char *value, int replace)

// The [setenv] function can be used to add a new definition to the environment.
// The entry with the name [name] is replaced by the value 'name=value'.
// Please note that this is also true if value is the value is the empty string.

// To do this a new string is created and the strings [name] and [value] are copied.
// A null pointer for the [value] parameter is illegal. If the environment already
// contains an entry with key [name] the replace parameter controls the actions.

// If replace is 0, nothing happens. Otherwise the old entry is replaced by the new one.

// If the function is successful it returns 0. Otherwise the environment is unchanged
// and the return value is -1 and errno is set.

    // int unsetenv (const char *name)

// The function returns -1 if name is a null pointer, points to an empty string, 
// or points to a string containing a = character. It returns 0 if the call succeeded.

    // int clearenv (void)

// The [clearenv] function removes all entries from the environment.
// Using [putenv] and [setenv] new entries can be added again later.
// If the function is successful it returns 0. Otherwise the return value is nonzero.

void setenv_usage(void)
{
	if (0 == setenv("LL", "'ls -l'", 0)) {
		printf("LL=%s\n", getenv("LL"));	// output: LL='ls -l'
		unsetenv("LL");
		printf("LL=%s\n", getenv("LL"));	// output: LL=(null)
	}
}

int main(void)
{
	setenv_usage();
	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Environment-Access.html#Environment-Access
