#include <unistd.h>
#include <linux/reboot.h>
#include <sys/reboot.h>
#include <stdio.h>
#include <stdlib.h>


void
reboot_usage(void)  /* reboot computer */
{
    if (reboot(LINUX_REBOOT_CMD_RESTART) == -1)
    {
        perror("reboot()");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}


int
main(void)
{
    reboot_usage();
    return 0;
}


// http://man7.org/linux/man-pages/man2/reboot.2.html