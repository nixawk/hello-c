#include <stdio.h>

/*
    Function declaration tells compiler about number of parameters functions takes, date-types
    of parameters and return type of function.
*/

/*
    It is always recommended to declare a function before it is used.
*/
int add_by_value(int, int);
int add_by_refer(int *, int *);

/*
    Pass by Value:
        In this parameter passing method, values of actual parameters are copied to function's
        formal parameter and two types of parameters are stored in different memory locations.
        So any changes made inside functions are not reflected in actual parameters of caller.

    Pass by Reference:
        Both actual and formal parameters refer to same locations, so any changes made inside
        the function are actually reflected in actual parameters of caller.
*/
int add_by_value(int x, int y)
{
    return x + y;
}

int add_by_refer(int *x, int *y)
{
    *x = 11;
    *y = 22;
    return *x + *y;
}

int main(void)
{
    /*
        The parameters passed to function are called (actual parameters). Ex: 10, 20
        The parameters received by function are called formal parameters.
    */

    int x = 10, y = 20, z;

    z = add_by_value(x, y);
    printf("%d + %d = %d\n", x, y, z);

    z = add_by_refer(&x, &y);
    printf("%d + %d = %d\n", x, y, z);

    return 0;
}
