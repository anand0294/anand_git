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

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x9869a9ec, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xe7a13348, __VMLINUX_SYMBOL_STR(device_destroy) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0x41d85b31, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0xb7d9081c, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0x5cc2363, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0x43cd65e1, __VMLINUX_SYMBOL_STR(device_create) },
	{ 0x753a7087, __VMLINUX_SYMBOL_STR(__class_create) },
	{ 0x1864648c, __VMLINUX_SYMBOL_STR(cdev_alloc) },
	{ 0x29537c9e, __VMLINUX_SYMBOL_STR(alloc_chrdev_region) },
	{ 0x4f8b5ddb, __VMLINUX_SYMBOL_STR(_copy_to_user) },
	{ 0x4f6b400b, __VMLINUX_SYMBOL_STR(_copy_from_user) },
	{ 0xf1687b4b, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x5af6d1c5, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x50eedeb8, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xb4390f9a, __VMLINUX_SYMBOL_STR(mcount) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "07671C0222DB05F50DD7A8D");
