#ifndef CHRDEV_H
#define CHRDEV_H
#include <linux/cdev.h>
#define MAJORR 59
#define COUNT 2
#define chrdev_name "mychrdev"
dev_t chrdev;
struct cdev *mycdev;
struct file_operations fop;
#endif // CHRDEV_H
