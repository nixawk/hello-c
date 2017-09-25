#include <string.h>
#include <stdlib.h>
#include <stdio.h>


// char * strtok(char *restrict str, const char *restrict sep);
// wchar_t * wcstok (wchar_t *newstring, const wchar_t *delimiters, wchar_t **save_ptr)
// char * strtok_r (char *newstring, const char *delimiters, char **save_ptr)


// A string can be split into tokens by making a series of calls to the function [strtok]

// The string to be split up is passed as the [newstring] argument on the first call only.
// The strtok function uses this to set up some internal state information.

// Subsequent calls to get additional tokens from the same string are indicated by passing
// a null pointer as the [newstring] argument.

// Calling [strtok] with another non-null [newstring] argument reinitializes the state
// information.


void
strtok_usage(void)
{
    const char string[] = "words separated by spaces -- and, punctutation!";
    const char delimiters[] = " .,;:!-";
    char *token, *cp;

    cp = strdup(string);              /* make writable copy. */
    if (cp == NULL)
    {
        fprintf(stderr, "strdup() failed \n");
        exit(0);
    }

    token = strtok(cp, delimiters);    /* token => "words" ... */
    while (token)
    {
        printf("token : %s\n", token);
        token = strtok(NULL, delimiters);
    }

    free(cp);                         /* cleanup, no leak */
}


int
main(void) {
    strtok_usage();

    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Finding-Tokens-in-a-String.html#Finding-Tokens-in-a-String