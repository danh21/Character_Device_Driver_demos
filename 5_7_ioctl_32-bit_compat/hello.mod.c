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
	{ 0xb8e7ce2c, "__put_user_8" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xada84b28, "device_destroy" },
	{ 0xa9edd0d8, "class_destroy" },
	{ 0x78445a7c, "cdev_del" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x932aac8c, "class_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0x1421f594, "device_create" },
	{ 0x21be7f7b, "cdev_init" },
	{ 0x54c057fa, "cdev_add" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x122c3a7e, "_printk" },
	{ 0x167e7f9d, "__get_user_1" },
	{ 0x8d5e53af, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "AF0A9EA8C4DCDF728D0BF33");
