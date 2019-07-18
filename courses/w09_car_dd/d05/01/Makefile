obj-m += sk.o
# obj-m += hello_param.o

#KDIR	:= /lib/modules/$(shell uname -r)/build
KDIR	:= /root/kernel-mds2450-3.0.22
# PWD	:= $(shell pwd)
APP  = sk_app



default:
	rm -rf *.ko *.mod.* .*.cmd *.o
	rm -rf Modules.symvers
	rm -rf .tmp_versions
	
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
	arm-none-linux-gnueabi-gcc -o $(APP) $(APP).c -static
	
	cp sk.ko /tftpboot/rootfs/rootfs/
	cp sk_app /tftpboot/rootfs/rootfs/
	
clean :	
	rm -rf *.ko *.mod.* .*.cmd *.o
	rm -rf Modules.symvers
	rm -rf .tmp_versions

# .c.o:
# 	gcc -c ${CFLAGS} $<

#  %_dbg.o: %.c
#         gcc -c -g -o $@ ${CFLAG} $<

#  DEBUG_OBJECTS = main_dbg.o edit_dbg.o

#  edimh_dbg: $(DEBUG_OBJECTS)
#         gcc -o $@ $(DEBUG_OBJECTS)

#  $<     입력 화일을 의미합니다. 콜론의 오른쪽에 오는 패턴을 치환합니다.
#  $@     출력 화일을 의미합니다. 콜론의 왼쪽에 오는 패턴을 치환합니다.
#  $*     입력 화일에서 꼬리말(.c, .s 등)을 떼넨 화일명을 나타냅니다.
# 역시 GNU 버전이라는 생각이 들지 않으시는지요?

#  target:
#         cd obj ; \
#         HOST_DIR=/hom/e ; \
#         mv *.o $$HOST_DIR


# all:
# 	make -C $(KDIR) SUBDIRS=$(PWD) modules
#
#clean:
#	make -C $(KDIR) SUBDIRS=$(PWD) clean

# http://doc.kldp.org/KoreanDoc/html/GNU-Make/GNU-Make-3.html
