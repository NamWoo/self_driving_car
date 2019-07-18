# EL-2440 kernel 2.6 driver Makefile

obj-m  := mydrv.o

# KDIR  := /usr/src/elayer/linux-2.6.24-el2440-v2.0

KDIR	:= /root/kernel-mds2450-3.0.22

PWD    := $(shell pwd)

APP  = test_mydrv

default:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
		
#	arm-linux-gnu-gcc -o $(APP) $(APP).c
	arm-none-linux-gnueabi-gcc -o $(APP) $(APP).c -static

	
clean :	
	rm -rf *.ko
	rm -rf *.mod.*
	rm -rf .*.cmd
	rm -rf *.o


