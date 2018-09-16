#include<linux/module.h>
#include<linux/version.h>
#include<linux/kernel.h>
#include<linux/init.h>

//Module body starts
void func1(void);
EXPORT_SYMBOL_GPL(func1);

int val=300;

void func1(void){
	printk("Function1 Invoked\n");
	printk("Value : %d", val);
	return;

}

//Module body Ends

int init_mod(void){
	printk("Module 1 Inserted\n");
	return 0;
}

void cleanup_mod(void){
	printk("Module 1 removed\n");
	return;
}

module_init(init_mod);
module_exit(cleanup_mod);

MODULE_AUTHOR("ANAND MOHAN TIWARI DEVICE DRIVER DEVELOPER");
MODULE_DESCRIPTION("First Module");
MODULE_LICENSE("GPL");


