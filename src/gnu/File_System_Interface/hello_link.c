#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

// In POSIX systems, one file can have many names at the same time. All of the names
// are equally real, and no one of them is preferred to the others.
// To add a name to a file, use the [link] function. (The new name is also called a
// hard link to the file.) Creating a new link to a file does not copy the contents
// of the file; it simply makes a new name by which the file can be known, in addition
// to the file's existing name or names.

// int link (const char *oldname, const char *newname)
// int unlink(const char *path);

// This function returns a value of 0 if it is successful and -1 on failure.
// In addition to the usual file name errors for both oldname and newname,
// the following [errno] error conditions are defined for this function:

    // EACCESS
    // EEXIST
    // EMLINK
    // ENOENT
    // ENOSPC
    // EPERM
    // EROFS
    // EXDEV
    // EIO

#define OLDNAME "/tmp/oldfile"
#define NEWFILE "/tmp/newfile"


void
link_usage(void)
{
    if (link(OLDNAME, NEWFILE) != 0)
    {
        fprintf(stderr, "link() failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    printf("link() successful: %s\n", NEWFILE);
}


void
unlink_usage(void)
{
    if (unlink(OLDNAME) != 0)
    {
        fprintf(stderr, "unlink() failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    printf("unlink() successful: %s\n", OLDNAME);
}

int
main(void)
{
    link_usage();
    unlink_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Hard-Links.html#Hard-Links
// https://linux.die.net/man/3/link