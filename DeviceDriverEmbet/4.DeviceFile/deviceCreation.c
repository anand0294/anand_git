/*
 * This program shows how to create device file or node dynamically
 * Author : ANAND MOHAN TIWARI
 */

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/version.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/device.h>

static struct class * amt_class;
dev_t amt_dev=0;
static int firstminor =0;
static int count =1;
static char * name = "AMT_NODENo";
static int __init amt_init ( void ){
	/*****************Allocation of major and minor no dynamically**********************/
	int res ;
	res = alloc_chrdev_region( &amt_dev, firstminor , count, name );
	if( res <0 ){
		printk(KERN_INFO "Failed to allocate Major and Minor Number\n");
		return -1;
	}
	printk(KERN_INFO "Major No= %d, Minor No= %d\n", MAJOR( amt_dev ), MINOR( amt_dev ) );

	/***************Allocation of class for creating device file*************************/
	amt_class = class_create( THIS_MODULE, "amt_devClass" );
	if( amt_class == NULL ){
		printk(KERN_INFO "Failed to create Class for Device file\n");
		goto r_class;
	}
	/************ Creating Device file for transparent comm. b/w Application & DD *******/
	if( device_create( amt_class, NULL, amt_dev, NULL, "MohanDevice") ==NULL ){
		printk(KERN_INFO "Failed to create Device File\n");
		goto r_device;
	}
	printk(KERN_INFO "Kernel Module Inserted Successfully...\n");
	return 0;
r_device :
	class_destroy( amt_class );

r_class :
	unregister_chrdev_region( amt_dev, count );
	return -1;
}

static void __exit amt_exit( void ){
	device_destroy( amt_class, amt_dev );
	class_destroy( amt_class );
	unregister_chrdev_region( amt_dev, count );
	printk(KERN_INFO "Kernel Module Removed Successfully...\n");
	return;
}

module_init(amt_init);
module_exit(amt_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ANAND MOHAN TIWARI");
MODULE_DESCRIPTION("Shows to create device file");
MODULE_VERSION("0.0.5");
