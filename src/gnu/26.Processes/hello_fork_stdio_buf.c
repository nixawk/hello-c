#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int
main(void)
{
    // setbuf(stdout, NULL);  /* Fix1: disable buffer cache */

    printf("Hello, World\n");
    fflush(stdout);           /* Fix2: flush buf cache before fork() */

    write(STDOUT_FILENO, "Ciao\n", 5);

    if (fork() == (int) -1)
    {
        exit(EXIT_FAILURE);
    }

    /* Both child and parent continue execution here */

    exit(EXIT_SUCCESS);
}


/*

$ ./a.out
Hello, World
Ciao


$ ./a.out > a
$ cat a
Ciao
Hello, World    --- double printf here
Hello, World

*/


// Fix:
// setbuf(stdout, NULL);  /* Fix: disable buffer cache */

// http://man7.org/linux/man-pages/man2/fork.2.html
// http://man7.org/linux/man-pages/man3/setbuf.3.html