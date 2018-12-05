#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

/*
int system(const char *command);

command   - This is the C string containing the name of the requested variable.

The value returned is -1 on error, and the return status of the command otherwise.

*/

int main(int argc, char const *argv[])
{
	int i;

	if (argc < 2) {
		printf("[*] Usage: %s <command> <command> ...\n", argv[0]);
		exit(0);
	}

	for (i = 1; i < argc; ++i) {
		printf("$ %s\n", argv[i]);
		system(argv[i]);
		printf("\n");
	}

	return 0;
}
