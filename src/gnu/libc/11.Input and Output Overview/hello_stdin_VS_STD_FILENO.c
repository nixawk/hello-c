#include <unistd.h>
#include <stdio.h>
#include <limits.h>

// stdin (_IO_FILE defined in /usr/include/libio.h) is a structure data. 
// STDIN_FILENO is a macro constant, which points to a file descriptor used by kernel.

// -> /usr/include/stdio.h
// /* Standard streams.  */
// extern struct _IO_FILE *stdin;          /* Standard input stream.  */
// extern struct _IO_FILE *stdout;         /* Standard output stream.  */
// extern struct _IO_FILE *stderr;         /* Standard error output stream.  */
// /* C89/C99 say they're macros.  Make them happy.  */
// #define stdin stdin
// #define stdout stdout
// #define stderr stderr


// -> /usr/include/unistd.h
// /* Standard file descriptors.  */
// #define STDIN_FILENO    0       /* Standard input.  */
// #define STDOUT_FILENO   1       /* Standard output.  */
// #define STDERR_FILENO   2       /* Standard error output.  */


void
stdin_VS_STDIN_FILENO(void)
{
    printf("stdin->_flags = %hd\n", stdin->_flags);
    printf("STDIN_FILENO  = %d\n", STDIN_FILENO);
}


void
file_descriptor_MAX(void)
{
    printf("OPEN_MAX  : %d\n", OPEN_MAX);
}


int
main(void)
{
    stdin_VS_STDIN_FILENO();
    file_descriptor_MAX();
    return 0;
}


// http://man7.org/linux/man-pages/man3/stdin.3.html
// http://pubs.opengroup.org/onlinepubs/009695399/functions/stdin.html
// https://stackoverflow.com/questions/15102992/what-is-the-difference-between-stdin-and-stdin-fileno