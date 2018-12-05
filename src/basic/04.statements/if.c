#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	if (argc < 2) {
		printf("[*] Usage: %s arg1 arg2 ... argN\n", argv[0]);
		exit(1);
	}

	for (int i = 1; i < argc; i++) {
		printf("%s ", argv[i]);
	}
	printf("\n");
	return 0;
}

/* https://en.cppreference.com/w/c/language/if */
