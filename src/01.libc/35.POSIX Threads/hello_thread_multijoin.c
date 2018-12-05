#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

static int totThreads = 0;	/* Total number of threads created */
static int numLive = 0;		/* Total number of threads still alive or
				   terminated but not yet joined */
static int numUnjoined = 0;	/* Number of terminated threads that
				   have not yet been joined */

enum tstate {			/* Thread states */
	TS_ALIVE,		/* Thread is alive */
	TS_TERMINATED,		/* Thread terminated, not yet joined */
	TS_JOINED		/* Thread terminated, and joined */
};

static struct {			/* Info about each thread */
	pthread_t tid;		/* ID of this thread */
	enum tstate state;	/* Thread state (TS_* constants above) */
	int sleepTime;		/* Number seconds to live before terminating */
} *thread;

static void *			/* Start function for thread */
thread_job(void *arg)
{
	int idx = (int)arg;
	int s;

	int t = thread[idx].sleepTime;
	sleep(t);		/* Simulate doing some work */
	printf("Thread %d terminating\n", idx);

	if (pthread_mutex_lock(&mutex) != 0) {
		perror("pthread_mutex_lock");
		exit(EXIT_FAILURE);
	}

	numUnjoined++;
	thread[idx].state = TS_TERMINATED;

	if (pthread_mutex_unlock(&mutex) != 0) {
		perror("pthread_mutex_unlock");
		exit(EXIT_FAILURE);
	}

	if (pthread_cond_signal(&cond) != 0) {
		perror("pthread_cond_signal");
		exit(EXIT_FAILURE);
	}

	return NULL;
}

int main(int argc, char *argv[])
{
	int s, idx;

	if (argc < 2) {
		printf("[*] Usage: %s nsecs...", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((thread = calloc(argc - 1, sizeof(*thread))) == NULL) {
		perror("calloc");
		exit(EXIT_FAILURE);
	}

	for (idx = 0; idx < argc - 1; idx++) {
		thread[idx].sleepTime = atoi(argv[idx + 1]);
		thread[idx].state = TS_ALIVE;
		if (pthread_create
		    (&thread[idx].tid, NULL, thread_job, (void *)idx) != 0) {
			perror("pthread_create");
			exit(EXIT_FAILURE);
		}
	}

	totThreads = argc - 1;
	numLive = totThreads;

	while (numLive > 0) {
		if (pthread_mutex_lock(&mutex) != 0) {
			perror("pthread_mutex_lock");
			exit(EXIT_FAILURE);
		}

		while (numUnjoined == 0) {
			if (pthread_cond_wait(&cond, &mutex) != 0) {
				perror("pthread_cond_wait");
				exit(EXIT_FAILURE);
			}
		}

		for (idx = 0; idx < totThreads; idx++) {
			if (thread[idx].state == TS_TERMINATED) {
				if (pthread_join(thread[idx].tid, NULL) != 0) {
					perror("pthread_join");
					exit(EXIT_FAILURE);
				}

				thread[idx].state = TS_JOINED;
				numLive--;
				numUnjoined--;

				printf("Reaped thread %d (numLive=%d)\n", idx,
				       numLive);
			}
		}

		if (pthread_mutex_unlock(&mutex) != 0) {
			perror("pthread_mutex_unlock");
			exit(EXIT_FAILURE);
		}
	}

	exit(EXIT_SUCCESS);
}

/*

$ ./a.out 2 3
Thread 0 terminating
Reaped thread 0 (numLive=1)
Thread 1 terminating
Reaped thread 1 (numLive=0)

*/

// http://man7.org/tlpi/code/online/dist/threads/thread_multijoin.c
// http://man7.org/tlpi/errata/  (No. 649)
