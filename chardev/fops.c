#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kdev_t.h>
#include <linux/io.h>
#include <linux/fs.h>
#include <linux/string.h>
#include <linux/slab.h>
#include <asm-generic/uaccess.h>
#include "chrdev.h"

int fops_myopen(struct inode *myinode, struct file *myfile) {
    return 0;
}

int fops_myrelease(struct inode *myinode, struct file *myfile) {
    return 0;
}
ssize_t fops_myread(struct file* filep, char __user *buf, size_t count, loff_t *f_pos){
    copy_to_user(buf,"linux",6);
    *f_pos=*f_pos+6;
    return 6;
}

ssize_t fops_mywrite(struct file* filep, char __user *buf, size_t count, loff_t *f_pos){
    char *buffer;
    buffer=kmalloc(count+1,GFP_KERNEL);
    copy_from_user(buffer,buf,count);
    buffer[count]='\0';
    printk("read- %s\n",buffer);
    *f_pos=*f_pos+count;
    kfree(buffer);
    return count;
}

int fops_myioctl (struct inode *myinode, struct file *filep, unsigned int mycmd, unsigned long myarg){
    struct ioctl_cmd2 cmd2;
    char* string;
    switch(mycmd){
    case IO_PRINT1:
        printk("cmd 1 received\n");
        break;
    case IO_PRINT_STRING:
        copy_from_user(&cmd2,(struct ioctl_cmd2*)myarg,sizeof(struct ioctl_cmd2));
        string=kmalloc(cmd2.len,GFP_KERNEL);
        copy_from_user(string,cmd2.string,cmd2.len);
        printk("cmd2:%s",string);
        kfree(string);
        break;
    default:
        return ENOTTY;
    }

    return 0;
}
