#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>

// strstr
// strcasestr
// strnstr

bool
in(s, substr)
    const char *s;
    const char *substr;
{
    return strstr(s, substr) != NULL;
}

int
main(void)
{
    in("hello", "ll") ? printf("yes\n") : printf("no\n");
    return 0;
}
