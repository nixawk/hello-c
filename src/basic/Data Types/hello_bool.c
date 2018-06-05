// The C99 standard for C language supports bool variables.
// Unlike C++, where no header file is needed to use bool,
// a header file "stdbool.h" must be included to use bool
// in C.

#include <stdio.h>
#include <stdbool.h>

void
bool_sizeof(void)
{
    printf("sizeof(bool) = %lu\n", sizeof(bool));
}

void
bool_true_or_false(void)
{
    bool bc = true;

    if (bc)
        printf("Condition is true\n");
    else
        printf("Condition is false\n");
}

int
main(void)
{
    bool_sizeof();
    bool_true_or_false();

    return 0;
}

// https://www.geeksforgeeks.org/bool-in-c/
// https://stackoverflow.com/questions/1921539/using-boolean-values-in-c
