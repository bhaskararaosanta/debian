#include <linux/module.h>
#include <linux/kernel.h>

int __init hello_init(void)
{
	printk(KERN_INFO "Bhaskar:Module loaded successfully by %s function\n", __FUNCTION__);
	return 0;
}

module_init(hello_init);
