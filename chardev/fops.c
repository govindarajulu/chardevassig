#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kdev_t.h>
#include <linux/io.h>
#include <linux/fs.h>
#include "chrdev.h"

int fops_myopen(struct inode *myinode, struct file *myfile) {
    return 0;
}
