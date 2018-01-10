#define _GNU_SOURCE
#include <stdio.h>


void
fcloseall_usage(void)
{
    if (fcloseall() == 0)
    {
        printf("all files were successfully closed.\n");
    }
    else
    {
        printf("all files were failed to close.\n");
    }
}


int
main(void)
{
    fcloseall_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Closing-Streams.html#Closing-Streams
// http://man7.org/linux/man-pages/man3/fcloseall.3.html