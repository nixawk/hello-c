#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function: void flockfile (FILE *stream)
// Function: int ftrylockfile (FILE *stream)
// Function: void funlockfile (FILE *stream)
// Function: int __fsetlocking (FILE *stream, int type)

void *
thread_func(void *argc)
{
    FILE *s = (FILE *) argc;

    flockfile(s);

    printf("threadid: %ld\n", (long) pthread_self());

    funlockfile(s);

    pthread_exit((void *) 1);
}


int
main(int argc, char *argv[])
{
    pthread_t thread1, thread2;
    FILE *s;

    if (argc != 2)
    {
        printf("[*] Usage: %s <file>", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* redirect stdout output to file */

    s = freopen(argv[1], "w", stdout);
    if (s == NULL)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    /* multi threads */

    if (pthread_create(&thread1, NULL, thread_func, (void *) s) != 0)
    {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&thread2, NULL, thread_func, (void *) s) != 0)
    {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    if (pthread_join(thread1, NULL) != 0)
    {
        perror("pthread_join");
        exit(EXIT_FAILURE);
    }

    if (pthread_join(thread2, NULL) != 0)
    {
        perror("pthread_join");
        exit(EXIT_FAILURE);
    }

    /* close FILE stream, and avoid memory leak */

    if (fclose(s) != 0)
    {
        perror("fclose");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);

}


// https://www.gnu.org/software/libc/manual/html_node/Streams-and-Threads.html#Streams-and-Threads
// http://man7.org/linux/man-pages/man3/flockfile.3.html