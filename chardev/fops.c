#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kdev_t.h>
#include <linux/io.h>
#include <linux/fs.h>
#include "chrdev.h"

int fops_open(struct inode *myinode, struct file *myfile) {
    return 0;
}

int fops_release(struct inode *myinode, struct file *myfile) {
    return 0;
}
