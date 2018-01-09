#include <pthread.h>
#include <stdio.h>
#include <string.h>
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


/* job for every thread */

static void *
thread_job(void *arg)
{
    char *s = (char *) arg;

    printf("%s\n", s);

    return (void *) strlen(s);
}

int
main(void)
{
    pthread_t thread;
    void *retval;

    if ((pthread_create(&thread, NULL, thread_job, "Hello, World\n")) != 0)
    {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    printf("Message from main()\n");

    if ((pthread_join(thread, &retval)) != 0)
    {
        perror("pthread_join");
        exit(EXIT_FAILURE);
    }

    printf("Thread returned: %ld\n", (long) retval);

    exit(EXIT_SUCCESS);
}


/*

$ gcc -pthread hello_pthread_create.c
$ ./a.out
Message from main()
Hello, World

Thread returned: 13

*/

// http://man7.org/linux/man-pages/man3/pthread_create.3.html