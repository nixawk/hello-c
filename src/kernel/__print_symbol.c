#include <linux/module.h>
#include <linux/init.h>
#include <linux/kallsyms.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LK");
MODULE_DESCRIPTION("Module for __print_symbol");

int func_a(void);
static int __init __print_symbol_init(void);
static void __exit __print_symbol_exit(void);

int
a_symbol(void)
{
    return 0;
}

EXPORT_SYMBOL(a_symbol);

static int
__init __print_symbol_init(void)
{
    char * fmt;
    unsigned long addr;
    char *name;
    struct module * fmodule = NULL;

    addr = (unsigned long) __builtin_return_address(0);
    fmt = "it's the first part,\n %s";
    __print_symbol(fmt, addr);
    printk(KERN_INFO "\n\n");

    name = "ext4";
    fmodule = find_module(name);

    if (fmodule != NULL)
    {
    printk("fmodule->name: %s\n", fmodule->name);
    addr = (unsigned long)fmodule->init;
    fmt = "it's the second part,\n %s";
    __print_symbol(fmt, addr);
    }

    addr = (unsigned long)a_symbol + 5;
    fmt = "it's the third part,\n %s";
    __print_symbol(fmt, addr);

    return 0;
}

static void
__exit __print_symbol_exit(void)
{
    printk(KERN_INFO "module exit ok !\n");
}

module_init(__print_symbol_init);
module_exit(__print_symbol_exit);

/*

# dmesg -k -w

[ 7935.143494] it's the first part,
                do_one_initcall+0x4e/0x18d
[ 7935.143495] 

[ 7935.143507] fmodule->name: ext4
[ 7935.143511] it's the second part,
                async_cookie+0x1242/0xffffffffffffeab0 [battery]
[ 7935.143514] it's the third part,
                a_symbol+0x5/0x8 [mod]
[ 7944.734209] module exit ok !

*/

// References
// https://elixir.bootlin.com/linux/v4.15/source/include/linux/kallsyms.h#L116
// https://elixir.bootlin.com/linux/v4.15/source/include/linux/module.h#L328
