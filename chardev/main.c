#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kdev_t.h>
#include <linux/io.h>
#include <linux/fs.h>
#define MAJORR 1
#define COUNT 2
#define chrdev_name "mychrdev"
dev_t chrdev;
struct file_operations fop= {
    .owner = THIS_MODULE

};
static __init int modinit(void){
    int err;
    chrdev=MKDEV(MAJORR,0);
    printk("------------------------------\n");
    printk("inserting module\n");
    printk("trying registering chrdev:%s-MAJOR=%d,COUNT=%d\n",chrdev_name,MAJOR(chrdev),COUNT);
    err=register_chrdev_region(chrdev,COUNT,chrdev_name);
    if(err<0){
        printk("chr register failed with register_chrdev_region, trying alloc_chrdev\n");
        goto try_alloc_chrdev_region;
    }
    printk("registration successfull\n");
    return 0;
try_alloc_chrdev_region:
    err=alloc_chrdev_region(&chrdev,0,COUNT,chrdev_name);
    if(err<0)
        goto goto_error;
    printk("registed chrdev:%s-MAJOR=%d,COUNT=%d\n",chrdev_name,MAJOR(chrdev),COUNT);
    return 0;
goto_error:
    return err;
}


static __exit void modexit(void){
    printk("removing module\n");
    printk("unregistering chrdev:%s-MAJOR=%d,COUNT=%d\n",chrdev_name,MAJOR(chrdev),COUNT);
    unregister_chrdev_region(chrdev,COUNT);
}

module_init(modinit);
module_exit(modexit);
