#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include "mystruct.h"
#include <linux/slab.h>


int base_minor = 0;
char *device_name = "mystruct";
int count = 1;
dev_t devicenumber;
abc kernel_struct;
char kernel_buffer[100];


static struct class *class = NULL;
static struct device *device = NULL;
static struct cdev mycdev;

MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
	return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
	pr_info("%s\n", __func__);
        return 0;
}

static ssize_t device_read(struct file *file, char __user *user_buffer,
                      size_t count, loff_t *offset)
{
	int retval;
	
	kernel_struct.str = kmalloc(1, GFP_KERNEL);

	retval = copy_to_user(&((abc *)user_buffer)->i, &kernel_struct.i, sizeof(kernel_struct.i));
	pr_info("%s: Copy to user returned:%d\n", __func__, retval);

	//retval = copy_to_user(((abc *)user_buffer)->str, kernel_buffer, strlen(kernel_buffer)+1);
	//pr_info("%s: Copy to user returned:%d\n", __func__, retval);


	pr_info("%s:int :%d\t str:%s \t Count:%lu \t offset:%llu\n", __func__,
			kernel_struct.i, kernel_buffer, count, *offset);
        return 0;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer,
                       size_t count, loff_t *offset)
{
	int retval;
	int string_length = 0;


	retval = copy_from_user(&kernel_struct, user_buffer, count);
	pr_info("%s: Copy from user returned:%d\n", __func__, retval);
	string_length = strnlen_user(kernel_struct.str, 100);
	retval = copy_from_user(&kernel_buffer, kernel_struct.str, string_length);
	pr_info("%s: Length:%d\n", __func__, string_length);
	pr_info("%s:int:%d\t str:%s\t Count:%lu \t offset:%llu\n", __func__, kernel_struct.i,
			kernel_buffer, count, *offset);
        return count;
}



struct file_operations device_fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};


static int test_hello_init(void)
{
	class = class_create("myclass");

	if (!alloc_chrdev_region(&devicenumber, base_minor, count, device_name)) {
		printk("Device number registered\n");
		printk("Major number received:%d\n", MAJOR(devicenumber));

		device = device_create(class, NULL, devicenumber, NULL, device_name);
		cdev_init(&mycdev, &device_fops);
		mycdev.owner = THIS_MODULE;
		cdev_add(&mycdev, devicenumber, count);

	}
	else
		printk("Device number registration Failed\n");

	return 0;
}

static void test_hello_exit(void)
{
	device_destroy(class, devicenumber);
        class_destroy(class);
	cdev_del(&mycdev);
	unregister_chrdev_region(devicenumber, count);
}

module_init(test_hello_init);
module_exit(test_hello_exit);
