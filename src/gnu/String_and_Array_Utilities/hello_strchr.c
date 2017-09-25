#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// char * strchr(const char *s, int c);
// char * strrchr(const char *s, int c);

// The strchr function finds the first occurrence of the byte c (converted to a char)
// in the string beginning at string.
// The return value is a pointer to the located byte, or a null pointer if no match was found.

// char * strstr(const char *haystack, const char *needle);

// char * index (const char *string, int c)
// char * rindex (const char *string, int c) 

// index is another name for [strchr]; they are exactly the same.
// New code should always use [strchr] since the name is defined in ISO C,
// while [index] is a BSD invention which never was available on System V derived systems.


void
strchr_usage(void)
{
    char s[] = "helloworld";
    int c = 'l';

    char *ptr = strchr(s, c);
    if (ptr == NULL)
    {
        printf("strchr() failed \n");
        exit(0);
    }

    printf("%p - %s\n", ptr, ptr);
}

int main(void)
{
    strchr_usage();

    return 0;
}
