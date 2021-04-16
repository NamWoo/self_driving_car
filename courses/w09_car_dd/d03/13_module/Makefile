obj-m += hello.o
obj-m += hello_param.o

#KDIR	:= /lib/modules/$(shell uname -r)/build
KDIR	:= /root/kernel-mds2450-3.0.22
# PWD	:= $(shell pwd)
APP  = hello_app



default:
	rm -rf *.ko *.mod.* .*.cmd *.o
	rm -rf Modules.symvers
	rm -rf .tmp_versions
	
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
	arm-none-linux-gnueabi-gcc -o $(APP) $(APP).c -static
	
	cp hello.ko /tftpboot/rootfs/rootfs/
	cp hello_app /tftpboot/rootfs/rootfs/
	
clean :	
	rm -rf *.ko *.mod.* .*.cmd *.o
	rm -rf Modules.symvers
	rm -rf .tmp_versions



# all:
# 	make -C $(KDIR) SUBDIRS=$(PWD) modules
#
#clean:
#	make -C $(KDIR) SUBDIRS=$(PWD) clean

