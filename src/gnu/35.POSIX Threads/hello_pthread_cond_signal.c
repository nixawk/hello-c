#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>


static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

static int avail = 0;

typedef enum { FALSE, TRUE } bool;


void *
thread_job(void *arg)
{
    int cnt = atoi((char *) arg);
    int s, j;

    for (j = 0; j < cnt; j++)
    {
        sleep(1);

        /* Code to produce a unit omitted */
        if (pthread_mutex_lock(&mutex) != 0)
        {
            perror("pthread_mutex_lock");
            exit(EXIT_FAILURE);
        }

        avail++;

        if (pthread_mutex_unlock(&mutex) != 0)
        {
            perror("pthread_mutex_unlock");
            exit(EXIT_FAILURE);
        }

        if (pthread_cond_signal(&cond) != 0)
        {
            perror("pthread_cond_signal");
            exit(EXIT_FAILURE);
        }
    }

    exit(EXIT_SUCCESS);
}

int
main(int argc, char *argv[])
{
    pthread_t thread;
    int s, j;
    int totRequired;   /* Total number of units that all threads
                          will produce */
    int numConsumed;   /* Total units so far consumed */
    time_t t;
    bool done;

    if (argc < 2)
    {
        printf("[*] Usage: %s <threads-num>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    t = time(NULL);

    /* Create all threads */

#ifdef DEBUG
    printf("main - pthread_create start\n");
#endif

    totRequired = 0;
    for (j = 1; j < argc; j++)
    {
        totRequired += atoi(argv[j]);

        if (pthread_create(&thread, NULL, thread_job, argv[j]) != 0)
        {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

#ifdef DEBUG
    printf("main - pthread_create finished\n");
#endif

    /* Loop to consume available units */
    numConsumed = 0;
    done = FALSE;

    for (;;)
    {

#ifdef DEBUG
    printf("main - pthread_mutex_lock start\n");
#endif
        if (pthread_mutex_lock(&mutex) != 0)
        {
            perror("pthread_mutex_lock");
            exit(EXIT_FAILURE);
        }

#ifdef DEBUG
    printf("main - pthread_mutex_lock end\n");
#endif


#ifdef DEBUG
    printf("main - pthread_cond_wait start\n");
#endif
        while (avail == 0)  /* Wait for something to consume */
        {
            if (pthread_cond_wait(&cond, &mutex) != 0)
            {
                perror("pthread_cond_wait");
                exit(EXIT_FAILURE);
            }
        }

#ifdef DEBUG
    printf("main - pthread_cond_wait end\n");
#endif

        while (avail > 0)
        {
            numConsumed++;
            avail--;
            printf("T=%ld: numConsumed=%d\n", (long)(time(NULL) - t), numConsumed);
            done = (numConsumed >= totRequired);
        }

#ifdef DEBUG
    printf("main - pthread_mutex_unlock start\n");
#endif

        if (pthread_mutex_unlock(&mutex))
        {
            perror("pthread_mutex_lock");
            exit(EXIT_FAILURE);
        }

#ifdef DEBUG
    printf("main - pthread_mutex_unlock end\n");
#endif

        if (done)
            break;
    }

    exit(EXIT_SUCCESS);
}

/*

$ ./a.out 3
T=1: numConsumed=1
T=2: numConsumed=2
T=3: numConsumed=3

$ ./a.out 3 4
T=1: numConsumed=1
T=1: numConsumed=2
T=2: numConsumed=3
T=2: numConsumed=4
T=3: numConsumed=5
T=3: numConsumed=6

*/


// http://man7.org/tlpi/code/online/dist/threads/prod_condvar.c.html
