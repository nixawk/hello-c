#include <stdio.h>

int
main(void)
{
#if VERBOSE >= 2
    printf("Trace Message");
    return 0;
#endif
}

/*
$ gcc -DVERBOSE=3 -o define-macro-if-else define-macro-if-else.c
*/