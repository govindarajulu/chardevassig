#ifndef CHRDEV_H
#define CHRDEV_H



#include <linux/cdev.h>
#define MAJORR 59
#define COUNT 2
#define chrdev_name "mychrdev"
#define IO_PRINT1 1
#define IO_PRINT_STRING 2

struct ioctl_cmd2 {
    ssize_t len;
    char * string;
}__attribute__((__packed__));

int fops_open(struct inode *myinode, struct file *myfile);
int fops_release(struct inode *myinode, struct file *myfile);
ssize_t fops_read(struct file* filep, char __user *buf, size_t count, loff_t *f_pos);
ssize_t fops_write(struct file* filep, char __user *buf, size_t count, loff_t *f_pos);
int fops_ioctl (struct inode *myinode, struct file *filep, unsigned int mycmd, unsigned long myarg);

#endif // CHRDEV_H
