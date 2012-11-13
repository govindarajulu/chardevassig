#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kdev_t.h>
#include <linux/io.h>
#include <linux/fs.h>
#include "chrdev.h"
extern dev_t chrdev;
extern dev_t chrdev;
extern struct cdev *mycdev;
extern struct file_operations fop;
static __init int modinit(void)
{
        int err;
        chrdev=MKDEV(MAJORR,0);
        printk("------------------------------\n");
        printk("inserting module\n");
        printk("trying registering chrdev:%s-MAJOR=%d,COUNT=%d\n",chrdev_name,MAJOR(chrdev),COUNT);
        err=register_chrdev_region(chrdev,COUNT,chrdev_name);
        if(err<0){
                printk("chr register failed with register_chrdev_region, trying alloc_chrdev\n");
                goto try_alloc_chrdev_region;
        }
        printk("registration successfull\n");
        goto goto_cdev_init;
try_alloc_chrdev_region:
        err=alloc_chrdev_region(&chrdev,0,COUNT,chrdev_name);
        if(err<0)
                goto goto_error;
        printk("registed chrdev:%s-MAJOR=%d,COUNT=%d\n",chrdev_name,MAJOR(chrdev),COUNT);
        goto goto_cdev_init;
goto_error:
        return -1;
goto_cdev_init:
        mycdev=cdev_alloc();
        mycdev->ops=&fop;
        mycdev->owner=THIS_MODULE;
        err=cdev_add(mycdev,chrdev,COUNT);
        if(err<0) {
                printk("error in cdev_add\n");
                goto goto_unregister_chrdev_region;
        }
        printk("cdev_add successfull\n");
        goto goto_success;
goto_success:
        return 0;
goto_unregister_chrdev_region:
        unregister_chrdev_region(chrdev,COUNT);
        goto goto_error;
}

static __exit void modexit(void)
{
        printk("removing module\n");
        printk("unregistering chrdev:%s-MAJOR=%d,COUNT=%d\n",chrdev_name,MAJOR(chrdev),COUNT);
        cdev_del(mycdev);
        unregister_chrdev_region(chrdev,COUNT);
}

module_init(modinit);
module_exit(modexit);
