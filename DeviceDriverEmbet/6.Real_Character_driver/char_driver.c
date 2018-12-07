/*
 * This program shows you to create a real character device driver.
 * In this driver we will perform open,read, write and close operations.
 * AUTHOR: ANAND MOHAN TIWARI
 */

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/version.h>
#include <linux/module.h>

#include <linux/cdev.h>     //for cdev_init and cdev_add
#include <linux/uaccess.h> //for copy_to/from_user
#include <linux/kdev_t.h> //for class creation
#include <linux/device.h> // for device creation
#include <linux/slab.h> //for kmalloc and kfree
#include <linux/fs.h>

/**Basic structure and variable declarations**/
struct class * amt_structclass;
struct cdev amt_cdev;
dev_t amt_dev=0;

int firstDeviceNo=0;
int NoOfDevice=1;

#define mem_size 1024

uint8_t * kernel_buffer;

/**Function declaration**/
static int __init amt_init ( void );
static void __exit amt_exit ( void );

static int amt_open ( struct inode * inode, struct file * fp);
static int amt_release ( struct inode * inode, struct file * fp );
static ssize_t amt_read ( struct file * fp, char __user * buff, size_t size, loff_t * off );
static ssize_t amt_write ( struct file * fp, const char __user * buff, size_t size, loff_t * off );

/**Initialization of function with file_operatons structure to perform RD/WR operations**/
static struct file_operations amt_fops = {
	.owner  = THIS_MODULE,
	.open   = amt_open,
	.read   = amt_read,
	.write  = amt_write,
	.release= amt_release,
};

	/**Function definition**/
static int amt_open(	struct inode * inode , struct file * fp ) {
	/*Creating Physical memory*/
	if( (kernel_buffer = kmalloc (mem_size, GFP_KERNEL) ) ==0 ){
		printk(KERN_INFO "Failed to allocate memory\n");
		return -1;
	}
	printk(KERN_INFO "Device File Opened....!!! \n" );
	return 0;
}

static int amt_release (struct inode * inode , struct file *fp ) {
	kfree( kernel_buffer );
	printk(KERN_INFO "Device file closed\n");
	return 0;
}

static ssize_t amt_read ( struct file *fp, char __user * buff, size_t size, loff_t * off ) {
	copy_to_user( buff, kernel_buffer, mem_size );
	printk(KERN_INFO "User will reads : %s \n", buff );
	printk(KERN_INFO "Data Reads .... Done!!!\n");
	return mem_size;
}

static ssize_t amt_write ( struct file * fp, const char __user * buff, size_t size, loff_t * off ){
	copy_from_user( kernel_buffer, buff, size );
	printk(KERN_INFO "Kernel reads : %s \n", kernel_buffer );
	printk(KERN_INFO "Data writes .... Done!!!\n");
	return size;
}

/**Driver Initialization Routine**/
static int __init amt_init( void ){
	/*Allocating Major and Minor Number Dynamically*/
	if( alloc_chrdev_region ( &amt_dev, firstDeviceNo, NoOfDevice, "MOHAN_NODE" ) < 0 ){
		printk(KERN_INFO "Failed to assign Major and Minor Number\n");
		return -1;
	}	
	printk(KERN_INFO "Node number assigned successfully Major No: %d,\
			 Minor No: %d\n", MAJOR(amt_dev), MINOR(amt_dev) );
	
	/*Creating Cdev structure*/
	cdev_init( &amt_cdev, &amt_fops);

	/*Adding character device to system*/
	if( cdev_add ( &amt_cdev, amt_dev, NoOfDevice ) <0){
		printk(KERN_INFO "Failed To Add Character Driver to the system\n");
		goto r_class;
	}

	/*Creating Class for Device File*/
	amt_structclass = class_create ( THIS_MODULE, "amt_class" );
	if(amt_structclass == NULL ){
		printk(KERN_INFO "Failed to Create class\n");
		goto r_class;
	}

	/*Creating Device File*/
	if( device_create(amt_structclass, NULL, amt_dev, NULL, "MOHAN_DRIVER") == NULL ){
		printk(KERN_INFO "Failed to create Device File(Device)\n");
		goto r_device;
	}

	printk("Kernel Module Inserted Successfully\n");
	return 0;
r_device:
	class_destroy(amt_structclass);
r_class:
	unregister_chrdev_region( &amt_dev, NoOfDevice );	
	return -1;
}


static void __exit amt_exit ( void ){
	device_destroy ( amt_structclass, amt_dev );
	class_destroy ( amt_structclass );
	cdev_del ( &amt_cdev );
	unregister_chrdev_region( amt_dev, NoOfDevice );
	return;
}

module_init ( amt_init );
module_exit ( amt_exit );

MODULE_LICENSE ( " GPL ");
MODULE_DESCRIPTION ( " REAL CHARACTER DRIVER IMPLEMENTATION " );
MODULE_AUTHOR ( " ANAND MOHAN TIWARI " );
MODULE_VERSION ( "0.0.7" );
