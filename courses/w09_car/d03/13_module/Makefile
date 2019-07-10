obj-m += hello.o
obj-m += hello_param.o

#KDIR	:= /lib/modules/$(shell uname -r)/build
KDIR	:= /root/kernel-mds2450-3.0.22

APP  = hello_app

default:
	rm -rf *.ko
	rm -rf *.mod.*
	rm -rf .*.cmd
	rm -rf *.o
	
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
	arm-none-linux-gnueabi-gcc -o $(APP) $(APP).c -static
	
	cp hello.ko /tftpboot/rootfs/rootfs/
	cp hello_app /tftpboot/rootfs/rootfs/
	
clean :	
	rm -rf *.ko
	rm -rf *.mod.*
	rm -rf .*.cmd
	rm -rf *.o


# all:
# 	make -C $(KDIR) SUBDIRS=$(PWD) modules
#
#clean:
#	make -C $(KDIR) SUBDIRS=$(PWD) clean

