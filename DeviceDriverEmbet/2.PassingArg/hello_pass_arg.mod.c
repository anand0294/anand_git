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
	{ 0xbb084feb, __VMLINUX_SYMBOL_STR(param_ops_charp) },
	{ 0x209b187, __VMLINUX_SYMBOL_STR(param_ops_int) },
	{ 0xc6fb3cba, __VMLINUX_SYMBOL_STR(param_array_ops) },
	{ 0x50eedeb8, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xa5a2cf17, __VMLINUX_SYMBOL_STR(param_set_int) },
	{ 0xb4390f9a, __VMLINUX_SYMBOL_STR(mcount) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "5936E8B38F22AB561494C37");