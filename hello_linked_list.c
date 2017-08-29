#include <stdio.h>
#include <stdlib.h>

struct employee {
    int id;
    struct employee *partner;
};


int main(void)
{
    struct employee *boss;
    struct employee *someone;

    int n;

    boss = malloc(sizeof(struct employee));
    boss->id = 1234;
    boss->partner = 0;

    someone = boss;

    for (n = 5; n > 0; n--) {
        someone->partner = malloc(sizeof(struct employee));
        someone = someone->partner;
        someone->id = n;
    }

    if (boss != 0) {
        // while (boss->partner != 0) {
        while (boss != NULL) {
            printf("partner id  : %d\n", boss->id);
            printf("partner pt  : %p\n", boss->partner);
            boss = boss->partner;
        }
    }

    if (boss == 0) {
        printf("Out of memory");
        return 0;
    }

    /* initialize the new memory */
    boss->partner = 0;
    return 0;
}
