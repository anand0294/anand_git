/* Motto : Learning purpose. This program demonstrate the basic character 
 * driver implementation, we manually assign the major and minor no to the 
 * device and the name of charcter driver using mknod command.
 * This program is a dummy driver used only of learning purpose.
 * Author : ANAND MOHAN TIWARIi(amt)
 */

/*Basic kernel header file which deal with initialization,
 *version, kernel module etc*/
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/version.h>

/*For dynamic memory Allocation Api like kmalloc*/
#include <linux/slab.h>

/*const struct file_operations structure is defined in below header file*/
#include <linux/fs.h>

/*dev_t structure is defined here and is used to hold Major&minor no.*/
#include <linux/types.h> 

/*For Cdev structure*/
#include <linux/cdev.h>

/*copy_to_user and copy_from_user API's defined in below header file*/
#include <linux/uaccess.h>


/* Allcating Major no and Minor no manually*/
#define MAJORNO 300
#define MINORNO 0
#define MAX_LENGTH 4000
/*Use this for Device file name which allow transparent communication between user 
 *space apllication and hardware. To create see txt file in this folder.
 * To create Device file see .txt file in the folder.
 */
#define DEVICE_NAME "static_charDev"

/*Assigning major and minor number to dev*/
dev_t dev= MKDEV(MAJORNO, MINORNO);
int inuse=0, count=1;

static const char chr_dev_buf[MAX_LENGTH];//Internal buffer
static struct cdev * amt_cdev;


/*Function declaration*/
static int __init amt_driver_init(void);
static void __exit amt_driver_exit(void);
static int amt_open(struct inode * inode, struct file * file);
static int amt_release(struct inode *, struct file * file);
static ssize_t amt_read(struct file * file,const char * buff, size_t len, loff_t * presentOffset );
static ssize_t amt_write(struct file * file, const char * buff, size_t len, loff_t * presentOffset );


/*Function Definition*/

static int amt_open(struct inode * inode, struct file * file){
	if(inuse ){
		printk(KERN_INFO "Device BUSY %s\n",DEVICE_NAME);
		return -EBUSY;
	}
	inuse =1;
	printk("Open Operation Invoked\n");
	return 0;
}


static int amt_release(struct inode * inode, struct file * file){
	inuse=0;
	return 0;
}


static ssize_t amt_write(struct file * file, const char * buff/*Coming data*/, size_t len, loff_t * presentOffset){
	/*Copy data from user space to kernel space using function copy_from_user*/
	int NoOfByte = len - copy_from_user( (chr_dev_buf + *presentOffset), *buff,len );	
	*presentOffset += NoOfByte;
	printk(KERN_INFO "Recived data is : %s , Number of Bytes is : %d\n",chr_dev_buf, NoOfByte);
	return NoOfByte;
}


static ssize_t amt_read(struct file * file, const char * buff, size_t len, loff_t * presentOffset){
	/*Copies a block of data from the kernel to user space using function copy_to_user*/
	int NoOfByte = len - copy_to_user((chr_dev_buf + *presentOffset), buff, len);
	*presentOffset +=NoOfByte;
	return NoOfByte;
}

/*Registering function fops structure*/
const struct file_operations fops = {
	.owner	 = THIS_MODULE,
	.open	 = amt_open,
	.read	 = amt_read,
	.write	 = amt_write,
	.release = amt_release

};

/*Initialization routine of your character device driver*/
static int  __init amt_driver_init(void){
int ret;
	if((register_chrdev_region(dev, 0, DEVICE_NAME))<0){
		printk("Error in allocating major number\n");
		return -1;
	}
	printk(KERN_INFO "Major No: %d, Minor No: %d\n",MAJOR(dev), MINOR(dev));
	printk(KERN_INFO "Kernel Module Inserted Successfully....\n");
	/*Creating cdev structure*/
	amt_cdev = cdev_alloc();
	cdev_init(amt_cdev, &fops);

	 /*Adding character device to the system*/
	ret = cdev_add(amt_cdev, dev, count);/*count is 1 here see declaration above*/
	if(ret<0){
		printk(KERN_INFO "Error in registering\n");
		return ret;
	}
	memset(chr_dev_buf, '\0', MAX_LENGTH);
	return 0;
}

/*Exit routine of your character driver*/
static void __exit amt_driver_exit(void){
	cdev_del(amt_cdev);
	unregister_chrdev_region(amt_cdev, 1);
	printk(KERN_INFO "Kernel Module removed Successfully****\n");

}

module_init(amt_driver_init);//Used to initialize your init function
module_exit(amt_driver_exit);//used to initialize your exit function

MODULE_DESCRIPTION("Basic and static implementation of a character device driver");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("ANAND MOHAN TIWARI");
