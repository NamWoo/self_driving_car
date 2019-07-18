#obj-m := keysample.o
#keysample-objs	:= keyint_bottom_kscan_dd_sysfs.o
#obj-m += keyint_base.o
obj-m += work_queue.o
# obj-m += work_queue.o
#obj-m += keyint_bottom_kscan.o
#obj-m += keyint_bottom_kscan_dd.o

EXTRA_CFLAGS += -I./include

KDIR := /root/kernel-mds2450-3.0.22


default:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
#	cp -ra keysample.ko /opt/4.2.4-arm/arm-generic-linux-gnu/sys-root/root/
#	cp -ra keysample.ko /work/rootfs_nfs/root
	cp work_queue.ko /tftpboot/rootfs/rootfs	
	

clean:
	rm -rf *.ko
	rm -rf *.mod.*
	rm -rf .*.cmd
	rm -rf *.o
	rm -rf *.bak
	


