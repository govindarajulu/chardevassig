obj-m := mychrdev.o
mychrdev-objs := chrdev.o main.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=`pwd` modules
