#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>


int
main(void)
{
    // syscall(__NR_getuid) is equivalent to getuid()
    printf("%ld\n", syscall(__NR_getuid));
    return 0;
}


// http://man7.org/linux/man-pages/man2/syscall.2.html
// https://www.win.tue.nl/~aeb/linux/lk/lk-3.html
