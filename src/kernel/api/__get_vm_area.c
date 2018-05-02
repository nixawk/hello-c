#include <linux/module.h>
#include <linux/vmalloc.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LK");
MODULE_DESCRIPTION("Module for __get_vm_area");

static int __get_vm_area_init(void);
static void __get_vm_area_exit(void);
struct vm_struct *vm = NULL;

static int
__get_vm_area_init(void)
{
        vm = __get_vm_area(8192 * 4, VM_ALLOC, 0xC0000100, 0xdd000000);
        if (!vm)
                return -ENOMEM;
        else {
                printk("vm->size : %ld\n", vm->size);
                printk("vm->addr : 0x%lx\n", (unsigned long)vm->addr);
        }

        return 0;
}

static void __get_vm_area_exit(void)
{
        if (vm)
        {
                free_vm_area(vm);
                printk("free_vm_area ok !\n");
        }

        printk("module exits ok !\n");
}

module_init(__get_vm_area_init);
module_exit(__get_vm_area_exit);

// References
// https://elixir.bootlin.com/linux/v4.16.5/source/include/linux/vmalloc.h#L125
