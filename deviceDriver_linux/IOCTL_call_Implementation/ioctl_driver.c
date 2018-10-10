/*
 *AUTHOR : ANAND MOHAN TIWARI
 * This program helps you understand the IOCTL call implementation
 * in driver.
 */

#include<linux/kernel.h>
#include<linux/version.h>
#include<linux/init.h>
#include<linux/module.h>

#include<linux/cdev.h>// to use device file structure
#include<linux/fs.h>// to use file_operations structure
#include<linux/uaccess.h>// to use copy_to/from_user functions
#include<linux/slab.h>// to use kmalloc functions.

static int __init amt_init(void){
	

return 0;
}
