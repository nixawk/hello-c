#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/reboot.h>
#include <linux/reboot.h>

/*
 * LINUX_REBOOT_CMD_CAD_OFF
 * LINUX_REBOOT_CMD_CAD_ON
 * LINUX_REBOOT_CMD_HALT
 * LINUX_REBOOT_CMD_KEXEC
 * LINUX_REBOOT_CMD_POWER_OFF
 * LINUX_REBOOT_CMD_RESTART
 * LINUX_REBOOT_CMD_RESTART2
 * LINUX_REBOOT_CMD_SW_SUSPEND
 *
 *
 * */
int main(void)
{
	/*
	 * (RB_AUTOBOOT, 0x1234567).  The message "Restarting system." is
	 * printed, and a default  restart  is  per‐formed immediately. 
	 * If not preceded by a sync(2), data will be lost. */
	if (reboot(LINUX_REBOOT_CMD_RESTART) == -1) {
		perror("reboot");	/* reboot: Operation not permitted */
		exit(EXIT_FAILURE);
	}

	return 0;
}

/* https://elixir.bootlin.com/linux/latest/source/include/uapi/linux/reboot.h#L32 */
