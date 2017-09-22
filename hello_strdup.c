#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// char * strdup (const char *s)
// wchar_t * wcsdup (const wchar_t *ws)
// char * strdupa (const char *s)        // allocates the new string using [alloca] instead of [malloc]

// This function copies the string s into a newly allocated string.
// The string is allocated using malloc; see Unconstrained Allocation.
// If malloc cannot allocate space for the new string, strdup returns a null pointer.
// Otherwise it returns a pointer to the new string.


void
strdup_usage(void)
{
    char string[] = "hello, world";
    char *pstr = NULL;

    pstr = strdup(string);
    if (pstr == NULL)
    {
        fprintf(stderr, "strdup() failed \n");
        exit(0);
    }

    printf("%s\n", pstr);  /* heap buffer */
    free(pstr);
}


int
main(void)
{
    strdup_usage();

    return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Copying-Strings-and-Arrays.html#Copying-Strings-and-Arrays