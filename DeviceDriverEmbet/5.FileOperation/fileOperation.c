/*
 * This program shows the use of cdev and fileoperations structure
 * to perform open read and write etc operations.
 * AUTHOR: ANAND MOHAN TIWARI 
 */

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/version.h>

#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>

/**** Useful structures and variables ****/
static struct class * amt_class;
static struct cdev * amt_cdev;
dev_t amt_dev=0;
int firstdevice=0, count=1;

/**** Function Declarations ****/

static int __init amt_init ( void );
static void __exit amt_exit ( void );
static int amt_open ( struct inode *inode, struct file * file );
static int amt_release ( struct inode * inode, struct file * file );
static ssize_t amt_read ( struct file * file, char __user * buff, size_t size, loff_t * offset );
static ssize_t amt_write ( struct file * file, const char __user * buff, size_t size, loff_t * offset );

/*Registering open, read etc with file_operations*/
static struct file_operations amt_fops = {
	.owner = THIS_MODULE,
	.open  = amt_open,
	.read  = amt_read,
	.write = amt_write,
	.release = amt_release
};

static int amt_open ( struct inode * inode, struct file * file ){
	printk(KERN_INFO "Open Operation Invoked\n");
	return 0;
}

static int amt_release ( struct inode * inode , struct file * file ){
	printk(KERN_INFO "Release Operation Invoked\n");
	return 0;
}

static ssize_t amt_read ( struct file * file, char __user * buff, size_t size, loff_t * offset ){
	printk(KERN_INFO "Read Operation Invoked\n");
	return size;
}

static ssize_t amt_write ( struct file * file, const char __user * buff, size_t size, loff_t * offset ){
	printk(KERN_INFO "Write operation Invoked\n");
	return size;
}

static int __init amt_init ( void ){
	
	/******* Dynamic Allocation of major and minor number *******/
	if ( alloc_chrdev_region( &amt_dev, firstdevice, count, "INODE_NUMBER") < 0 ){
		printk(KERN_INFO "Failed to allocate Major and Minor number\n");
		return -1;
	}
	printk(KERN_INFO "MAJOR NO:%d MINOR NO: %d \n", MAJOR( amt_dev ), MINOR( amt_dev ) );
	
	/***** Registering struct file_operations to cdev structure to perform read, write etc operations *****/
	amt_cdev = cdev_alloc();
	cdev_init( amt_cdev, &amt_fops );
	if( cdev_add ( amt_cdev, amt_dev, count ) < 0 ){
		printk(KERN_INFO "Failed to add cdev into dev file\n");
		goto r_class;
	}
	/***** Creating Class *****/
	amt_class = class_create ( THIS_MODULE, "amt_DeviceClass" );
	if ( amt_class == NULL ){
		printk(KERN_INFO "Failed to create Class\n");
		goto r_class;
	}
	if ( device_create ( amt_class, NULL, amt_dev, NULL, "MOHAN_CHARACTER_DRIVER") == NULL ){
		printk(KERN_INFO "Failed to Create Device File\n");
		goto r_device;
	}
	printk(KERN_INFO "Kernel Module inserted Successfully\n");
	return 0;

r_device:
	class_destroy( amt_class );
r_class:
	unregister_chrdev_region( amt_dev, count );
	return -1;
}

static void __exit amt_exit ( void ){
	device_destroy(amt_class, count);
	class_destroy( amt_class );
	cdev_del(amt_cdev);
	unregister_chrdev_region( amt_dev, count );
	printk(KERN_INFO "Kernel Module Removed Successfully\n");
	return;
}

module_init ( amt_init );
module_exit ( amt_exit );

MODULE_LICENSE( "GPL" );
MODULE_DESCRIPTION( "Dummy Driver Implementation of Character Driver");
MODULE_AUTHOR("ANAND MOHAN TIWARI");
MODULE_VERSION( "0.0.6" );
