#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

/*

struct in_addr {
    in_addr_t s_addr;         // 32-bit IPv4 address
                              // network byte ordered
}


struct sockaddr_in {
    uint8_t        sin_len;        // length of structure (16)
    sa_family_t    sin_family;     // AF_INET
    in_port_t      sin_port;       // 16-bit TCP or UDP port number
                                   // network byte ordered
    struct in_addr sin_addr;       // 32-bit IPv4 address
                                   // network byte ordered
    char           sin_zero[8];    // unused
}

*/

int
main(int argc, const char *argv[])
{
    if (argc != 2)
    {
        printf("[*] Usage: %s <host>\n", argv[0]);
        exit(EXIT_FAILURE);
    }


    // What's the differences ?
    // sockaddr_in / in_addr / in_addr_t

    // struct sockaddr_in addr;
    // inet_aton(argv[1], &addr.sin_addr);

    struct in_addr in_addr1;
    if (inet_aton(argv[1], &in_addr1) != 1)
    {
        perror("inet_aton");
        exit(EXIT_FAILURE);
    }

    // in_addr_t in_addr_t1;
    // in_addr_t1 = inet_addr(argv[1]);  // Not recommended

    printf("[*] %s -> inet_aton -> struct in_addr\n", argv[1]);
    printf("[*] struct in_addr -> inet_ntoa -> %s\n", inet_ntoa(in_addr1));

    exit(EXIT_SUCCESS);
}
