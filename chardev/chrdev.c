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
    .open  = fops_myopen,
    .release = fops_myrelease,
    .read = fops_myread,
    .write = fops_mywrite,
    .ioctl = fops_myioctl
};
