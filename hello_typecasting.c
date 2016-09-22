#include <stdio.h>

int main()
{
    FILE *fp;
    int n;

    fp = fopen("test.txt", "r");
    while ((n = fgetc(fp)) != EOF)
    {
        printf("%02x : %c\n", n, (char)n);
    }

    fclose(fp);
    return 0;
}
