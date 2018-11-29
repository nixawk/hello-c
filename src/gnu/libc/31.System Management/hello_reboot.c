#include <unistd.h>
#include <linux/reboot.h>
#include <sys/reboot.h>
#include <stdio.h>
#include <stdlib.h>

// LINUX_REBOOT_MAGIC1

// The magic numbers are so that a memory error that flips bits in the system
// call number which results in the reboot system call's number won't reboot
// the machine unless the memory error also happens to change the arguments
// to the magic numbers.

void reboot_usage(void)
{				/* reboot computer */
	if (reboot(LINUX_REBOOT_CMD_RESTART) == -1) {
		perror("reboot()");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

int main(void)
{
	reboot_usage();
	return 0;
}

// http://man7.org/linux/man-pages/man2/reboot.2.html
// https://elixir.free-electrons.com/linux/v4.3/source/include/uapi/linux/reboot.h#L8
// https://unix.stackexchange.com/questions/145502/what-is-the-use-of-magic-arguments-in-linux-reboot-system-call
// https://superuser.com/questions/640267/what-is-the-purpose-of-the-magic-numbers-in-linux-reboot
