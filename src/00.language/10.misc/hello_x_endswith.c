#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

bool endswith(s, suffix)
char *s;
char *suffix;
{
	assert(s != NULL && suffix != NULL);
	return strncmp(s + strlen(s) - strlen(suffix), suffix, strlen(suffix)
	    ) == 0;
}

int main(void)
{
	endswith("hello", "lo") ? printf("yes\n") : printf("no\n");
	// endswith("hello", NULL);

	return 0;
}
