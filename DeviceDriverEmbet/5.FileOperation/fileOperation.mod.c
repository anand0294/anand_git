#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x83784ea9, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xce9b5364, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0x624d5a2a, __VMLINUX_SYMBOL_STR(device_destroy) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0x5cc2363, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0xd552c68e, __VMLINUX_SYMBOL_STR(device_create) },
	{ 0x753a7087, __VMLINUX_SYMBOL_STR(__class_create) },
	{ 0x31512a4a, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0xb4175b6b, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0xa43d912, __VMLINUX_SYMBOL_STR(cdev_alloc) },
	{ 0x29537c9e, __VMLINUX_SYMBOL_STR(alloc_chrdev_region) },
	{ 0x50eedeb8, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xb4390f9a, __VMLINUX_SYMBOL_STR(mcount) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "ED404BE41C625E242903209");
