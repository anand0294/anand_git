/*
 * This program shows the implementation of IOCTL call into driver
 * AUTHOR: ANAND MOHAN TIWARI
 */

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/version.h>
#include <linux/module.h>

#include <linux/cdev.h>
#include <linux/slab.h> //for kmalloc
#include <linux/uaccess.h> // for copy_to/from_user
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/ioctl.h>

/* Declaration of structure and variables*/
static struct class * amt_class;
static struct cdev amt_cdev;
dev_t amt_dev;
static int firstdevice=0;
static int noofdevice=1;

#define mem_size 1024

/*Creation of IOCTL call __IOX(magic no, command no, argument )*/
#define AMT_READ _IOR('a', 'a', int32_t *)
#define AMT_WRITE _IOW('a', 'b', int32_t *)
int32_t value=0;

/*Function declaration*/
static int __init amt_init ( void );
static void __exit amt_exit(void );
static int amt_open ( struct inode * inode, struct file * fp );
static int amt_release ( struct inode * inode, struct file * fp );
static ssize_t amt_write ( struct file * fp, const char * buff, size_t size, loff_t * offset );
static ssize_t amt_read ( struct file * fp, char __user * buff, size_t size, loff_t * offset );
static long amt_ioctl( struct file * fp, unsigned int cmd, unsigned long arg );

/*Registering all function with file_operations structue*/
struct file_operations amt_fops = {
	.owner		= THIS_MODULE,
	.open		= amt_open,
	.read		= amt_read,
	.write		= amt_write,
	.unlocked_ioctl = amt_ioctl,
	.release	= amt_release,

};

static int amt_open( struct inode * inode, struct file * fp ){
	printk( KERN_INFO "Open Operation invoked\n" );
	return 0;
}

static int amt_release ( struct inode * inode, struct file * fp ){
	printk( KERN_INFO "Close Operation invoked\n" );
	return 0;
}

static ssize_t amt_write ( struct file * fp, const char * buff, size_t size, loff_t * offset ){
	printk( KERN_INFO "Write Operation invoked\n" );
	return 0;
}

static ssize_t amt_read ( struct file * fp, char __user * buff, size_t size, loff_t * offset ){
	printk( KERN_INFO "Read Operation invoked\n" );
	return 0;
}


static long amt_ioctl( struct file * fp, unsigned int cmd, unsigned long arg ){
	switch(cmd){
		case AMT_WRITE:
				copy_from_user ( &value,(int32_t *)arg, sizeof( value )  );
				printk( KERN_INFO "Value written to kernel is %d\n", value );
				break;
		case AMT_READ:
				copy_to_user ( (int32_t *)arg, &value, sizeof( value ) );
				break;
	}
	return 0;
}

static int __init amt_init( void ){
	/*Allocating Major and Minor Number Automatically ( Portable code )*/
	if ( alloc_chrdev_region ( &amt_dev, firstdevice, noofdevice, "AMT_NODE_NUMBER") < 0 ){
		printk(KERN_INFO "Failed to allocate Major and Minor Number\n");
		return -1;
	}
	printk(KERN_INFO "Major No: %d, Minor No %d \n", MAJOR( amt_dev ), MINOR( amt_dev ) );
	
	/*Initializing Cdev structure with fops structure(Creating cdev structure) */
	cdev_init ( &amt_cdev, &amt_fops );
	/*Adding device file to the system*/
	if ( cdev_add ( &amt_cdev, amt_dev, noofdevice) < 0 ){
		printk(KERN_INFO "Failed to add device file to the system\n");
		return -1;
	}
	/* Creating class to create device file */
	amt_class = class_create (THIS_MODULE, "AMT_CLASS");
	if( amt_class == NULL ){
		printk(KERN_INFO "Failed to create class\n");
		goto r_class;
	}
	/*Creating device file For transparent comm. b/w user space and kernel space */
	if( device_create( amt_class, NULL, amt_dev, NULL, "MOHAN_CHAR_DRIVER" ) == NULL ){
		printk(KERN_INFO "Failed to create Device File\n");
		goto r_device;
	}
	printk(KERN_INFO "Kernel module inserted Successfully\n");
	return 0;
r_device:
	class_destroy( amt_class );
r_class:
	unregister_chrdev_region ( amt_dev, noofdevice );
	return -1;
}

static void __exit amt_exit ( void ){
	device_destroy ( amt_class, noofdevice );
	class_destroy( amt_class );
	cdev_del ( &amt_cdev );
	unregister_chrdev_region ( amt_dev, noofdevice );
	printk( KERN_INFO "Kernel Module Removed Successfully\n");
	return;
}

module_init ( amt_init );
module_exit ( amt_exit );

MODULE_LICENSE ( " GPL " );
MODULE_DESCRIPTION ( "Implementation of IOCTL Call" );
MODULE_AUTHOR ("ANAND MOHAN TIWARI");
MODULE_VERSION ("0.0.8");
