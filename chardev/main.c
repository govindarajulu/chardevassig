#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kdev_t.h>
#include <linux/io.h>
#include <linux/fs.h>
#include "chrdev.h"
extern dev_t chrdev;
extern dev_t chrdev;
extern struct cdev *mycdev;
extern const struct file_operations fop;
static __init int modinit(void)
{
	int err;
	chrdev = MKDEV(MAJORR, 0);
	printk(KERN_INFO "------------------------------\n");
	printk(KERN_INFO "inserting module\n");
	printk(KERN_INFO "trying registering chrdev:%s-MAJOR=%d,COUNT=%d\n",
	       chrdev_name, MAJOR(chrdev), COUNT);
	err = register_chrdev_region(chrdev, COUNT, chrdev_name);
	if (err < 0) {
		printk(KERN_INFO "chr register failed with register_chrdev_region, trying alloc_chrdev\n");
		goto try_alloc_chrdev_region;
	}
	printk(KERN_INFO "registration successfull\n");
	goto goto_cdev_init;
try_alloc_chrdev_region:
	err = alloc_chrdev_region(&chrdev, 0, COUNT, chrdev_name);
	if (err < 0)
		goto goto_error;
	printk(KERN_INFO "registed chrdev:%s-MAJOR=%d,COUNT=%d\n",
	       chrdev_name, MAJOR(chrdev), COUNT);
	goto goto_cdev_init;
goto_error:
	return -1;
goto_cdev_init:
	mycdev = cdev_alloc();
	mycdev->ops = &fop;
	mycdev->owner = THIS_MODULE;
	err = cdev_add(mycdev, chrdev, COUNT);
	if (err < 0) {
		printk(KERN_INFO "error in cdev_add\n");
		goto goto_unregister_chrdev_region;
	}
	printk(KERN_INFO "cdev_add successfull\n");
	goto goto_success;
goto_success:
	return 0;
goto_unregister_chrdev_region:
	unregister_chrdev_region(chrdev, COUNT);
	goto goto_error;
}

static __exit void modexit(void)
{
	printk(KERN_INFO "removing module\n");
	printk(KERN_INFO "unregistering chrdev:%s-MAJOR=%d,COUNT=%d\n",
	       chrdev_name, MAJOR(chrdev), COUNT);
	cdev_del(mycdev);
	unregister_chrdev_region(chrdev, COUNT);
}

module_init(modinit);
module_exit(modexit);
