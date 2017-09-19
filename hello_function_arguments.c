#include <stdio.h>
#include <stdarg.h>

/*

#include <stdarg.h>
void va_start(va_list ap, last); 
type va_arg(va_list ap, type); 
void va_end(va_list ap); 
void va_copy(va_list dest, va_list src);

*/

int
min(int x, int y)
{
    return x <= y ? x : y;
}

int
min_args(int argc, ...)
{
    int i;
    int tv, mv; // tempval: tv, minval: mv

    /* va_list is a type to hold information about variable arguments */
    va_list ap;

    /* va_start must be called before accessing avriable argument list */
    va_start(ap, argc);

    for (i = 0; i < argc; i++)
    {
        /* Now arguments can be accessed one by one using va_arg macro */
        tv = va_arg(ap, int);
        mv = (i == 0) ? tv : min(mv, tv);
        // if (i == 0)
        // {
        //     mv = tv;
        // } else {
        //     mv = min(mv, tv);
        // }
    }

    /* va_end should be executed before the function returns whenever 
       va_start has been previously used in that function. */
    va_end(ap);

    return mv;
}


int
main(int argc, const char *argv[])
{
   int mv = min_args(4, 10, 20, 30, 40);
   printf("min numval: %d\n", mv);

    return 0;
}

// https://www.systutorials.com/docs/linux/man/3-va_start/