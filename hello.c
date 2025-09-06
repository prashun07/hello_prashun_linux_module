#include <linux/module.h>   // For all kernel modules
#include <linux/kernel.h>   // For KERN_INFO
#include <linux/init.h>     // For __init and __exit macros

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Prashun");
MODULE_DESCRIPTION("A simple Hello World kernel module");

static int __init hello_init(void) {
	printk(KERN_INFO "Hello, Prashun!\n");
  	return 0;
}

static void __exit hello_exit(void) {
    printk(KERN_INFO "Goodbye, Prashun!\n");
}

module_init(hello_init);
module_exit(hello_exit);
