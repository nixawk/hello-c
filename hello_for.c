#include <stdio.h>

int main()
{
    int x;

    printf("Loop - for : \n");
    for (x = 0; x < 10; x++) {
        printf("%d\n", x);
    }

    printf("Loop - while : \n");
    x = 0;
    while (x < 10) {
        printf("%d\n", x);
        x++;
    }

    printf("Loop - do .. while : \n");
    x = 0;
    do {
        printf("%d\n", x);
        x++;
    } while (x < 10);

    return 0;
}
