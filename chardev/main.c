#include <linux/module.h>
#include <linux/kernel.h>

static __init int modinit(void){
    printk("inserting module\n");
    return 0;
}


static __exit void modexit(void){
    printk("removing module\n");
}

module_init(modinit);
module_exit(modexit);
