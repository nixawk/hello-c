#include <time.h>
#include <stdio.h>

int main()
{
    time_t *timer;

    time(timer);  // current time
    printf("%s\n", asctime(localtime(timer)));
    return 0;
}
