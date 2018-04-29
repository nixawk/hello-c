#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LK");
MODULE_DESCRIPTION("Module for __find_symbol");

static int __init find_symbol_init(void);
static void __exit find_symbol_exit(void);

static int
__init find_symbol_init(void)
{
        struct module *kmodule;
        const struct kernel_symbol *ksymbol;

        const s32 *crc;

        bool enable_gpl = true;
        bool enable_warn = true;

        const char *module_name = "ext4";
        const char *symbol_name = "ext4_init_security";

        kmodule = find_module(module_name);
        if (kmodule != NULL) {
                printk(KERN_INFO "kmodule->name: %s\n", kmodule->name);
                ksymbol = find_symbol(symbol_name, &kmodule, &crc, enable_gpl, enable_warn);
                if (ksymbol != NULL)
                {
                        printk(KERN_INFO "ksymbol->value: %lx\n", ksymbol->value);
                        printk(KERN_INFO "ksymbol->name: %s\n", ksymbol->name);
                }
                else {
                        printk(KERN_ERR "failed to find_symbol\n");
                }

        if (crc != NULL)
        {
                printk(KERN_INFO "*crc: %d\n", *crc);
        }
        }
        else {
                printk(KERN_ERR "failed to find_module\n");
        }

        return 0;
}

static void
__exit find_symbol_exit(void)
{
        printk(KERN_INFO "module exits ok!\n");
}

module_init(find_symbol_init);
module_exit(find_symbol_exit);
