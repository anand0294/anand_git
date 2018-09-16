#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/version.h>

extern void func(void);
extern void func1(void);

static __init int mmyinit(void){ 
	//Indicating the kernel that this part is initializer
	printk("Calling Kernel Symbol\n");
	func();
	func1();
	return 0;
}

static __exit void mmyexit(void){
	//This part is exit routine
	printk("Cleanup Invoked\n");

}

module_init(mmyinit);
module_exit(mmyexit);

MODULE_AUTHOR("MOHAN");
MODULE_DESCRIPTION("Using mod2.c function in this program");
MODULE_LICENSE("GPL");
