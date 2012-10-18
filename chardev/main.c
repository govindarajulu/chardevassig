#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/kdev_t.h>
#define MAJORR 59
#define COUNT 2
dev_t chrdev;
static __init int modinit(void){
    int err;
    chrdev=MKDEV(MAJORR,0);
    printk("inserting module\n");
    printk("registering chrdev\n");
    err=register_chrdev_region(chrdev,COUNT,"mychrdev");
    if(err!=0)
        goto error;
        return 0;
error:
    return -1;
}


static __exit void modexit(void){
    printk("removing module\n");
    printk("unregistering chrdev\n");
    unregister_chrdev_region(chrdev,COUNT);
}

module_init(modinit);
module_exit(modexit);
