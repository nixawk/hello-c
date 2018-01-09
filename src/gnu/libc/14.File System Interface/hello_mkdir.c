#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// int mkdir (const char *filename, mode_t mode)

// The [mkdir] function creates a new, empty directory with name filename.
// The argument [mode] specifies the file permissions fot the directory file.

// A return value of 0 indicates successful completion, and -1 indicates failure.

void
mkdir_usage(void)
{
    if (0 != mkdir("/tmp/newdir", S_IRWXU))
    {
        fprintf(stderr, "mkdir() failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    printf("mkdir() a new directory: newdir\n");
}


int
main(void)
{
    mkdir_usage();
    return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Creating-Directories.html#Creating-Directories
// https://www.gnu.org/software/libc/manual/html_node/Permission-Bits.html#Permission-Bits