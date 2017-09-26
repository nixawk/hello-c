#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


// FILE * fdopen (int filedes, const char *opentype)

// The [fdopen] function returns a new stream for the file descriptor [filedes].

// The [opentype] argument is interperted in the same way as for the [fopen] function,
// except that the ‘b’ option is not permitted; this is because GNU systems make no 
// distinction between text and binary files. Also, "w" and "w+" do not cause truncation 
// of the file; these have an effect only when opening a file, and in this case the 
// file has already been opened. You must make sure that the opentype argument matches 
// the actual mode of the open file descriptor.

// The return value is the new stream. If the stream cannot be created (for example, if
// the modes for the file indicated by the file descriptor do not permit the access
// specified by the [opentype] argument), a null pointer is returned instead.


// int fileno (FILE *stream)

// This function returns the file descriptor associated with the stream stream. 
// If an error is detected (for example, if the stream is not valid) or if stream 
// does not do I/O to a file, fileno returns -1.

void read_from_pipe(int);
void write_to_pipe(int);
void fdopen_usage(void);


void
read_from_pipe(int file)
{
    FILE *stream;
    int c;

    stream = fdopen(file, "r");
    while ((c = fgetc(stream)) != EOF)
    {
        putchar(c);
    }
    fclose(stream);
}


void
write_to_pipe(int file)
{
    FILE *stream;

    stream = fdopen(file, "w");
    fprintf(stream, "hello, world!\n");
    fprintf(stream, "goodbye, world!\n");
    fclose(stream);
}


void
fdopen_usage(void)
{
    pid_t pid;
    int mypipe[2];

    if (pipe(mypipe))     /* Create the pipe */
    {
        fprintf(stderr, "pipe() failed.\n");
        exit(EXIT_FAILURE);
    }

    pid = fork();          /* Create the child process */
    if (pid == (pid_t) 0)
    {
        close(mypipe[1]);  /* This is the child process, Close other end first. */
        read_from_pipe(mypipe[0]);
        exit(EXIT_SUCCESS);
    }
    else if (pid < (pid_t) 0)
    {
        fprintf(stderr, "fork() failed.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        close(mypipe[0]);
        write_to_pipe(mypipe[1]);
        exit(EXIT_SUCCESS);   
    }
}


int
main(void)
{
    fdopen_usage();
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Descriptors-and-Streams.html#Descriptors-and-Streams
// https://www.gnu.org/software/libc/manual/html_node/Creating-a-Pipe.html#Creating-a-Pipe