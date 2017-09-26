#include <unistd.h>
#include <stdio.h>

// char * getcwd (char *buffer, size_t size)

// The [getcwd] function returns an absolute file name representing the curent working
// directory, storing it in the character array [buffer] that you provide. The [size]
// argument is how you tell the system the allocation size of [buffer].

// The GNU C Library version of this function also permits you to specify a null pointer
// for the [buffer] argument. Then [getcwd] allocates a buffer automatically, as with
// malloc. If the [size] is greater than zero, then the buffer is that large; otherwise,
// the buffer is as large as necessary to hold the result.

// The return value is [buffer], and a null pointer on failure.

// char * getwd (char *buffer)          /* Deprecated Function */
// char * get_current_dir_name (void)

#define PATH_MAX        4096            /* #include <linux/limits.h> */


void
getcwd_usage(void)
{
    char path[PATH_MAX] = "";

    if (getcwd(path, PATH_MAX) == path)
    {
        printf("current directory: %s\n", path);
    } else {
        fprintf(stderr, "getcwd() failed.\n");
    }
}


int
main(void)
{
    getcwd_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Working-Directory.html#Working-Directory