obj-m := main.o
main-objs:= chrdev.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=`pwd` modules
