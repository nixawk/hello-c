#include <stdio.h>

// void flockfile (FILE *stream)

// The [flockfile] function acquires the internal locking object associated with
// the stream stream. This ensures that no other thread can explicitly through
// [flockfile/ftrylockfile] or implicitly through the call of a stream function
// lock the stream. The thread will block until the lock is acquired. An explicit
// call to funlockfile has to be used to release the lock.


// int ftrylockfile (FILE *stream)

// The [ftrylockfile] function tries to acquire the internal locking object associated
// with the stream just like [flockfile]. But unlike [flockfile] this function does not
// block if the lock is not available. [ftrylockfile] returns zero if the lock was
// successfully acquired. Otherwise the stream is locked by another thread.


// void funlockfile (FILE *stream)

// The [funlockfile] function releases the internal locking object of the stream.
// The stream must have been locked before by a call to [flockfile] or a successful
// call of [ftrylockfile]. The implicit locking performed by the stream operations
// do not count. The [funlockfile] function does not return an error status and the
// behavior of a call for a stream which is not locked by the current thread is
// undefined.


// int __fsetlocking (FILE *stream, int type)


void
flockfile_usage(FILE *fp)
{
    flockfile(fp);
    fputs("This is a flockfile test.\n", fp);
    funlockfile(fp);
}


int
main(void)
{
    FILE *fp;

    fp = fopen("/tmp/testfile", "w");
    if (fp != NULL)
    {
        flockfile_usage(fp);   /* pleaes try it in multi-threads modes */
        fclose(fp); 
    }

    return 0;
}

// https://www.gnu.org/software/libc/manual/html_node/Streams-and-Threads.html#Streams-and-Threads