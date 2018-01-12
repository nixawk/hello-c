#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>

void
gai_strerror_demo(void)
{
   printf("EAI_ADDRFAMILY - %s\n", gai_strerror(EAI_ADDRFAMILY));
   printf("EAI_AGAIN - %s\n", gai_strerror(EAI_AGAIN));
   printf("EAI_BADFLAGS - %s\n", gai_strerror(EAI_BADFLAGS));
   printf("EAI_FAIL - %s\n", gai_strerror(EAI_FAIL));
   printf("EAI_FAMILY - %s\n", gai_strerror(EAI_FAMILY));
   printf("EAI_MEMORY - %s\n", gai_strerror(EAI_MEMORY));
   printf("EAI_NODATA - %s\n", gai_strerror(EAI_NODATA));
   printf("EAI_NONAME - %s\n", gai_strerror(EAI_NONAME));
   printf("EAI_SERVICE - %s\n", gai_strerror(EAI_SERVICE));
   printf("EAI_SOCKTYPE - %s\n", gai_strerror(EAI_SOCKTYPE));
   printf("EAI_SYSTEM - %s\n", gai_strerror(EAI_SYSTEM));
}

int
main(void)
{
    gai_strerror_demo();
    return 0;
}

// http://man7.org/linux/man-pages/man3/gai_strerror.3.html