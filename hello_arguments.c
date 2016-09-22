#include <stdio.h>

int main(int argc, const char *argv[])
{
    if (argc != 2)                              /* argc should be 2 for correct execution */
    {
        /* We print argv[0] assuming it is the program name */
        printf("usage: %s filename", argv[0]);
    }
    else
    {
        // We assume argv[1] is a filename to open
        FILE *fp = fopen(argv[1], "r");

        if (fp == 0)
        {
            printf("Could not open file\n");
        }
        else
        {
            int x;

            while ((x = fgetc(fp)) != EOF)
            {
                printf("%c", x);
            }
            fclose(fp);
        }
    }
    return 0;
}
