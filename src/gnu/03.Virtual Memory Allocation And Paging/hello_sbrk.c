#include <unistd.h>
#include <stdio.h>

    // void *sbrk (ptrdiff_t delta)

// This function is the same as [brk] except that you specify the new end of
// the data segment as an offset delta from the current end and on success
// the return value is the address of the resulting end of the data segment
// instead of zero.

// This means you can use 'sbrk(0)' to find out what the current end of the
// data segment is.

void
sbrk_usage(void)
{
    printf("The end of data segment: %p\n", sbrk(0));
}


int
main(void)
{
    sbrk_usage();
    return 0;
}


/*
$ ./hello_sbrk 
The end of data segment: 0x5637edb33000
*/

// https://www.gnu.org/software/libc/manual/html_node/Resizing-the-Data-Segment.html#Resizing-the-Data-Segment