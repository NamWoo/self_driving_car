# EL6410 kernel 3.0 driver Makefile

obj-m  := mydrv.o

KDIR	:= /root/kernel-mds2450-3.0.22

PWD    := $(shell pwd)

APP  = test_mydrv

default:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
		
	arm-none-linux-gnueabi-gcc -o $(APP) $(APP).c -static
	
clean :	
	rm -rf *.ko
	rm -rf *.mod.*
	rm -rf .*.cmd
	rm -rf *.o


