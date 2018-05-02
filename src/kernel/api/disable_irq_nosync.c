#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LK");
MODULE_DESCRIPTION("Module for disable_irq_nosync");

#ifndef IRQF_DISABLED  // Linux Kernel v4.16.6 - NOT EXIST
#define IRQF_DISABLED 0x00000020
#endif

static int __init disable_irq_nosync_init(void);
static void __exit disable_irq_nosync_exit(void);
static irqreturn_t irq_handler(int, void *);
static int irq = 3;

static irqreturn_t
irq_handler(int data, void *dev_id)
{
        printk("the data is: %d\n", data);
        printk("in the interrupt handler function\n");

        return IRQ_NONE;
}

static int
__init disable_irq_nosync_init(void)
{
        int result = 0;

        printk("into disable_irq_nosync_init\n");
        result = request_irq(irq, irq_handler, IRQF_DISABLED, "A_NEW_DEVICE", NULL);
        disable_irq_nosync(irq);
        enable_irq(irq);
        printk("out disable_irq_nosync_exit");
        return 0;
}

static void
__exit disable_irq_nosync_exit(void)
{
        printk("module exits ok !\n");
}

module_init(disable_irq_nosync_init);
module_exit(disable_irq_nosync_exit);

// https://elixir.bootlin.com/linux/v3.9/source/include/linux/interrupt.h#L62
