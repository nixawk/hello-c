#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>


// int socket (int namespace, int style, int protocol)

// This function creates a socket and specifies communication style [style],
// which should be one of the socket styles listed in [Communication Styles].

// The [namespace] argument specifies the namespace; it must be [PF_LOCAL]
// (see [Local Namespace]) or PF_INET (see [Internet Namespace]).

// [protocol] designates the specific protocol (see [Socket Concepts]);
// zero is usually right for protocol.

// The return value from [socket] is the file descriptor for the new socket,
// or -1 in case of error.

void
socket_usage(void)
{
    int sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock < 0)
    {
        fprintf(stderr, "socket() failed: %s\n.", strerror(errno));
    }
    printf("create a new socket\n");
    
    // When you have finished using a socket, you can simply close its file descriptor with close;
    close(sock);
}


int
main(void)
{
    socket_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Communication-Styles.html#Communication-Styles
// https://www.gnu.org/software/libc/manual/html_node/Internet-Namespace.html#Internet-Namespace
// https://www.gnu.org/software/libc/manual/html_node/Socket-Concepts.html#Socket-Concepts
// https://www.ibm.com/developerworks/linux/tutorials/l-sock/l-sock-pdf.pdf
// https://www.gnu.org/software/libc/manual/html_node/Closing-a-Socket.html#Closing-a-Socket
// https://stackoverflow.com/questions/4160347/close-vs-shutdown-socket
