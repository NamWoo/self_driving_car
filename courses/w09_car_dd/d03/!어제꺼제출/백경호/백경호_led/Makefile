obj-m   := sk.o

#KDIR	:= /root/work/embedded/linux-3.12.14
KDIR	:= /root/kernel-mds2450-3.0.22

all:
	make -C $(KDIR) SUBDIRS=$(PWD) modules

clean:	
	make -C $(KDIR) SUBDIRS=$(PWD) clean
