#include <linux/module.h>
#include <linux/kernel.h>

void __exit hello_exit(void)
{
	printk(KERN_INFO "Bhaskar:Module unloaded successfully by %s function\n", __FUNCTION__);
}

module_exit(hello_exit);
