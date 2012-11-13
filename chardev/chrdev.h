#ifndef CHRDEV_H
#define CHRDEV_H



#include <linux/cdev.h>
#include <linux/ioctl.h>
#define MAJORR 59
#define COUNT 2
#define chrdev_name "mychrdev"
#define IO_PRINT1 1
#define IO_PRINT_STRING 6


#define MY_IOC_MAGIC 'k'
#define MY_IOC_PRINT1 _IO(MY_IOC_MAGIC,0)
#define MY_IOC_PRINT_STRING _IOWR(MY_IOC_MAGIC,1,char)

struct ioctl_cmd2 {
    ssize_t len;
    char * string;
}__attribute__((__packed__));

int fops_myopen(struct inode *myinode, struct file *myfile);
int fops_myrelease(struct inode *myinode, struct file *myfile);
ssize_t fops_myread(struct file* filep, char __user *buf, size_t count, loff_t *f_pos);
ssize_t fops_mywrite(struct file* filep, char __user *buf, size_t count, loff_t *f_pos);
int fops_myioctl (struct inode *myinode, struct file *filep, unsigned int mycmd, unsigned long myarg);

#endif // CHRDEV_H
