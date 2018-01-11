// Just works on Linux platform.

#include <sys/inotify.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE  (10 * (sizeof(struct inotify_event) + NAME_MAX + 1))

void
inotify_event_handler(struct inotify_event *event)
{
    printf("wd=%2d;", event->wd);
    if (event->cookie > 0)
    {
        printf("cookie=%4d\n", event->cookie);
    }

    printf("mask = ");
    if (event->mask & IN_ACCESS)        printf("IN_ACCESS ");
    if (event->mask & IN_ATTRIB)        printf("IN_ATTRIB ");
    if (event->mask & IN_CLOSE_NOWRITE) printf("IN_CLOSE_NOWRITE ");
    if (event->mask & IN_CLOSE_WRITE)   printf("IN_CLOSE_WRITE ");
    if (event->mask & IN_CREATE)        printf("IN_CREATE ");
    if (event->mask & IN_DELETE)        printf("IN_DELETE ");
    if (event->mask & IN_DELETE_SELF)   printf("IN_DELETE_SELF ");
    if (event->mask & IN_IGNORED)       printf("IN_IGNORED ");
    if (event->mask & IN_ISDIR)         printf("IN_ISDIR ");
    if (event->mask & IN_MODIFY)        printf("IN_MODIFY ");
    if (event->mask & IN_MOVE_SELF)     printf("IN_MOVE_SELF ");
    if (event->mask & IN_MOVED_FROM)    printf("IN_MOVED_FROM ");
    if (event->mask & IN_MOVED_TO)      printf("IN_MOVED_TO ");
    if (event->mask & IN_OPEN)          printf("IN_OPEN ");
    if (event->mask & IN_Q_OVERFLOW)    printf("IN_OVERFLOW ");
    if (event->mask & IN_UNMOUNT)       printf("IN_UNMOUNT ");
    printf("\n");

    if (event->len > 0)
    {
        printf("name=%s\n", event->name);
    }
}

int
main(int argc, char *argv[])
{
    int inotifyfd, wd;    /* inotify file descriptor */
    int i;                /* for index */
    ssize_t nread;        /* count of read */
    char buf[BUF_SIZE];   /* buffer of read */
    char *p;
    struct inotify_event *event;

    if (argc < 2 || strcmp(argv[1], "--help") == 0)
    {
        printf("[*] Usage: %s <FILE> ...\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Linux inotify monitor */

    inotifyfd = inotify_init();
    if (inotifyfd == -1)
    {
        perror("inotify_init");
        exit(EXIT_FAILURE);
    }

    for (i = 1; i < argc; i++)
    {
        wd = inotify_add_watch(inotifyfd, argv[i], IN_ALL_EVENTS);
        if (wd == -1)
        {
            perror("inotify_add_watch");
            exit(EXIT_FAILURE);
        }

        printf("Watching %s using wd %d\n", argv[i], wd);
    }

    for (;;)
    {
        nread = read(inotifyfd, buf, BUF_SIZE);
        if (nread == 0)
        {
            fprintf(stderr, "read() from inotify fd returned 0 !");
            exit(EXIT_FAILURE);
        }

        if (nread == -1)
        {
            perror("read");
            exit(EXIT_FAILURE);
        }

        printf("Read %ld bytes from inotify fd\n", (long) nread);

        for (p = buf; p < buf + nread;)
        {
            event = (struct inotify_event *) p;
            inotify_event_handler(event);
            p += sizeof(struct inotify_event) + event->len;
        }
    }

    exit(EXIT_SUCCESS);
}


/*

$ ./a.out 1.txt 
Watching 1.txt using wd 1
Read 16 bytes from inotify fd
wd= 1;mask = IN_OPEN
Read 16 bytes from inotify fd
wd= 1;mask = IN_ACCESS 
Read 16 bytes from inotify fd
wd= 1;mask = IN_CLOSE_NOWRITE 
Read 32 bytes from inotify fd
wd= 1;mask = IN_MODIFY 
wd= 1;mask = IN_OPEN
Read 32 bytes from inotify fd
wd= 1;mask = IN_MODIFY 
wd= 1;mask = IN_CLOSE_WRITE 
Read 16 bytes from inotify fd
wd= 1;mask = IN_ATTRIB 
Read 16 bytes from inotify fd
wd= 1;mask = IN_DELETE_SELF 
Read 16 bytes from inotify fd
wd= 1;mask = IN_IGNORED 
^C

*/

// http://man7.org/linux/man-pages/man2/inotify_init.2.html