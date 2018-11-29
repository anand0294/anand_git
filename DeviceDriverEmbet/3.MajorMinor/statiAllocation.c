/*
 * Aim: This program show to statically allocate the major and minor number
 * AUTHOR: ANAND MOHAN TIWARI
 * This code is system dependent not portable. See dynamic allocation
 */

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/version.h>
#include <linux/fs.h>
#include <linux/types.h>

dev_t deviceId = MKDEV( 300, 0 );
int count = 1;
char * name = "/dev/ANAND";

static int __init amt_init ( void ){
	int res;
	res = register_chrdev_region( deviceId, count, name );
	if(res == 0){
		printk(KERN_INFO "Failed to allocate device id\n");
		return -1;
	}
	printk( KERN_INFO "MAJOR NO= %d , MINOR NO= %d\n",MAJOR( deviceId ), MINOR( deviceId ) );
	printk( KERN_INFO "Kernel module inserted Successfully\n" );
	return 0;
}

static void __exit amt_exit ( void ){
	unregister_chrdev_region( deviceId, count );
	printk( KERN_INFO "Kernel module successfully removed\n" );
	return;
}


module_init ( amt_init );
module_exit ( amt_exit );

MODULE_LICENSE ( "GPL");
MODULE_AUTHOR ( "ANAND MOHAN TIWARI");
MODULE_DESCRIPTION ("SHOWS HOW TO ASSIGN MAJOR AND MINOR NO STATICALLY");
MODULE_VERSION("0.0.3");




