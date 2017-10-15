#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

// mode_t umask (mode_t mask)

// The [umask] function sets the file creation mask of the current process
// to mask, and returns the previous value of the file creation mask.


// mode_t getumask (void)

// Return the current value of the file creation mask for the current process.
// This function is a GNU extension and is only available on GNU/Hurd systems.

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)
#define UMASK (S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

void
umask_usage(void)
{
    umask(0);
    if (creat("umask_xxx", RWRWRW) < 0)
    {
        fprintf(stderr, "creat() failed: %s\n", strerror(errno));
        exit(1);
    }

    umask(UMASK);
    if (creat("umask_yyy", RWRWRW) < 0)
    {
        fprintf(stderr, "creat() failed: %s\n", strerror(errno));
        exit(1);
    }

    system("ls -l umask_xxx umask_yyy");  // view file attributes
}


int
main(void)
{
    umask_usage();
    return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Setting-Permissions.html