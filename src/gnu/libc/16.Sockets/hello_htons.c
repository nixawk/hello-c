#include <arpa/inet.h>
#include <stdio.h>

void
htons_demo(void)
{
    short int port = 80;
    printf("%d -> %#x\n", port, htons(port));
}

void
ntohs_demo(void)
{
    short int port = 0x5000;
    printf("%#x -> %d\n", port, ntohs(port));
}

int
main(void)
{
    htons_demo();
    ntohs_demo();
    return 0;
}

/*

$ ./a.out
80 -> 0x5000
0x5000 -> 80

*/

// http://man7.org/linux/man-pages/man3/htons.3.html