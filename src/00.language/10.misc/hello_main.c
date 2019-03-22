#include <stdio.h>

struct entry {
	int argc;
	char **argv;
};

int main(struct entry e)
{
	for (int i = 0; i < e.argc; i++) {
		printf("argv[%d] = %s\n", i, e.argv[i]);
	}
	return 0;
}
