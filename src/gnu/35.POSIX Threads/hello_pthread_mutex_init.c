#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void
pthread_mutex_init_usage(void)
{
    pthread_mutex_t mutex;
    pthread_mutexattr_t attr;

    if (pthread_mutexattr_init(&attr) != 0)
    {
        perror("pthread_mutexattr_init");
        exit(EXIT_FAILURE);
    }

    if (pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK) != 0)
    {
        perror("pthread_mutexattr_settype");
        exit(EXIT_FAILURE);
    }

    if (pthread_mutex_init(&mutex, &attr) != 0)
    {
        perror("pthread_mutex_init");
        exit(EXIT_FAILURE);
    }

    if (pthread_mutex_destroy(&mutex) != 0)
    {
        perror("pthread_mutex_destroy");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}


int
main(void)
{
    pthread_mutex_init_usage();
    return 0;
}


// http://man7.org/linux/man-pages/man3/pthread_mutex_init.3p.html
// http://man7.org/linux/man-pages/man3/pthread_mutexattr_init.3p.html
// http://man7.org/linux/man-pages/man3/pthread_mutexattr_settype.3p.html
// http://man7.org/linux/man-pages/man3/pthread_mutex_destroy.3p.html