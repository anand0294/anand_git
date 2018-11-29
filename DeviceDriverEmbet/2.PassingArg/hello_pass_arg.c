/*
 * This module describe how to pass arguments to driver. 
 * AUTHOR : ANAND MOHAN TIWARI
 */

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h> /*To use module_param(); module_param_array(); module_param_cb*/
#include <linux/version.h>

int valueAMT= 5, arrayAMT[4] ;
char * nameAMT ;
int cb_valueAMT = 0;

module_param ( valueAMT, int, S_IRUSR|S_IWUSR );  /*Passing integer value*/
module_param ( nameAMT, charp, S_IRUSR|S_IWUSR ); /*Passing string as parameter*/
module_param_array ( arrayAMT, int, NULL, S_IRUSR|S_IRUSR ); /*Passing Array as parameter*/

/*********************************Call back function implementation ************************************************************/

int notify_param(const char * val, const struct kernel_param * kp ){

	int res;
	res = param_set_int(val, kp);
	if(res == 0){
		printk(KERN_INFO "Callback function is called\n");
		printk(KERN_INFO "New value of cb_valueAMT =%d\n", cb_valueAMT );
	
	}
	return -1;
}

struct kernel_param_ops my_kernel_param =
{
	.set = notify_param, /*Our implementation to set value*/
	.get = param_set_int, /*To get value*/
};

module_param_cb ( cb_valueAMT, &my_kernel_param, &cb_valueAMT, S_IRUSR|S_IWUSR|S_IXUSR|S_IRWXG );

/*********************************************************************************************************************************/

static int __init amt_init ( void ){
	
	int i;
	printk(KERN_INFO "ValueAMT =%d \n", valueAMT );
	printk(KERN_INFO "cb_valueAMT =%d \n", cb_valueAMT );
	printk(KERN_INFO "nameeAMT =%s \n", nameAMT );
	for(i=0; i< ( sizeof( arrayAMT)/sizeof(int) ); i++ )
		printk(KERN_INFO "Array[%d] = %d ",i, arrayAMT[i] );
	printk(KERN_INFO "\n Kernel module inserted successfully\n");

	return 0;
}


static void __exit amt_exit ( void ){

	printk(KERN_INFO "\nKernel modeule Removed Successfully\n");
	return;
}


module_init ( amt_init );
module_exit ( amt_exit );

MODULE_LICENSE (" GPL ");
MODULE_DESCRIPTION ( "THIS MODULE SHOW HOW TO PASS ARGUMENTS TO KERNEL" );
MODULE_AUTHOR (" ANAND MOHAN TIWARI ");
MODULE_VERSION ( "0.0.2" ); 
