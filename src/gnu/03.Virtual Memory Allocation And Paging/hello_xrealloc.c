#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

// In most cases it makes no difference what happens to the original block 
// when realloc fails, because the application program cannot continue when 
// it is out of memory, and the only thing to do is to give a fatal error 
// message. Often it is convenient to write and use a subroutine, 
// conventionally called xrealloc, that takes care of the error message as 
// xmalloc does for malloc:


static void
fatal(char *fmt, ...)
{
    va_list list;

    va_start(list, fmt);
    vfprintf(stderr, fmt, list);
    va_end(list);

    exit(1);
}


void *
xrealloc (void *ptr, size_t size)
{
    void *value = realloc (ptr, size);
    if (value == 0)
        fatal ("Virtual memory exhausted");
    return value;
}


int
main(void)
{
    char *ptr = NULL;

    xrealloc(ptr, 32);
    free(ptr);

    return 0;
}


// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Malloc-Examples