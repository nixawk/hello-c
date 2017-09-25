#include <assert.h>
#include <stdio.h>

/*
The assert.h header file of the C standard Library provides a macro called assert which can be used to verify assumptions made by the program and print a diagnostic message if this assumptions is false.

The defined macro assert refers to another macro NDEBUG which is not a part of <assert.h>. If NDEBUG is defined as a macro name in the source file, at the point where <assert.h> is included, the assert macro is defined as follows.
*/

void demo_assert(int i)
{
    assert (i == 2);
    printf("Number is : %d\n", i);
}


int main(void)
{
    int i;

    printf("Pleae enter a number: ");
    scanf("%d", &i);
    demo_assert(i);
}

// Assertion failed: (i == 2), function demo_assert, file hello-assert.c, line 12.
