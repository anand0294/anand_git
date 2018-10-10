/*
 * AUTHOR : ANAND MOHAN TIWARI
 * This program describes to dynamically allocate Inode(Major and Minor)
 * number, automatic file creation and Registering the open,read, write
 * and release call with file operation structure.
 */


#include<linux/init.h>
#include<linux/version.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/uaccess.h>//for copy_to_user/copy_from_user
#include<linux/slab.h>//for dynamic memory allocation api's like kmalloc.
#include<linux/types.h>// for dev_t which holds major and minor no
#include<linux/fs.h>//for file_operations structure
#include<linux/cdev.h> //Both cdev_init() and cdev_add() are declared here.

/***************************************************************************
 **For Automatic device file Creation                                     **
 **Step1:Include the header file linux/device.h and linux/kdev_t.h        **
 **The automatic creation of device files can be handled with udev.       ** 
 **Udev is the device manager for the Linux kernel that creates/removes   **
 **device nodes in the /dev directory dynamically.                        **
 ***************************************************************************/
#include<linux/kdev_t.h>
#include<linux/device.h>


#define CHR_DEV_NAME "dynamic_device"
#define SUCCESS 0
#define mem_size 2000

uint8_t * kernel_buffer;
dev_t maj_no;

static char * driver_buff = "This is the data from Character device Driver";
//static char * buffer;
static struct cdev * deviceFile;
struct class *deviceClass;

/* Function Declaration : */
static int __init dynamic_alloc_init(void);
static void __exit dynamic_alloc_exit(void);
static int amt_open(struct inode * inode, struct file * fd);
static int amt_release(struct inode * inode, struct file * fd);
static ssize_t amt_read(struct file * fd, char __user * buffer, size_t len, loff_t * pos);
static ssize_t amt_write(struct file * fd,  char * buffer, size_t len, loff_t * pos);

/*Registering the functions  with file_operations*/
static struct file_operations virtualFileSystem = {
	.owner   = THIS_MODULE,
	.read    = amt_read,
	.write   = amt_write,
	.open    = amt_open,
	.release = amt_release,
};

/*Function Definitions*/
/*Implementation of open function*/
static int amt_open(struct inode * inode, struct file * fd){
	 /*Creating Physical memory*/
        if((kernel_buffer =(void * )kmalloc(mem_size , GFP_KERNEL)) == 0){
            printk(KERN_INFO "Cannot allocate memory in kernel\n");
            return -1;
        }
	printk(KERN_INFO "Open Operation Invoked\n");
	return SUCCESS;
}
static int amt_release(struct inode * inode, struct file * fd){
	kfree(kernel_buffer);
	printk("Relese operation Invoked and allocated memory is released\n");
	return SUCCESS;
}

static ssize_t amt_read(struct file * fd, char __user * buffer, size_t len, loff_t *pos){
	int noOfbytes;
	noOfbytes = (len - copy_to_user(buffer/*to*/,driver_buff/*from*/ + *pos, len/*How many bytes*/));
	noOfbytes +=*pos;
	printk(KERN_INFO "Data Received is : %s\n , No of bytes : %d\n", driver_buff, noOfbytes);
return noOfbytes;
}


static ssize_t amt_write(struct file * fd, char * buffer, size_t len, loff_t * pos){
	int noOfbytes;
/*Copy data from user space to kernel space using function copy_from_user*/
	noOfbytes = (len - copy_from_user(buffer + *pos, buffer, len));
	noOfbytes +=*pos;
	printk(KERN_INFO "Data Received is : %s\n , No of bytes : %d\n", buffer, noOfbytes);
//	*pos=0;
//	copy_to_user(buffer + *pos, buffer, len);
	return noOfbytes;

}

/*Module Initialization routine : Constructor*/
static int __init dynamic_alloc_init(void){

/*****************************************************************
 **int alloc_chrdev_region(dev_t *dev, unsigned int firstminor, **
 **				unsigned int count, char *name);**
 **Allocating Major number Dynamically                          **
 *****************************************************************/

	if((alloc_chrdev_region(&maj_no,0, 1, CHR_DEV_NAME))<0){
		printk(KERN_ERR "Cannot allocate major number For the device\n");
		return -1;
	}

	if(!(deviceFile = cdev_alloc())){
		printk(KERN_ERR "failed to perform cdev_alloc operation");
		goto r_class; //to unregister character driver major no:
	}

/*************************************************************************
 ** For Automatic device file Creation                                  **
 **Step2.Create the class                                               **
 **This will create the struct class for our device driver.             **
 **It will create structure under/sys/class/                            **
 **struct class * class_create (struct module *owner, const char *name);**
 **owner – pointer to the module that is to “own” this struct class     **
 **name – pointer to a string for the name of this class                **
 **This is used to create a struct class pointer that can then be used  **
 **in calls to class_device_create.                                     **
 *************************************************************************/
	deviceClass = class_create(THIS_MODULE, "amt_class");
	if(deviceClass==NULL){
		printk(KERN_ERR "Cannot create device file\n");
		goto r_class;

	}
/**************************************************************************
 ** For Automatic device file creation Step 3: Last step                 **
 **This function can be used by char device classes. A struct device will**
 **be created in sysfs, registered to the specified class.               **
 **struct device *device_create (struct *class, struct device *parent,   **
 **                            dev_t dev, const char *fmt, ...);         **
 **class–pointer to the structclass thatthis device shouldbe registeredto**
 **parent– pointer to the parent struct device of this new device, if any**
 **devt – the dev_t for the char device to be added                      **
 **fmt  – string for the device’s name                                   **
 **   … – variable arguments                                             **
 **************************************************************************/

	if(device_create(deviceClass, NULL, maj_no,NULL, CHR_DEV_NAME)==NULL){
		printk(KERN_ERR "Cannot create device\n");
		goto r_device;
	}
/**************************************************************************
 ** In case of multiple minors, the device_create() and device_destroy() **
 ** APIs may be put in the for loop, and the <device name format> string **
 ** could be useful. For example, the device_create() call in a for loop **
 ** indexed by i could be as follows:                                    **
 ** device_create(cl, NULL, MKNOD(MAJOR(first), MINOR(first) + i),       **
 **						NULL, "mynull%d", i);    **
 **************************************************************************/

/**********************************************************************************
 ** cdev_init() - used to initialize struct cdev with the defined file_operations**
 ** cdev_add()  - used to add a character device to the system.                  **
 ** After a call to cdev_add(), your device is immediately alive                 **
 **cdev_init — initialize a cdev structure                                       **
 **Synopsis :void cdev_init(struct cdev * cdev,const struct file_operations*fops);*
 ** Arguments : struct cdev * cdev :: the structure to initialize                **
 ** const struct file_operations * fops  the file_operations for this device     **
 ** Description : Initializes cdev, remembering fops, making it ready to add to  **
 ** the system with cdev_add.                                                    **
 ** void cdev_init(struct cdev *cdev, struct file_operations *fops);             **
 ** Once the cdev structure is set up with file_operations and owner, the final  **
 ** step is to tell the kernel about it with a call to:                          **
 ** int cdev_add(struct cdev *dev, dev_t num, unsigned int count);               **
 **********************************************************************************/
	cdev_init(deviceFile, &virtualFileSystem);
//	deviceFile.owner = THIS_MODULE;
 //       deviceFile.ops = &virtualFileSystem;

	if((cdev_add(deviceFile, maj_no, 1))<0){
		printk(KERN_INFO "Cannot add the device to the system\n");
            goto r_class;
        }
	printk(KERN_INFO "Major Number =%d  Minor Number = %d \n", MAJOR(maj_no),MINOR(maj_no));
	printk(KERN_INFO "Kernel module : %s inserted successfully\n",CHR_DEV_NAME);
	return 0;

r_device :
		class_destroy(deviceClass);

r_class :
	unregister_chrdev_region(maj_no,1);
	return -1;
}

/*Module Exit routine : Destructor*/

static void __exit dynamic_alloc_exit(void){

/***********************************************************
 **you can destroy the device using device_destroy().     **
 **void device_destroy (struct class * class, dev_t devt);**
 ***********************************************************/
	device_destroy(deviceClass,maj_no);

/*************************************************************
 **the pointer created here is to be destroyed when finished**
 ** by making a call to class_destroy.                      **
 **void class_destroy (struct class * cls);                 **
 *************************************************************/

        class_destroy(deviceClass);

	unregister_chrdev_region(maj_no, 1);
	printk(KERN_INFO "Kernel module removed successfully\n");
}

module_init(dynamic_alloc_init);
module_exit(dynamic_alloc_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Dynamic allocation of Major number Device file creation\n");
MODULE_AUTHOR("ANAND MOHAN TIWARI");
MODULE_VERSION("1.0");

