#include <stdio.h>


/* Read environments from variable environ */

extern char **environ;

void
show_environ(void)
{
    char **env;
    for (env = environ; *env != NULL; env++)
    {
        puts(*env);
    }
}

/* Read environments from main arguments */

int
main(int argc, char *argv[], char **environ)
{
    for (; *environ != NULL; environ++)
    {
        puts(*environ);
    }

    show_environ();

    return 0;
}