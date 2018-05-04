#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/syscalls.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LK");
MODULE_DESCRIPTION("Module for sys_getuid");

static int __init sys_getuid_init(void);
static void __exit sys_getuid_exit(void);

static int
__init sys_getuid_init(void)
{
        long uid;

        printk(KERN_INFO "sys_getuid_init\n");

        uid = sys_getuid();
        // make an error: Unknown symbol sys_getuid (err 0)
        // This means that the kernel isn't allowing modules to see that variable.

        printk(KERN_INFO "current uid = %ld\n", uid);

        return 0;
}

static void
__exit sys_getuid_exit(void)
{
        printk(KERN_INFO "sys_getuid_exit\n");
}

module_init(sys_getuid_init);
module_exit(sys_getuid_exit);

/*

sys_getuid is not in /usr/src/linux/Module.symvers [EXPORT_SYMBOL]

*/

/*

#include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>

void
syscall_usage(void)
{
    long uid;

    uid = syscall(SYS_getuid);
    printf("uid = %ld\n", uid);
}

int
main(void)
{
    syscall_usage();
    return 0;
}

*/

// https://elixir.bootlin.com/linux/v4.16.7/source/include/linux/syscalls.h#L598
// https://stackoverflow.com/questions/7513184/unknown-symbol-in-while-loading-a-kernel-module
// http://www.unixresources.net/linux/clf/driver/archive/00/00/65/31/653102.html
// http://man7.org/linux/man-pages/man2/syscall.2.html
// http://www.linfo.org/kernel_space.html
// https://en.wikipedia.org/wiki/User_space
// https://www.usna.edu/Users/cs/aviv/classes/ic221/s16/lec/11/lec.html
// https://elixir.bootlin.com/linux/v4.16.7/source/include/linux/syscalls.h#L598