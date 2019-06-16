##########[Embedded C test firmware Makefile]##############
#
# NAME : Makefile - S3C2450 test Firmware Makefile
# Brief history
#----------------------------------------------------------
#
#	2015.08.10, Seonghye : Modified
#
###########################################################

.EXPORT_ALL_VARIABLES:

## If you want to change path, modify here

TOPDIR =$(PWD)
TOOLPATH = /opt/CodeSourcery/Sourcery_G++_Lite

SRCS	= Main.c Uart.c iic.c iis.c timer.c libc.c exception.c
ASRCS	= s3c2450_startup.S libs.S

OBJS	= ${SRCS:.c=.o} ${ASRCS:.S=.o}

CC = $(TOOLPATH)/bin/arm-none-eabi-gcc
LD = $(TOOLPATH)/bin/arm-none-eabi-ld
OBJCOPY	= $(TOOLPATH)/bin/arm-none-eabi-objcopy
OBJDUMP	= $(TOOLPATH)/bin/arm-none-eabi-objdump

LIBCDIR =$(TOOLPATH)/arm-none-eabi/lib
LIBGCCDIR =$(TOOLPATH)/lib/gcc/arm-none-eabi/4.5.2
LIBC =$(TOOLPATH)/arm-none-eabi/lib/libc.a
LIBGCC = $(TOOLPATH)/lib/gcc/arm-none-eabi/4.5.2/libgcc.a

## User library for UART1 Driver
MY_LIB_PATH = $(TOPDIR)/Libraries
LIBUART =  $(MY_LIB_PATH)/libUart1.a

#### Option Definition ####
INCLUDE	=  -I$(TOPDIR) -I$(LIBCDIR)/include -I$(LIBGCCDIR)/include

CFLAGS	+= $(INCLUDE) -g -Wall -Wstrict-prototypes -Wno-trigraphs -O0
CFLAGS	+= -fno-strict-aliasing -fno-common -pipe
CFLAGS += -march=armv4t -mtune=arm9tdmi -fno-builtin -mapcs

LDFLAGS	= --cref -Bstatic -nostartfiles -T S3C2450-RAM.ld -Map 2450main.map
OCFLAGS = -O binary -R .note -R .comment -S

2450TEST = MDS2450.bin

%.o:%.S
	$(CC) -c $(CFLAGS) -o $@ $<

%.o:%.c
	$(CC) -c $(CFLAGS) -o $@ $<

all: $(2450TEST)

$(2450TEST) : $(OBJS)
	$(LD) $(LDFLAGS) -o MDS2450 $(OBJS) $(LIBC) $(LIBGCC) \
	-I$(LIBGCCDIR)/include -I$(LIBCDIR)/include -L$(LIBC) -L$(LIBGCCDIR) -lgcc

	$(OBJCOPY) $(OCFLAGS) $(TOPDIR)/MDS2450 $(TOPDIR)/$@
	cp $(TOPDIR)/$@ /tftpboot

clean:
	rm -f *.o 
	rm -f $(TOPDIR)/$(2450TEST)
	rm -f $(TOPDIR)/MDS2450
	rm -f $(TOPDIR)/2450main.map

dep:
	$(CC) -M $(INCLUDE) $(SRCS) $(ASRCS) > .depend

ifeq (.depend,$(wildcard .depend))
include .depend
endif					