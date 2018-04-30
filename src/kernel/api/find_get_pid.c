#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LK");
MODULE_DESCRIPTION("Module for find_get_pid");

static int __init find_get_pid_init(void);
static void __exit find_get_pid_exit(void);

static int
__init find_get_pid_init(void)
{
        struct pid *kpid;

        kpid = find_get_pid(current->pid);
        if (kpid != NULL)
        {
                printk(KERN_INFO "pid->count: %d\n", kpid->count.counter);
                printk(KERN_INFO "pid->level: %d\n", kpid->level);
                printk(KERN_INFO "upid->nr: %d\n", kpid->numbers[kpid->level].nr);
        }
        else
        {
                printk(KERN_ERR "Failed to find_get_pid\n");
        }

        return 0;
}

static void
__exit find_get_pid_exit(void)
{
        printk(KERN_INFO "module exits ok !\n");
}

module_init(find_get_pid_init);
module_exit(find_get_pid_exit);

// https://elixir.bootlin.com/linux/v4.16.5/source/include/linux/pid.h#L58
// https://elixir.bootlin.com/linux/v4.16.5/source/include/linux/types.h#L190

