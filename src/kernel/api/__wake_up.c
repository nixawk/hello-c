#include <linux/module.h>
#include <linux/sched.h>
#include <linux/wait.h>
#include <linux/kthread.h>
#include <linux/pid.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LK");
MODULE_DESCRIPTION("Module for __wake_up");

int my_func(void *argc);
static int __init __wake_up_init(void);
static void __exit __wake_up_exit(void);

struct wait_queue_head head;
struct task_struct *old_thread;

int
my_func(void *argc)
{
        printk("in the kernel thread of function!\n");
        printk("the current pid is: %d\n", current->pid);
        printk("the state of the init function is: %ld\n", old_thread->state);
        __wake_up(&head, TASK_ALL, 0, NULL);
        printk("the state of the init function __wake_up is: %ld\n", old_thread->state);
        printk("out the kernel thread function\n");

        return 0;
}

static
int __init __wake_up_init(void)
{
        char namefrm[] = "__wake_up.c%s";
        long time_out;
        struct task_struct *result;
        struct wait_queue_entry data;

        printk("init __wake_up_init.\n");
        result = kthread_create_on_node(my_func, NULL, -1, namefrm);
        printk("the pid of the new thread is: %d\n", result->pid);
        printk("the current pid is: %d\n", current->pid);

        init_waitqueue_head(&head);
        init_waitqueue_entry(&data, current);
        add_wait_queue(&head, &data);
        old_thread = current;
        wake_up_process(result);

        time_out = schedule_timeout_uninterruptible(1000 * 10);
        printk("the schedule timeout is: %ld\n", time_out);
        printk("out __wake_up_init.\n");

        return 0;
}

static
void __wake_up_exit(void)
{
        printk("module exits ok !\n");
}

module_init(__wake_up_init);
module_exit(__wake_up_exit);

/*

$ uname -a
Linux labs 4.15.0-kali2-amd64 #1 SMP Debian 4.15.11-1kali1 (2018-03-21) x86_64 GNU/Linux

$ dmesg -k -w

[17636.154464] init __wake_up_init.
[17636.164043] the pid of the new thread is: 12358
[17636.164159] the current pid is: 12357
[17636.164188] in the kernel thread of function!
[17636.164192] the current pid is: 12358
[17636.164196] the state of the init function is: 2
[17636.164203] the state of the init function __wake_up is: 0
[17636.164206] out the kernel thread function
[17636.164215] the schedule timeout is: 10000
[17636.164218] out __wake_up_init.
[17647.490118] module exits ok !

*/

