#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <arpa/inet.h>

#define MAXBUF   8192  /* Max I/O buffer size */


void
unix_error(char *msg)  /* Unix-style error */
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(0);
}


int
main(int argc, const char *argv[])
{
    struct in_addr inaddr;
    uint32_t addr;
    char buf[MAXBUF];

    if (argc != 2) {
        fprintf(stderr, "usage: %s <hex number>\n", argv[0]);
        exit(0);
    }

    sscanf(argv[1], "%x", &addr);
    inaddr.s_addr = htonl(addr);

    if (!inet_ntop(AF_INET, &inaddr, buf, MAXBUF)) {
        unix_error("inet_ntop");
    }

    printf("%s\n", buf);
    return 0;
}