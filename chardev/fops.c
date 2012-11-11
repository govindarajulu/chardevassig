#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kdev_t.h>
#include <linux/io.h>
#include <linux/fs.h>
#include <linux/string.h>
#include <asm-generic/uaccess.h>
#include "chrdev.h"

int fops_open(struct inode *myinode, struct file *myfile) {
    return 0;
}

int fops_release(struct inode *myinode, struct file *myfile) {
    return 0;
}
ssize_t fops_read(struct file* filep, char __user *buf, size_t count, loff_t *f_pos){
    //strcpy(buf,"linux");
    copy_to_user(buf,"linux",6);
    *f_pos=*f_pos+6;
    return 6;
}
