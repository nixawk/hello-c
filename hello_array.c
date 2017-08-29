#include <stdio.h>

void array_x_y(void) {
    int x = 2;
    int y = 3;
    char astring[x][y];

    int i, j;

    for (i = 0; i < x; ++i) {
        for (j = 0; j < y; ++j) {
            astring[i][j] = i + j;
        }
    }

    for (i = 0; i < x; ++i) {
        for (j = 0; j < y; ++j) {
            printf("[%d][%d]: %d\n", i, j, astring[i][j]);
        }
    }
}

int main(void)
{
    char astring[10];
    int n;

    printf("Please enter a string: ");
    scanf("%s", astring);

    /* if inputs length > 10, prog will crash */
    for (n = 0; n < 10; ++n) {
        if (astring[n] == 'a')
            printf("[%d] letter is a\n", n);
    }

    array_x_y();

    getchar();
    return 0;
}
