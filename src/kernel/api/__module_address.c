#include <linux/module.h>
#include <linux/preempt.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LK");
MODULE_DESCRIPTION("Module for __module_address");

static int __init __module_address_init(void);
static void __exit __module_address_exit(void);


int
a_module(void)
{
        return 0;
}

static int
__init __module_address_init(void)
{
        struct module * ret;
        unsigned long addr = (unsigned long)a_module;

        preempt_disable();
        ret = __module_address(addr);
        preempt_enable();

        if (ret != NULL)
        {
                printk(KERN_INFO "ret->name: %s\n", ret->name);
                printk(KERN_INFO "ret->state: %d\n", ret->state);
                printk(KERN_INFO "ret->percpu_size: %d\n", ret->percpu_size);
                printk(KERN_INFO "refs of %s is %d\n", ret->name, module_refcount(ret));
        }
        else
        {
                printk(KERN_INFO "__module_address return NULL\n");
        }

        return 0;
}

static void
__exit __module_address_exit(void)
{
        printk(KERN_INFO "module exit ok!\n");
}

module_init(__module_address_init);
module_exit(__module_address_exit);

/*

$ uname -a
Linux labs 4.15.0-kali2-amd64 #1 SMP Debian 4.15.11-1kali1 (2018-03-21) x86_64 GNU/Linux

$ insmod __module_address.ko
$ rmmod __module_address
$ dmesg -k -w

[ 1298.557524] ret->name: mod
[ 1298.557525] ret->state: 1
[ 1298.557525] ret->percpu_size: 0
[ 1298.557526] refs of mod is 1
[ 1310.669552] module exit ok!

*/

// References

// https://www.kernel.org/doc/html/latest/
// https://elixir.bootlin.com/linux/v4.15/source/include/linux/module.h
// https://elixir.bootlin.com/linux/v4.15/source/include/linux/preempt.h
