#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/version.h>
#include<linux/moduleparam.h>

void foo(void);
void foo1(void);

static int val =0;

//module_param(val, int, S_IRUGO); // for read only
module_param(val, int, S_IWUSR);
MODULE_PARM_DESC(val, "INTIALISE ME AT INSERTION TIME");
MODULE_SUPPORTED_DEVICE(NULL);

void foo(void){
	printk("Foo invoked : Value = %d\n", val);
return;
}

void foo1(void){

	printk("Foo1 Invoked\n");
return;
}


int myinit(void){
	printk("Module3 Inserted\n");
	foo();
	return 0;
}

void myexit(void){
	printk("Module3 Removed\n");
return;
}

module_init(myinit);
module_exit(myexit);


MODULE_AUTHOR("MOHAN");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("INITIALIZATION OF VARIABLE AT RUN TIME");
