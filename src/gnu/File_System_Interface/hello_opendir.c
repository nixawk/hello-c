#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

// Data Type: DIR

// The DIR data type represents a directory stream.

    // typedef struct __dirstream DIR;

    // struct __dirstream
    //   {
    //     int fd;                     /* File descriptor.  */

    //     __libc_lock_define (, lock) /* Mutex lock for this structure.  */

    //     size_t allocation;          /* Space allocated for the block.  */
    //     size_t size;                /* Total valid data in the block.  */
    //     size_t offset;              /* Current offset into the block.  */

    //     off_t filepos;              /* Position of next entry to read.  */

    //     /* Directory block.  */
    //     char data[0] __attribute__ ((aligned (__alignof__ (void*))));
    //   };


// DIR * opendir (const char *dirname)

// The [opendir] function opens and returns a directory stream for reading
// the directory whose file name is [dirname].

// If unsuccessful, [opendir] returns a null pointer. In addition to the usual file name errors,
// the following [errno] error conditions are defined for this condition:

    // EACCESS
    // EMFILE
    // ENFILE
    // ENOMEM


// int closedir (DIR *dirstream)
// This function closes the directory stream [dirstream].
// It returns 0 on success and -1 on failure.


void
opendir_usage(void)
{
    char *dirpath = "/tmp/";
    DIR *dirstream;  /* DIR Structure details */

    dirstream = opendir(dirpath);
    if (dirstream == NULL)
    {
        fprintf(stderr, "opendir() failed: %s\n", strerror(errno));
    }

    printf("opendir() successfully - [%s]\n", dirpath);
    
    if (closedir(dirstream) == -1)
    {
        fprintf(stderr, "closedir() failedL %s\n", strerror(errno));
    }
}


int
main(void)
{
    opendir_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Opening-a-Directory.html#Opening-a-Directory
// http://man7.org/linux/man-pages/man3/readdir.3.html
// https://stackoverflow.com/questions/22122405/where-is-dir-defined
// https://stackoverflow.com/questions/16893895/what-is-dirstream-where-can-we-find-the-definition
// https://classes.soe.ucsc.edu/cmpe202/SimpleScalar/ssbig-na-sstrix/include/dirstream.h