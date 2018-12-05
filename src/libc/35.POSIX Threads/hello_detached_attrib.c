#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void *thread_job(void *arg)
{
	char *s = (char *)arg;

	printf("thread print: %s\n", arg);

	return (void *)strlen(s);
}

void pthread_attr_usage(void)
{
	pthread_attr_t attr;
	pthread_t thread;

	if (pthread_attr_init(&attr) != 0) {
		perror("pthread_attr_init");
		exit(EXIT_FAILURE);
	}

	if (pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED) != 0) {
		perror("pthread_attr_setdetachstate");
		exit(EXIT_FAILURE);
	}

	if (pthread_create(&thread, &attr, thread_job, "Hello, World") != 0) {
		perror("pthread_create");
		exit(EXIT_FAILURE);
	}

	if (pthread_attr_destroy(&attr) != 0) {
		perror("pthread_attr_destory");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}

int main(void)
{
	pthread_attr_usage();
	return 0;
}
