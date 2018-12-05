#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

static int glob = 0;
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;	// pthread_mutex_init

void *thread_job(void *arg)
{
	int loops = *((int *)arg);
	int loc, j, s;

	for (j = 0; j < loops; j++) {
		if (pthread_mutex_lock(&mtx) != 0) {
			perror("pthread_mutex_lock");
			exit(EXIT_FAILURE);
		}

		loc = glob;
		loc++;
		glob = loc;

		if (pthread_mutex_unlock(&mtx) != 0) {
			perror("pthread_mutex_unlock");
			exit(EXIT_FAILURE);
		}
	}

	return NULL;
}

void thread_mutex_usage(int loops)
{
	pthread_t thread1, thread2;
	void *value_ptr1, *value_ptr2;

	// int loops = 10000;

	if (pthread_create(&thread1, NULL, thread_job, &loops) != 0) {
		perror("pthread_create - thread1");
		exit(EXIT_FAILURE);
	}

	if (pthread_create(&thread2, NULL, thread_job, &loops) != 0) {
		perror("pthread_create - thread2");
		exit(EXIT_FAILURE);
	}

	if (pthread_join(thread1, &value_ptr1) != 0) {
		perror("pthread_join - thread1");
		exit(EXIT_FAILURE);
	}

	if (pthread_join(thread2, &value_ptr2) != 0) {
		perror("pthread_join - thread2");
		exit(EXIT_FAILURE);
	}

	printf("glob = %d\n", glob);

	exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[])
{
	int loops;

	if (argc < 2) {
		printf("[*] %s <num-loops>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	sscanf(argv[1], "%d", &loops);

	printf("loops = %d\n", loops);
	thread_mutex_usage(loops);

	return 0;
}

/*

$ gcc -pthread hello_pthread_mutex_t.c
$ ./a.out
loops = 100000
glob = 200000

*/

// http://man7.org/linux/man-pages/man3/pthread_mutex_init.3p.html
