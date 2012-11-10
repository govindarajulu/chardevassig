#ifndef CHRDEV_H
#define CHRDEV_H



#include <linux/cdev.h>
#define MAJORR 59
#define COUNT 2
#define chrdev_name "mychrdev"
int fops_myopen(struct inode *myinode, struct file *myfile);


#endif // CHRDEV_H
