#include <stdio.h>

// The argument [envp] gives the program's environment; it is the same as
// the value of [environ].

int main(int argc, const char *argv[], const char *envp[])
{
	int i;

	for (i = 0; envp[i] != NULL; i++) {
		printf("%d: %s\n", i, envp[i]);
	}

	return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Program-Arguments.html
