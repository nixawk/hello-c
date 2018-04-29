#include <linux/module.h>
#include <linux/kallsyms.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LK");
MODULE_DESCRIPTION("Module for sprint_symbol");

static int __init symbol_put_addr_init(void);
static void __exit symbol_put_addr_exit(void);

static int
__init symbol_put_addr_init(void)
{
        void *address = __builtin_return_address(0);

        printk(KERN_INFO "module_refcount before sprint_put_addr: %d\n", module_refcount(THIS_MODULE));
        symbol_put_addr(address);
        printk(KERN_INFO "module_refcount after sprint_put_addr: %d\n", module_refcount(THIS_MODULE));
        return 0;
}

static void
__exit symbol_put_addr_exit(void)
{
        printk(KERN_INFO "module exits ok!\n");
}

module_init(symbol_put_addr_init);
module_exit(symbol_put_addr_exit);
