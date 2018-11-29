#include <linux/module.h>
#include <linux/sched/mm.h>
#include <linux/mm_types.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LK");
MODULE_DESCRIPTION("Module for mmput");

static int __init mmput_init(void);
static void __exit mmput_exit(void);

static int
__init mmput_init(void)
{
	struct task_struct *task;
	struct mm_struct *mm;

	task = get_current();
	if (task != NULL) {
		mm = get_task_mm(task);
		if (mm != NULL) {
			printk(KERN_INFO
			       "the mm_users of the mm_struct is: %d\n",
			       mm->mm_users.counter);
			printk(KERN_INFO
			       "the mm_count of the mm_struct is: %d\n",
			       mm->mm_count.counter);
			printk(KERN_INFO
			       "the mm_owner->pid of the mm_struct is: %d\n",
			       mm->owner->pid);
			printk(KERN_INFO
			       "the mm_owner->tgid of the mm_struct is: %d\n",
			       mm->owner->tgid);

			mmput(mm);

			printk(KERN_INFO
			       "the mm_users of the mm_struct is: %d\n",
			       mm->mm_users.counter);
			printk(KERN_INFO
			       "the mm_count of the mm_struct is: %d\n",
			       mm->mm_count.counter);
			printk(KERN_INFO
			       "the mm_owner->pid of the mm_struct is: %d\n",
			       mm->owner->pid);
			printk(KERN_INFO
			       "the mm_owner->tgid of the mm_struct is: %d\n",
			       mm->owner->tgid);
		} else {
			printk(KERN_ERR "failed to get_task_mm");
		}
	} else {
		printk(KERN_ERR "failed to get_current");
	}
	return 0;
}

static void
__exit mmput_exit(void)
{
	printk(KERN_INFO "module exits ok !\n");
}

module_init(mmput_init);
module_exit(mmput_exit);
