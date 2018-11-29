#include <linux/module.h>
#include <linux/sched.h>
#include <linux/pid.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LK");
MODULE_DESCRIPTION("Module for find_pid_ns");

static int __init find_pid_ns_init(void);
static void __init find_pid_ns_exit(void);

static int
__init find_pid_ns_init(void)
{
	struct pid *kpid = find_get_pid(current->pid);
	struct pid *fpid =
	    find_pid_ns(kpid->numbers[kpid->level].nr,
			kpid->numbers[kpid->level].ns);

	printk("the find_pid_ns result's count is: %d\n", fpid->count.counter);
	printk("the find_pid_ns result's level is: %d\n", fpid->level);
	return 0;
}

static void __init find_pid_ns_exit(void)
{
	printk(KERN_INFO "module exits ok !\n");
}

module_init(find_pid_ns_init);
module_exit(find_pid_ns_exit);	// please try to del ';', and recompile it 
