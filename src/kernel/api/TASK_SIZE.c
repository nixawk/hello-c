#include <linux/module.h>
#include <linux/memory.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LK");
MODULE_DESCRIPTION("Module for TASK_SIZE");

static int __init find_task_size_init(void);
static void __exit find_task_size_exit(void);

static int
__init find_task_size_init(void)
{
        printk(KERN_INFO "Memory TASK_SIZE: 0x%lx\n", TASK_SIZE);
        return 0;
}

static void
__exit find_task_size_exit(void)
{
        printk(KERN_INFO "module exits ok !\n");
}

module_init(find_task_size_init);
module_exit(find_task_size_exit);

/*

# dmesg -k -w

[ 2570.156990] Memory TASK_SIZE: 0x7ffffffff000
[ 2573.164671] module exits ok !

*/

// https://elixir.bootlin.com/linux/v4.16.7/source/arch/arm/include/asm/memory.h#L40
