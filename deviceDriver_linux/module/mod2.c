#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/version.h>

void func(void);

EXPORT_SYMBOL(func);//func exported

static int val =200;

void func(void){
	printk("Function Invoked : Value = %d\n", val);
	return;
}

void fun(void){
	printk("Second function invoked\n");
	return;
}

int myinit(void){
	printk("Module 2 Inserted\n");
	return 0;
}

void myexit(void){
	printk("Module 2 Removed\n");
	return;
}

module_init(myinit);
module_exit(myexit);

MODULE_AUTHOR("MOHAN");
MODULE_DESCRIPTION("INSERT FUNCTION INTO MODULE");
MODULE_LICENSE("GPL");
