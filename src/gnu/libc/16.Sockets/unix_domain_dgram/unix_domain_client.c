#include "unix_domain.h"

int
main(int argc, const char *argv[])
{
    struct sockaddr_un saddr, caddr;
    int sfd;
    char buf[] = "Hello, World";
    int buflen;
    ssize_t nrecv;

    sfd = socket(AF_UNIX, SOCK_DGRAM, 0);
    if (sfd == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&caddr, 0, sizeof(struct sockaddr_un));
    caddr.sun_family = AF_UNIX;
    strncpy(caddr.sun_path, "/tmp/unix_domain_client", sizeof(caddr.sun_path) - 1);

    if (remove(caddr.sun_path) == -1 && errno != ENOENT)
    {
        perror("remove");
        exit(EXIT_FAILURE);
    }

    if (bind(sfd, (struct sockaddr *) &caddr, sizeof(struct sockaddr_un) - 1) == -1)
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    memset(&saddr, 0, sizeof(struct sockaddr_un));
    saddr.sun_family = AF_UNIX;
    strncpy(saddr.sun_path, UNIX_SOCK_FILE, sizeof(saddr.sun_path) - 1);

    buflen = strlen(buf);

    if (sendto(sfd, buf, buflen, 0, (struct sockaddr *) &saddr, sizeof(struct sockaddr_un)) != buflen)
    {
        perror("sendto");
        exit(EXIT_FAILURE);
    }

    memset(buf, 0, buflen);

    nrecv = recvfrom(sfd, buf, buflen, 0, NULL, NULL);
    if (nrecv == -1)
    {
        perror("recvfrom");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", buf);

    if (close(sfd) == -1)
    {
        perror("close");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}
