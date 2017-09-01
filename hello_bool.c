#include <stdio.h>
#include <stdbool.h>

bool
is_true(void)
{
    return true;
}

bool
is_false(void)
{
    return false;
}

int
main(void)
{
    if (is_true())
        printf("condition is true.\n");

    if (!is_false())
        printf("condition is false.\n");

    return 0;
}