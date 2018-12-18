/*
 * This program shows how to communicate with kernel through
 * proc file system.
 * AUTHOR: ANAND MOHAN TIWARI
 */
#include <linux/kernel.h>
#include <linux/version.h>
#include <linux/init.h>
#include <linux/module.h>

#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/ioctl.h>
#include <linux/kdev_t.h>
#include <linux/device.h>
#include <linux/proc_fs.h>

#define AMT_WRVALUE _IOW('a', 'a', int32_t * )
#define AMT_RDVALUE _IOR('a', 'b', int32_t * )

/*Variable declarations*/
int32_t value=0;
char array[20]="mohan_proc_array\n";
static int len=1;

/*Structure Declarations*/
struct class * amt_class;
struct cdev amt_cdev;
dev_t amt_dev;
static int noofdevice=1;
static int firstminor=0;

/*Driver Function declaration*/

static int __init amt_init ( void );
static void __exit amt_exit ( void );
static int amt_open (struct inode * inode, struct file * fp );
static int amt_release ( struct inode * inode, struct file * fp );
static ssize_t amt_read (struct file * fp, char __user * buff, size_t size, loff_t * offset );
static ssize_t amt_write ( struct file * fp, const char * buff, size_t size, loff_t * offset );
static long amt_ioctl ( struct file * fp, unsigned int cmd, unsigned long arg );

/*****procfs entry*****/
static int proc_open(struct inode * inode , struct file * fp );
static int proc_release(struct inode * inode, struct file * fp );
static ssize_t proc_read (struct file * fp, char __user * buff, size_t size, loff_t * offset );
static ssize_t proc_write ( struct file * fp, const char * buff, size_t size, loff_t * offset );


static struct file_operations amt_fops = {
	.owner		= THIS_MODULE,
	.open		= amt_open,
	.read		= amt_read,
	.write		= amt_write,
	.unlocked_ioctl = amt_ioctl,
	.release	= amt_release,

};

static struct file_operations proc_fops = {
	.open	= proc_open,
	.read	= proc_read,
	.write	= proc_write,
	.release= proc_release,
};


/**Proc file system function definition**/

static int proc_open(struct inode * inode, struct file * fp ){
	printk(KERN_INFO "Proc file opened........\n");
	return 0;
}

static int proc_release(struct inode * inode, struct file * fp ){
	printk(KERN_INFO "Proc file released.......\n");
	return 0;
}

static ssize_t proc_read(struct file * fp, char __user *buff, size_t size, loff_t * offset ){

	printk(KERN_INFO "Proc read operation invoked...\n");
	if(len)
		len=0;
	else {
		len=1;
		return 0;
	}
	copy_to_user ( buff, array, 20 );
	return size;
}

static ssize_t proc_write( struct file * fp, const char * buff, size_t size, loff_t * offset ){
	printk(KERN_INFO "Proc write operation invoked...\n");
	copy_from_user( array, buff, 20);
	return size;
}

/**Driver function definition**/
static int amt_open(struct inode * inode, struct file * fp ){
	printk(KERN_INFO "Open operation invoked ........\n");
	return 0;
}

static int amt_release(struct inode * inode, struct file * fp ){
	printk(KERN_INFO "Release Operation invoked.......\n");
	return 0;
}


static ssize_t amt_write( struct file * fp, const char * buff, size_t size, loff_t * offset ){
	printk(KERN_INFO "Write operation invoked...\n");
	return size;
}

static ssize_t amt_read( struct file * fp, char __user * buff, size_t size, loff_t * offset ){
	printk(KERN_INFO "Read operation invoked...\n");
	return size;
}


static long amt_ioctl ( struct file * fp, unsigned int cmd, unsigned long arg ){
	printk(KERN_INFO "IOCTL operation Invoked\n");
	switch(cmd){
		case AMT_RDVALUE:
			copy_to_user( (int32_t *)arg, &value, sizeof(value) );
			break;
		case AMT_WRVALUE:
			copy_from_user( &value, (int32_t *)arg, sizeof(value) );
			printk(KERN_INFO "Value written to kernel is : %d\n", value);
			break;
		default:
			printk(KERN_INFO "Wrong Argument passed from kernel\n");
			break;
	}
	return 0;
}

	/**Initialization Routine **/
static int __init amt_init( void ){
	/*Allocation of Major and Minor Number*/
	if( ( alloc_chrdev_region (&amt_dev, firstminor, noofdevice, "AMT_NODENO") ) < 0 ){
		printk(KERN_INFO "Failed to allocate Major and Minor no\n");
		return -1;
	}
	printk(KERN_INFO "Major No: %d, Minor No: %d\n", MAJOR(amt_dev), MINOR(amt_dev) );
	
	/* Adding cdev structure with file_operations*/

	cdev_init( &amt_cdev, &amt_fops );
	
	/*Addition of Device to the system*/
	if( cdev_add( &amt_cdev, amt_dev, noofdevice ) < 0){
		printk(KERN_INFO "Failed to add device to the system\n");
		goto r_class;
	}

	/*Creating class structure*/
	amt_class = class_create( THIS_MODULE, "AMT_CLASS");
	if( amt_class == NULL ){
		printk(KERN_INFO "Failed to create Class\n");
		goto r_class;
	}
	
	/*Creating Device*/
	if( device_create (amt_class, NULL, amt_dev, NULL, "MOHAN_CHAR_DRIVER") == NULL ){
		printk(KERN_INFO "Failed to create device in the system\n");
		goto r_device;
	}

	/*Creating proc entry*/
	proc_create ("amt_proc", 0666,NULL, &proc_fops );
	printk(KERN_INFO "Kernel Inserted Successfully\n");

	return 0;
r_device:
	class_destroy(amt_class);
r_class:
	unregister_chrdev_region ( amt_dev, noofdevice );
	return -1;
}


static void __exit amt_exit ( void ){
	remove_proc_entry("amt_proc", NULL );
	device_destroy( amt_class, noofdevice );
	class_destroy( amt_class );
	cdev_del( &amt_cdev );
	unregister_chrdev_region( amt_dev, noofdevice );
	printk(KERN_INFO "Kernel module removed successfully...\n");
	return;
}


module_init ( amt_init );
module_exit ( amt_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Shows to create proc entry");
MODULE_AUTHOR("ANAND MOHAN TIWARI");
MODULE_VERSION ("0.0.9");
