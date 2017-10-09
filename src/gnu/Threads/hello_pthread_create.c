#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


// int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
//                    void *(*start_routine) (void *), void *arg);

// A successful call to [pthread_create()] stores  the ID of the new
// thread in the buffer pointed to by [thread]; this identifier is
// used to refer to the thread the thread in subsequent calls to other
// pthreads functions.

// The [attr] argument points to a [pthread_attr_t] structure whose
// contents are used at thread creation time to determine attributes
// for the new thread; this structure is initialized using
// [pthread_attr_init] and related functions. If [attr] is NULL, then
// the thread is created with default attributes.

// On success, [pthread_create()] returns 0; on error, it returns an
// error number, and the contents of [*thread] are undefined.

pthread_t ntid;


void
printids(const char *s)
{
    pid_t pid;
    pthread_t tid;

    pid = getpid();
    tid = pthread_self();
    printf("%s pid %lu tid %lu (0x%lx)\n", s,
        (unsigned long)pid,
        (unsigned long)tid,  (unsigned long)tid,  (unsigned long)tid);
}


void*
thread_func(void *arg)
{
    printids("new  thread:");
    return ((void *)0);
}


int
main(void)
{
    int err;

    err = pthread_create(&ntid, NULL, thread_func, NULL);
    if (err != 0)
    {
        fprintf(stderr, "pthread_create() failed.");
        exit(0);
    }

    printids("main thread:");
    sleep(1);
    return 0;
}


// http://man7.org/linux/man-pages/man3/pthread_create.3.html