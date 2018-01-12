#ifndef __UNIX_DOMAIN__
#define __UNIX_DOMAIN__

#include <sys/socket.h>
#include <sys/un.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define UNIX_SOCK_FILE "/tmp/unix_domain_dgram.sock"

#ifndef BUF_SIZE
#define BUF_SIZE 4096
#endif

#endif