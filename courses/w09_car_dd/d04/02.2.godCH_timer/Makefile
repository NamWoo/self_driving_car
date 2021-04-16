obj-m	:= timerTest_mod.o

# KDIR	:= /lib/modules/$(shell uname -r)/build
KDIR	:= /root/kernel-mds2450-3.0.22
#KDIR	:= /work_kernel/linux
PWD	:= $(shell pwd)

default:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) clean
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules

	cp timerTest_mod.ko /tftpboot/rootfs/rootfs/
	# cp hello_app /tftpboot/rootfs/rootfs/

clean:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) clean
