#include <linux/module.h>
#include <linux/pid.h>
#include <linux/sched.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LK");
MODULE_DESCRIPTION("Module for get_pid");

static int __init get_pid_init(void);
static void __init get_pid_exit(void);

static int
__init get_pid_init(void)
{
	struct pid *kpid, *gpid;

	kpid = find_get_pid(current->pid);
	if (kpid != NULL) {
		printk("the find_get_pid result's count is: %d\n",
		       kpid->count.counter);
		printk("the find_get_pid result's level is: %d\n", kpid->level);

		gpid = get_pid(kpid);
		if (gpid != NULL) {
			printk("the get_pid result's count is: %d\n",
			       gpid->count.counter);
			printk("the get_pid result's level is: %d\n",
			       gpid->level);
		}
	} else {
		printk("failed to get_pid");
	}

	return 0;
}

static void __init get_pid_exit(void)
{
	printk(KERN_INFO "my module exit\n");
}

module_init(get_pid_init);
module_exit(get_pid_exit);

/*

static inline struct pid *get_pid(struct pid *pid)
{
    if (pid)
        atomic_inc(&pid->count);
    return pid;
}

*/
