#include <strings.h>
#include <stdio.h>


#define BUFSIZE 512


    // void bcopy (const void *from, void *to, size_t size)

// This is a partially obsolete alternative for memmove, derived from BSD.
// Note that it is not quite equibalent to memmove, because the arguments
// are not in the same order and there is no return value.


    // void bzero (void *block, size_t size)

// This is a partially obsolete alternative for memset, derived from BSD.
// Note that it is not as general as memset, because the only value it can
// store is zero.


void
bcopy_usage(void)
{
    char src[BUFSIZE] = "hello, world";
    char dst[BUFSIZE];

    bzero(dst, BUFSIZE);
    bcopy(src, dst, strlen(src));

    printf("%s\n", dst);
}


int
main(void)
{
    bcopy_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Character-Handling