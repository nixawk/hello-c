#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LK");
MODULE_DESCRIPTION("Module for EXPORT_SYMBOL");

static int func_symbol(void);
static int __init export_symbol_init(void);
static void __exit export_symbol_exit(void);
static int var_symbol = 32;

EXPORT_SYMBOL(func_symbol);
EXPORT_SYMBOL(var_symbol);

static int func_symbol(void)
{
	printk("this is a module symbol\n");
	return 0;
}

static int
__init export_symbol_init(void)
{
	printk("module inits ok!\n");
	return 0;
}

static void
__exit export_symbol_exit(void)
{
	printk(KERN_INFO "module exits ok!\n");
}

module_init(export_symbol_init);
module_exit(export_symbol_exit);
