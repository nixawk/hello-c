// Logical operators

#include <stdio.h>
#include <stdbool.h>

void logical_operators(void)
{
    bool b1 = false;
    bool b2 = true;

    if (!b1)        /* Logical negation (NOT) */
        printf("b1 is false\n");

    if (!b1 && b2)
    // if (!b1 && b2)  /* Logical AND */
        printf("b1 is false, and b2 is true\n");

    if (b1 || b2)   /* Logical OR */
        printf("b1 is true, or b2 is true\n");
}

int main(void)
{
    logical_operators();
    return 0;
}

// https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B#Arithmetic_operators
