obj-m += w09d04_proj.o
# obj-m += hello_param.o

#KDIR	:= /lib/modules/$(shell uname -r)/build
KDIR	:= /root/kernel-mds2450-3.0.22
# PWD	:= $(shell pwd)
APP  = w09d04_proj_app



default:
	rm -rf *.ko *.mod.* .*.cmd *.o
	rm -rf Modules.symvers
	rm -rf .tmp_versions
	
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
	arm-none-linux-gnueabi-gcc -o $(APP) $(APP).c -static
	
	cp w09d04_proj.ko /tftpboot/rootfs/rootfs/
	cp w09d04_proj_app /tftpboot/rootfs/rootfs/
	
clean :	
	rm -rf *.ko *.mod.* .*.cmd *.o
	rm -rf Modules.symvers
	rm -rf .tmp_versions



# all:
# 	make -C $(KDIR) SUBDIRS=$(PWD) modules
#
#clean:
#	make -C $(KDIR) SUBDIRS=$(PWD) clean

