#include <linux/module.h>
#include <linux/pid.h>
#include <linux/sched.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LK");
MODULE_DESCRIPTION("Module for find_vpid");

static int __init find_vpid_init(void);
static void __init find_vpid_exit(void);

static int
__init find_vpid_init(void)
{
        struct pid *vpid = find_vpid(current->pid);

        if (vpid != NULL)
        {
                printk("the find_vpid result's count is: %d\n", vpid->count.counter);
                printk("the find_vpid result's level is: %d\n", vpid->level);
        }
        else
        {
                printk("failed to find_vpid");
        }

        return 0;
}

static void __init find_vpid_exit(void)
{
        printk(KERN_INFO "my module exit\n");
}

module_init(find_vpid_init);
module_exit(find_vpid_exit);  // please try to del ';', and recompile it 

/*

# insmod find_vpid.ko
# rmmod find_vpid

[   91.900196] the find_vpid result's count is: 2
[   91.900197] the find_vpid result's level is: 0
[   98.505130] BUG: unable to handle kernel paging request at ffffffffc0293051
[   98.505137] IP: 0xffffffffc0293051
[   98.505139] PGD c80e067 P4D c80e067 PUD c810067 PMD 2677c067 PTE 0

# uname -a
Linux labs 4.16.5 #2 SMP Sun Apr 29 10:53:27 EDT 2018 x86_64 GNU/Linux

*/
