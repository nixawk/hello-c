#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// void pthread_exit(void *retval);
// int pthread_join(pthread_t thread, void **retval);


void *
thr_fn1(void *arg)
{
    printf("thread 1 returning\n");
    return ((void *)1);
}


void *
thr_fn2(void *arg)
{
    printf("thread 2 exiting\n");
    pthread_exit((void *)2);
}


int
main(void)
{
    int err;
    pthread_t tid1, tid2;
    void *tret;

    err = pthread_create(&tid1, NULL, thr_fn1, NULL);
    if (err != 0)
    {
        fprintf(stderr, "pthread_create() failed to create thread 1.\n");
        exit(0);
    }

    err = pthread_create(&tid2, NULL, thr_fn2, NULL);
    if (err != 0)
    {
        fprintf(stderr, "pthread_create() failed to create thread 2.\n");
        exit(0);
    }

    err = pthread_join(tid1, &tret);
    if (err != 0)
    {
        fprintf(stderr, "pthread_join() failed to join with thread 1.\n");
        exit(0);
    }
    printf("thread 1 exit code %ld\n", (long)tret);

    err = pthread_join(tid2, &tret);
    if (err != 0)
    {
        fprintf(stderr, "pthread_join() failed to join with thread 12\n");
        exit(0);
    }
    printf("thread 1 exit code %ld\n", (long)tret);

    return 0;
}



// http://man7.org/linux/man-pages/man3/pthread_exit.3.html
// http://man7.org/linux/man-pages/man3/pthread_join.3.html