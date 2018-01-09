// A common use of pipes is to send data to or receive data from a program
// being run as a subprocess. One way of doing this is by using a combination
// of pipe (to create the pipe), fork (to create the subprocess), dup2 (to
// force the subrocess to use the pipe as its standard input or output channel
// ), and exec (to execute the new program). Or, you can use popen and pclose

// The advantage of using popen and pclose is that the interface is much
// simpler and easier to use. But it doesn't offer as much flexibility
// as using the low-level functions directly.


    // FILE * popen(const char *command, const char *mode)

// The popen function is closely related to the system function. It executes
// the shell command as a subprocess. However, instead of waiting for the
// command to complete, it creates a pipe to the subprocess and returns a
// stream that cprresponds to that pipe.

// If you specify a mode argument of "r", you can read from the stream to
// retrieve data from the standard output channel of the subprocess.
// The subprocess inherits its standard input channel from the parent process.

// Similarly, if you specify a mode argument of "w", you can write to the
// stream to send data to the standard output channel of the subprocess.
// The subprocess inherits its standard output channel from the parent process.

// In the event of an error popen returns a null pointer. This might happen
// if the pipe or stream cannot be created, if the subprocess cannot be forked,
// or if the program cannot be executed.


    // int pclose(FILE *stream)

// The pclose function is used to close a stream created by popen. It waits
// for the child process to terminate and returns its status value, as for
// the system function.

#include <stdio.h>
#include <stdlib.h>


void
write_data(FILE *stream)
{
    int i;
    for (i = 0; i < 100; i++)
    {
        fprintf(stream, "%d\n", i);
    }

    if (ferror(stream))
    {
        fprintf(stderr, "Output to stream failed.\n");
        exit(EXIT_FAILURE);
    }
}


int
main(void)
{
    FILE *output;

    output = popen("more", "w");
    if (!output)
    {
        fprintf(stderr, "incorrect parameters or too many files.\n");
        return EXIT_FAILURE;
    }

    write_data(output);

    if (pclose(output) != 0)
    {
        fprintf(stderr, "Could not run more or other error.\n");
    }

    return EXIT_SUCCESS;
}


// https://www.gnu.org/software/libc/manual/html_node/Pipe-to-a-Subprocess.html#Pipe-to-a-Subprocess