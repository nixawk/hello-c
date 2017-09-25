#include <stdio.h>


// int fputs (const char *s, FILE *stream)

// The function [fputs] writes the string s to the stream, The terminating null
// character is not written. This function does not add a newline character, either.
// It outputs only the characters in the string. This function returns EOF if a
// write error occurs, and otherwise a non-negative value.


// int fputs_unlocked (const char *s, FILE *stream)

// The fputs_unlocked function is equivalent to the fputs function except that it
// does not implicitly lock the stream.


void
fputs_usage(void)
{
    char string[] = "hello, world\n";

    fputs(string, stdout);
}


int
main(void)
{
    fputs_usage();
    return 0;
}