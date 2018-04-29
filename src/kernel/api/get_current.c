#include <linux/module.h>
#include <linux/sched.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LK");
MODULE_DESCRIPTION("Module for get_current");

static int __init get_current_init(void);
static void __exit get_current_exit(void);

static int
get_current_init(void)
{
        struct task_struct *current_task;

        current_task = get_current();
        if (current_task != NULL)
        {
                printk("task_struct->stack: %p\n", current_task->stack);
                printk("task_struct->cpu: %d\n", current_task->cpu);
        }
        else
        {
                printk("failed to get_current()\n");
        }

        return 0;
}

static void
get_current_exit(void)
{
        printk(KERN_INFO "module exits ok!\n");
}

module_init(get_current_init);
module_exit(get_current_exit);
