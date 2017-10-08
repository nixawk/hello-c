#include <stdio.h>


size_t mystrlen(const char *);
void myexchange(char *, char *);
void myreverse(char *);


size_t
mystrlen(const char *str)
{
    register const char *s;   // Registers are faster than memory to access.

    for (s = str; *s; ++s);
    return (size_t)(s - str);
}

// size_t
// mystrlen(const char *str)
// {
//     size_t i;

//     for (i = 0; str[i]; i++);
//     return i;
// }

// size_t mystrlen(const char *s) {
//   const char *eos = s;
//   while (*eos++);
//   return (int) (eos - s - 1);
// }


void
myexchange(char *x, char *y)
{
    *x ^= *y;                 // csapp.3e
    *y ^= *x;
    *x ^= *y;
}


void
myreverse(char *str)
{
    size_t length, i;

    for (i = 0, length = mystrlen(str); i < (length / 2); i++)
    {
        myexchange(&str[i], &str[length - 1 - i]);
    }
}


int
main(void)
{
    /*
     * Exception: char *str = "hello,world";
     * [str] must be writable. */
    char str[] = "hello,world";

    printf("%s\n", str);
    myreverse(str);
    printf("%s\n", str);

    return 0;
}


// https://opensource.apple.com/source/Libc/Libc-167/gen.subproj/i386.subproj/strlen.c
// http://www.geeksforgeeks.org/understanding-register-keyword/
// http://www.jbox.dk/sanos/source/lib/string.c.html