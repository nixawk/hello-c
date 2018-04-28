#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LK");
MODULE_DESCRIPTION("Module for __module_text_address");

int func_a(void);
static int __init __module_text_address_init(void);
static void __exit __module_text_address_exit(void);

int
func_a(void)
{
    return 0;
}

static int var_b = 4;

static int
__init __module_text_address_init(void)
{
    unsigned long addr;
    struct module * ret;

    // __module_text_address -> function

    addr = (unsigned long)func_a;
    preempt_disable();
    ret = __module_text_address(addr);
    preempt_enable();

    printk(KERN_INFO "it's about func_a\n");
    if (ret != NULL)
    {
        printk(KERN_INFO "ret->name: %s\n", ret->name);
        printk(KERN_INFO "ret->state: %d\n", ret->state);
        printk(KERN_INFO "ret->percpu_size: %d\n", ret->percpu_size);
    }
    else
    {
        printk(KERN_WARNING "func_a is not in text area!\n");
    }

    // __module_text_address -> var

    addr = (unsigned long)var_b;
    preempt_disable();
    ret = __module_text_address(addr);
    preempt_enable();

    printk(KERN_INFO "it's about var_b\n");
    if (ret != NULL)
    {
        printk(KERN_INFO "ret->name: %s\n", ret->name);
        printk(KERN_INFO "ret->state: %d\n", ret->state);
        printk(KERN_INFO "ret->percpu_size: %d\n", ret->percpu_size);
    }
    else
    {
        printk(KERN_WARNING "var_b is not in text area!\n");
    }

    return 0;
}


static void
__exit __module_text_address_exit(void)
{
    printk(KERN_INFO "__module_text_address exit ok !\n");
}

module_init(__module_text_address_init);
module_exit(__module_text_address_exit);

/*

$ dmesg -k -w

[ 5414.405801] it's about func_a
[ 5414.405802] ret->name: mod
[ 5414.405803] ret->state: 1
[ 5414.405803] ret->percpu_size: 0

[ 5414.405804] it's about var_b
[ 5414.405804] var_b is not in text area!
[ 5422.265307] __module_text_address exit ok !

*/

