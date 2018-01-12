#include "unix_domain.h"

#define BACKLOG 5

int
main(int argc, const char *argv[])
{
    struct sockaddr_un addr;   /* unix sockaddr_un */
    int sfd, cfd;              /* server and client file descriptor */
    ssize_t nread;             /* count of read */
    char buf[BUF_SIZE];        /* buffer */

    sfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sfd == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    /* construct server socket address, bind socket to it, 
       and make this a listening socket */

    if (remove(UNIX_SOCK_FILE) == -1 && errno != ENOENT)
    {
        perror("remove");
        exit(EXIT_FAILURE);
    }

    memset(&addr, 0, sizeof(struct sockaddr_un));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, UNIX_SOCK_FILE, sizeof(addr.sun_path) - 1);

    if (bind(sfd, (struct sockaddr *)&addr, sizeof(struct sockaddr_un)) == -1)
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(sfd, BACKLOG) == -1)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    for (;;)   /* Handle client connections iteratively */
    {
        /* Accept a connection. The connection is returned on a new
           socket, 'cfd'; the listening socket ('sfd') remains open
           and can be used to accept further connections. */

        cfd = accept(sfd, NULL, NULL);
        if (cfd == -1)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        /* Transfer data from connected socket to stdout unilt EOF */

        while ((nread = read(cfd, buf, BUF_SIZE)) > 0)
        {
            if (write(STDOUT_FILENO, buf, nread) != nread)
            {
                perror("read");
                exit(EXIT_FAILURE);
            }
        }

        if (nread == -1)
        {
            perror("read");
            exit(EXIT_FAILURE);
        }

        if (close(cfd) == -1)
        {
            perror("close");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}