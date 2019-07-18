obj-m	:= timerTest_mod.o

# KDIR	:= /lib/modules/$(shell uname -r)/build
# KDIR	:= /work_kernel/linux
KDIR	:= /root/kernel-mds2450-3.0.22
PWD	:= $(shell pwd)

default:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
	arm-none-linux-gnueabi-gcc -o app app.c
	cp timerTest_mod.ko /tftpboot/rootfs/rootfs/
	cp timerTest_mod.c ~/kernel-mds2450-3.0.22/drivers/char/
	cp app /tftpboot/rootfs/rootfs/

clean:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) clean

