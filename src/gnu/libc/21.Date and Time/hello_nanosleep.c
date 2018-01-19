#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// sleep VS nanosleep

void
nanosleep_usage(void)
{
    struct timespec request, remain;

    request.tv_sec = 1;
    request.tv_nsec = 10000000;

    if (nanosleep(&request, &remain) == -1)
    {
        perror("nanosleep");
        exit(EXIT_FAILURE);
    }

    printf("remain.tv_sec = %ld\n", (long) remain.tv_sec);
    printf("remain.tv_nsec = %ld\n", remain.tv_nsec);
}

int
main(void)
{
    nanosleep_usage();
    return 0;
}

// http://man7.org/linux/man-pages/man2/nanosleep.2.html
// http://en.cppreference.com/w/c/chrono/time_t