/*
 * First Hellow World program for linux device driver
 * AUTHOR : ANAND MOHAN TIWARI
 */

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/version.h>

static int __init hellow_world_init (void)
{
	printk(KERN_INFO "\nHellow to the World of Linux Device driver\n");
	printk(KERN_DEBUG "Learn more things\n");
	printk(KERN_INFO "Kernel module inserted Successfully\n");
	return 0;
}

static void __exit hellow_world_exit (void){
	printk(KERN_WARNING "You Unloaded this module\n");
	printk(KERN_INFO "Unloading the module of hellow world\n");
	printk(KERN_DEBUG "Learn more\n");
	printk(KERN_INFO "Module removed successfully\n");
}


module_init(hellow_world_init);
module_exit(hellow_world_exit);

MODULE_AUTHOR("ANAND MOHAN TIWARI");
MODULE_DESCRIPTION("FIRST HELLO WORLD PROGRAM");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.0.1");
