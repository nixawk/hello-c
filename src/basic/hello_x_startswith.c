#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>


bool
startswith(char *s, char *prefix)
{
    assert(s != NULL && prefix != NULL);
    return strncmp(s, prefix, strlen(prefix)) == 0;
}

bool
endswith(char *s, char *suffix)
{
    assert(s != NULL && suffix != NULL);
    return strncmp(s + strlen(s) - strlen(suffix), suffix, strlen(suffix)) == 0;
}

int
main(void)
{
    startswith("hello", "he") ? printf("yes\n") : printf("no\n");
    endswith("hello", "lo") ? printf("yes\n") : printf("no\n");

    startswith("hello", NULL);
    endswith("hello", NULL);

    return 0;
}
