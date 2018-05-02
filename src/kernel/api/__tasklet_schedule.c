#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LK");
MODULE_DESCRIPTION("Module for __tasklet_schedule");

static int __init __tasklet_schedule_init(void);
static void __exit __tasklet_schedule_exit(void);
struct tasklet_struct tasklet1, tasklet2;

static void
irq_tasklet_action1(unsigned long data)
{
        printk("in irq_tasklet_action the state of the tasklet1 is: %ld\n", tasklet1.state);
        printk("tasklet1 running. by auhthor\n");
}

static void
irq_tasklet_action2(unsigned long data)
{
        printk("in irq_tasklet_action the state of the tasklet2 is: %ld\n", tasklet2.state);
        printk("tasklet2 running. by auhthor\n");
}

static int
__init __tasklet_schedule_init(void)
{
        static unsigned long data = 0;

        printk("into __tasklet_schedule\n");

        tasklet_init(&tasklet1, irq_tasklet_action1, data);
        tasklet_init(&tasklet2, irq_tasklet_action2, data);

        printk("The state of the tasklet1 is: %ld\n", tasklet1.state);
        printk("The state of the tasklet2 is: %ld\n", tasklet2.state);

        // What's the differences between tasklet_schedule and
        // tasklet_hi_schedule ?

        tasklet_schedule(&tasklet1);
        if (!test_and_set_bit(TASKLET_STATE_SCHED, &tasklet2.state))
                __tasklet_schedule(&tasklet2);
        // tasklet_schedule(&tasklet2);

        tasklet_kill(&tasklet1);
        tasklet_kill(&tasklet2);
        printk("out __tasklet_schedule\n");
        return 0;
}

static void
__exit __tasklet_schedule_exit(void)
{
        printk("module exits ok !\n");
}

module_init(__tasklet_schedule_init);
module_exit(__tasklet_schedule_exit);
