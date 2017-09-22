#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// char * strstr(const char *haystack, const char *needle);

// This is like [strchr], except that it searches haystack for a substring needle
// rather than just a single byte.
// It returns a pointer into the string haystack that is the first byte of the substring,
// or a null pointer if no match was found.

// char * index (const char *string, int c)
// char * rindex (const char *string, int c) 

// rindex is another name for [strrchr]; they are exactly the same.
// New code should always use [strrchr] since the name is defined in ISO C,
// while [index] is a BSD invention which never was available on System V derived systems.

void
strstr_usage(void)
{
    char haystack[] = "helloworld";
    char needle[] = "world";

    char *ptr = strstr(haystack, needle);
    if (ptr == NULL)
    {
        printf("strstr() failed \n");
        exit(0);
    }

    printf("%p - %s\n", ptr, ptr);
}


int
main(void) {
    strstr_usage();

    return 0;
}

