#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

bool
startswith(s, prefix)
    char *s;
    char *prefix;
{
    assert(s != NULL && prefix != NULL);
    return strncmp(s, prefix, strlen(prefix)) == 0;
}

int
main(void)
{
    startswith("hello", "he") ? printf("yes\n") : printf("no\n");
    // startswith("hello", NULL);

    return 0;
}
