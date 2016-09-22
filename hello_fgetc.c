#include <stdio.h>

int main()
{
    FILE *fp;
    int n;

    fp = fopen("test.txt", "r");
    while ((n = fgetc(fp)) != EOF) {
        // printf("%d\n", n);
        /* write output into stdout */
        fputc(n, stdout);
    }

    return 0;
}
