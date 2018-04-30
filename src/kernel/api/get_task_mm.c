#include <linux/module.h>
#include <linux/sched/mm.h>
#include <linux/mm_types.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LK");
MODULE_DESCRIPTION("Module for get_task_mm");

static int __init get_task_mm_init(void);
static void __exit get_task_mm_exit(void);

static int
__init get_task_mm_init(void)
{
        struct task_struct *task;
        struct mm_struct *mm;

        task = get_current();
        if (task != NULL)
        {
                mm = get_task_mm(task);
                if (mm != NULL)
                {
                        printk(KERN_INFO "the mm_users of the mm_struct is: %d\n", mm->mm_users.counter);
                        printk(KERN_INFO "the mm_count of the mm_struct is :%d\n", mm->mm_count.counter);
                }
                else
                {
                        printk(KERN_ERR "failed to get_task_mm");
                }
        }
        else
        {
                printk(KERN_ERR "failed to get_current");
        }
        return 0;
}

static void
__exit get_task_mm_exit(void)
{
        printk(KERN_INFO "module exits ok !\n");
}

module_init(get_task_mm_init);
module_exit(get_task_mm_exit);
