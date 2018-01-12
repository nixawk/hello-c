#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>

// struct sockaddr_in {
//    sa_family_t    sin_family; /* address family: AF_INET */
//    in_port_t      sin_port;   /* port in network byte order */
//    struct in_addr sin_addr;   /* internet address */
// };

// /* Internet address. */
// struct in_addr {
//    uint32_t       s_addr;     /* address in network byte order */
// };


/* convert IPv4 and IPv6 addresses from text to binary form. */

void
inet_pton_demo(void)
{
    char src[] = "8.8.8.8";
    struct in_addr dst;    /* dst is a stucture, and not an integer here */

    if (inet_pton(AF_INET, src, (void *)&dst) != 1)
    {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }
    
    printf("IP: %s -> %#x\n", src, dst.s_addr);
}

/* convert IPv4 and IPv6 addresses from binary to text */

void
inet_ntop_demo(void)
{
    struct in_addr src;
    char buf[256];

    src.s_addr = 0x8080808;

    if (inet_ntop(AF_INET, (void *) &src, buf, 256) == NULL)
    {
        perror("inet_ntop");
        exit(EXIT_FAILURE);
    }

    printf("IP: %#x -> %s", src.s_addr, buf);
}


int
main(void)
{
    inet_pton_demo();
    inet_ntop_demo();
    return 0;
}

/*

$ ./a.out
IP: 8.8.8.8 -> 0x8080808
IP: 0x8080808 -> 8.8.8.8

*/

// http://man7.org/linux/man-pages/man3/inet_pton.3.html
// http://man7.org/linux/man-pages/man7/ip.7.html