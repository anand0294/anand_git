/*
 * This program shows to allocate major and minor number dynamically
 * Author: ANAND MOHAN TIWARI
 */

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/version.h>
#include <linux/types.h>
#include <linux/fs.h>

dev_t deviceId;
int count =1;
int firstminor = 0;


static int __init amt_init ( void ) {
	int res;
	res = alloc_chrdev_region ( &deviceId, firstminor, count, "/dev/ANAND");
	if( res < 0 ){
		printk(KERN_INFO "FAILED to assign major and minor no\n");

	}
	printk(KERN_INFO "MAJOR NO= %d MINOR NO= %d\n", MAJOR ( deviceId ), MINOR ( deviceId ) );
	printk(KERN_INFO "Kernel module inserted successfuly\n");
	return 0;
}


static void __exit amt_exit ( void ){

	unregister_chrdev_region( deviceId, count );
	printk(KERN_INFO "Kernel module removed successfully\n");
	return;
}


module_init ( amt_init );
module_exit ( amt_exit );

MODULE_LICENSE ( "GPL" );
MODULE_DESCRIPTION ( "SHOWS HOW TO ALLOCATE MAJOR AND MINOR " );
MODULE_AUTHOR ( "ANAND MOHAN TIWARI " );
MODULE_LICENSE ( "0.0.4" );
