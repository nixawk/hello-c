#include <stdio.h>

// int puts (const char *s)

// The puts function writes the string s to the stream stdout followed by a newline.
// The terminating null character of the string is not written. (Note that fputs does
// not write a newline as this function does.)


void
puts_usage(void)
{
    char string[] = "hello, world\n";

    puts(string);
}


int
main(void)
{
    puts_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Simple-Output.html#Simple-Output