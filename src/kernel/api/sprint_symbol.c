#include <linux/module.h>
#include <linux/kallsyms.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LK");
MODULE_DESCRIPTION("Module for sprint_symbol");

static int __init sprint_symbol_init(void);
static void __exit sprint_symbol_exit(void);

static int
__init sprint_symbol_init(void)
{
        int ret;
        char buffer[KSYM_SYMBOL_LEN];
        unsigned long address = (unsigned long)__builtin_return_address(0);

        ret = sprint_symbol(buffer, address);
        printk(KERN_INFO "ret: %d\n", ret);
        printk(KERN_INFO "buf: %s\n", buffer);

        return 0;
}

static void
__exit sprint_symbol_exit(void)
{
        printk(KERN_INFO "module exits ok!\n");
}

module_init(sprint_symbol_init);
module_exit(sprint_symbol_exit);
