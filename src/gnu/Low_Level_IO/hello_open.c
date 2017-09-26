#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

// int open (const char *filename, int flags[, mode_t mode])
// int open64 (const char *filename, int flags[, mode_t mode])

// The [open] function creates and returns a new file descriptor for the file named by filename.
// Initially, the file position indicator for the file is at the beginning of the file.
// The argument [mode] is used only when a file is created, but it doesn't hurt to supply the
// argument in  any case.

// The [flags] argument controls how the file is to be opened. It must include one of the following
// access modes: [O_RDONLY], [O_WRONLY], or [O_RDWR]. This is a bit mask; you create the value by 
// the bitwise OR of the appropriate parameters (using the '|' operator in C).

    // File Access Modes
        // O_RDONLY   - Open the file for read access.
        // O_WRONLY   - Open the file for write access.
        // O_RDWR     - Open the file for both reading and writing.

        // O_READ     - Open the file for reading. Same as O_RDONLY; only defined on GNU.
        // O_WRITE    - Open the file for writing. Same as O_WRONLY; only defined on GNU.
        // O_EXEC     - Open the file for executing. Only defined on GNU.
        // O_ACCMODE  - This macro stands for a mask that can be bitwise-ANDed with the
                     // file status flag value to produce a value representing the file access mode.
                     // The mode will be O_RDONLY, O_WRONLY, or O_RDWR.

    // Open-time Flags
        // O_CREAT
        // O_EXCL
        // O_NONBLOCK
        // O_NOCTTY
        // O_IGNORE_CTTY
        // O_NOLINK
        // O_NOTRANS
        // O_TRUNC
        // O_SHLOCK
        // O_EXLOCK

    // Operating Modes
        // O_APPEND
        // O_NONBLOCK
        // O_NDELAY
        // O_ASYNC
        // O_FSYNC
        // O_SYNC
        // O_NOATIME 

    // File Status Flags
        // F_GETFL
        // F_SETFL

// The [mode] argument specifies the perissions to use in case a new file is created. It is modified
// by the process's umask in the usual way: the permissions of the the created file are [(mode & ~unmask)].

// The normal return value from [open] is a non-negative integer file descriptor. In the case of an error,
// a value of -1 is returned instead.


void
open_usage(void)
{
    int fd;

    fd = open("/tmp/testfile", O_RDONLY, S_IRWXU);  /* Linux System Call */
    if (fd != -1)
    {
        printf("open file descriptor: %d\n", fd);
        close(fd);
    }
}


int
main(void)
{
    open_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Opening-and-Closing-Files.html#Opening-and-Closing-Files
// https://www.gnu.org/software/libc/manual/html_node/Access-Modes.html#Access-Modes
// https://www.gnu.org/software/libc/manual/html_node/Open_002dtime-Flags.html#Open_002dtime-Flags
// https://www.gnu.org/software/libc/manual/html_node/Operating-Modes.html#Operating-Modes
// https://www.gnu.org/software/libc/manual/html_node/Getting-File-Status-Flags.html#Getting-File-Status-Flags
// https://stackoverflow.com/questions/596306/using-the-open-system-call
// https://stackoverflow.com/questions/2395465/create-a-file-in-linux-using-c
// http://www.tutorialspoint.com/unix_system_calls/open.htm