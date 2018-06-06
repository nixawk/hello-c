// Symbolic Constants

/*

A #define line defines a symbolic name or symbolic constant to be a
particular string of characters;

    #define name replace text

Thereafter, any occurrence of name (not in quotes and not part of another
name) will be replaced by the corresponding replacement text. The name has
the same form as a variable name; a sequence of letters and digits that
begins with a letter. The replacement text can be any sequence of characters;
it is not limited to numbers.

Symbolic constant names are conventionally written in upper case so they
can be readily distinguished from lower case variable names.

*/

#include <stdio.h>

#define   LOWER  0     /* lower limit of table */
#define   UPPER  300   /* upper limit */
#define   STEP   20    /* step size */

int
main(void)
{
    int fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
    {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }

    return 0;
}

/*

code@lab:~/debug$ gcc -g3 -o define-constant define-constant.c 
code@lab:~/debug$ gdb -q ./define-constant 
Reading symbols from ./define-constant...done.
>>> list main
2   
3   #define max 65535
4   
5   int
6   main(void)
7   {
8       printf("max is %d\n", max);
9       return 0;
10  }
>>> macro list
>>> info macro max
Defined at /home/code/debug/define-constant.c:3
#define max 65535

*/