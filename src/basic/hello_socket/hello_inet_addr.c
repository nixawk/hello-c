#include <arpa/inet.h>
#include <stdio.h>


// in_addr_t - An unsigned integral type of exactly 32 bits.

void
inet_addr_usage(void)
{
    char *ip = "192.168.1.100";
    in_addr_t addr = inet_addr(ip);

    printf("%x\n", addr); // 6401a8c0
}


int
main(void)
{
    inet_addr_usage();
    return 0;
}

/*

$ gcc hello_inet_addr.c -o hello_inet_addr
$ ./hello_inet_addr
6401a8c0

*/

// http://pubs.opengroup.org/onlinepubs/7908799/xns/netinetin.h.html
// http://www.cplusplus.com/forum/general/80191/