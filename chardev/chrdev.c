#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kdev_t.h>
#include <linux/io.h>
#include <linux/fs.h>
#include "chrdev.h"
dev_t chrdev;
struct cdev *mycdev;
struct file_operations fop= {
    .owner = THIS_MODULE,
    .open  = fops_open,
    .release = fops_release,
    .read = fops_read

};
