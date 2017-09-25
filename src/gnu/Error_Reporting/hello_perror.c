#define _GNU_SOURCE

#include <stdio.h>
#include <errno.h>


// void perror (const char *message)

// Using [perror] has the advantage that the function is portable and
// available on all systems implementating ISO C. But often the text 
// perror generates is not what is wanted and there is no way to extend 
// or change what perror does. The GNU coding standard, for instance, 
// requires error messages to be preceded by the program name and programs 
// which read some input files should provide information about the input 
// file name and the line number in case an error is encountered while 
// reading the file. For these occasions there are two functions available 
// which are widely used throughout the GNU project. 

int
main(void)
{
    int c;

    for (c = 108; c > 0; c--)
    {
        errno = c;
        perror(NULL);
    }
}

// https://www.gnu.org/software/libc/manual/html_node/Error-Messages.html#Error-Messages