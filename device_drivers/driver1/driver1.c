
#include<linux/module.h>
#include<linux/kernel.h>

int hello_init(void)
{
	printk(KERN_ALERT "Driver loaded successfully:Bhaskar\n");
	printk(KERN_ALERT "Inside insert %s function:\n", __FUNCTION__);
	return 0;
}

void hello_exit(void)
{
	printk(KERN_ALERT "Driver unloaded successfully:Bhaskar\n");
	printk(KERN_ALERT "Inside cleanup %s function on Date:\n", __FUNCTION__);
}

module_init(hello_init);
module_exit(hello_exit);
