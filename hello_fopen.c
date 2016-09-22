#include <stdio.h>

int main()
{
    FILE *fp;

    fp = fopen("test.txt", "r");
    printf("fopen  - open a file called test.txt\n");
    fclose(fp);
    printf("fclose - close a file\n");
    return 0;
}
