#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

#ifdef CONFIG_UNWINDER_ORC
#include <asm/orc_header.h>
ORC_HEADER;
#endif

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x6729d3df, "__get_user_4" },
	{ 0x80828878, "find_vpid" },
	{ 0x1d174c76, "pid_task" },
	{ 0xe2491b52, "pcpu_hot" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0xada84b28, "device_destroy" },
	{ 0xa9edd0d8, "class_destroy" },
	{ 0x78445a7c, "cdev_del" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x932aac8c, "class_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0x1421f594, "device_create" },
	{ 0x21be7f7b, "cdev_init" },
	{ 0x54c057fa, "cdev_add" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x122c3a7e, "_printk" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xc6cbbc89, "capable" },
	{ 0xb7d4f963, "send_sig" },
	{ 0x8d5e53af, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "A353DB43491D93C5CA9E4E9");
