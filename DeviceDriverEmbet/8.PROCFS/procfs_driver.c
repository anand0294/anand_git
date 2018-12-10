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
#include <linux/uaccess.h>
#include <linux/ioctl.h>
#include <linux/kdev_t.h>
#include <linux/device.h>

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
unsigned long amt_ioctl ( struct file * fp, unsigned int cmd, unsigned long arg );

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

static ssize_t amt_read( struct file * fp, const char * buff, size_t size, loff_t * offset ){
	printk(KERN_INFO "Read operation invoked...\n");
	return size;
}


unsigned long amt_ioctl ( struct file * fp, unsigned int cmd, unsigned long arg ){
	printk(KERN_INFO "IOCTL operation Invoked\n");
	switch(cmd){
		case AMT_RDVALUR:
			copy_to_user( (int32_t *)arg, &value, sizeof(value) );
			break;
		case AMT_WRVALUE:
			copy_form_user( &value, (int32_t *)arg, sizeof(value) );
			printk(KERN_INFO "Value written to kernel is : %d\n", value);
			break;
		default:
			printk(KERN_INFO "Wrong Argument passed from kernel\n");
			break;
	}
	return 0;
}

	/**Initialization Routine **/
static int __init amt_init(){
	if(){
		printk(KERN_INFO "Failed to allocate");
		return -1;
	}

	return 0;
r_device:
	class_destroy(amt_class);
r_class:
	unregister(amt_dev, noofdevice);

}
