/*
 * Aim: This program show to statically allocate the major and minor number
 * AUTHOR: ANAND MOHAN TIWARI
 * This code is system dependent not portable. See dynamic allocation
 */

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/version.h>





















static int __init amt_init ( void ){

	printk( KERN_INFO "Kernel module inserted Successfully\n" );

	return 0;
}

static void __exit amt_exit ( void ){

	printk( KERN_INFO "Kernel module successfully removed\n" );
	return;
}


module_init ( amt_init );
module_exit ( amt_exit );

MODULE_LICENSE ( "GPL");
MODULE_AUTHOR ( "ANAND MOHAN TIWARI")
MODULE_DESCRIPTION ("SHOWS HOW TO ASSIGN MAJOR AND MINOR NO STATICALLY")
MODULE_VERSION("0.0.3");




