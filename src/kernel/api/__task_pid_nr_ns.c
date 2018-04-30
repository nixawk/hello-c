#include <linux/module.h>
#include <linux/sched.h>
#include <linux/pid.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LK");
MODULE_DESCRIPTION("Module for __task_pid_nr_ns");

static int __init __task_pid_nr_ns_init(void);
static void __exit __task_pid_nr_ns_exit(void);

static int
__init __task_pid_nr_ns_init(void)
{
        struct pid *kpid = find_get_pid(current->pid);
        struct task_struct *task = pid_task(kpid, PIDTYPE_PID);

        pid_t result = __task_pid_nr_ns(task, PIDTYPE_PID, kpid->numbers[kpid->level].ns);

        printk("the pid of the find_get_pid is :%d\n", kpid->numbers[kpid->level].nr);
        printk("the result of the __task_pid_nr_ns is :%d\n", result);
        printk("the pid of current thread is :%d\n", current->pid);

        return 0;
}

static void
__exit __task_pid_nr_ns_exit(void)
{
        printk(KERN_INFO "module exits ok !\n");
}

module_init(__task_pid_nr_ns_init);
module_exit(__task_pid_nr_ns_exit);

