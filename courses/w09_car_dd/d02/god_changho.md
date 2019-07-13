## 02_open_release

```bash 
# insmod sk.ko
SK Module is up...
major number=251

# ./sk_app
Device has been opened...
fd = 3
SK has been detected...

Device has been closed...

# rmmod sk.ko
The module is down...
```

## 03_write 

```bash
# insmod sk.ko
SK Module is up...
major number=251
# ./sk_app
Device has been opened...
fd = 3data >>>>> = write...

Device has been closed...

SK has been detected...

Size of written data : 10
# rmmod sk.ko
The module is down...
```


## 04_read

```bash
# insmod sk.ko
SK Module is up...
major number=251
# ./sk_app
Device has been opened...
fd = 3Device has been closed...

SK has been detected...

data : this is read func...
# rmmod sk.ko
The module is down...
```

## 05_mydrv-copy_to_user 
read 해보라

```bash
# insmod sk.ko
mydrv_init done
# ./sk_app
buf_in =
# rmmod sk.ko
rmmod: can't unload 'sk': unknown symbol in module, or unknown parameter
```
다시

```bash
# mknod /dev/mydrv c 251 0
mknod: /dev/mydrv: File exists
# rm -rf /dev/mydrv
# mknod /dev/mydrv c 251 0
# rmmod mydrv.ko
mydrv_exit done


# insmod mydrv.ko
mydrv_init done
# ./test_mydrv
buf_in =
# ./test_mydrv
buf_in =
# rmmod mydrv.ko
mydrv_exit done
```

## 06_구조체과제

```Makefile

KDIR	:= /root/kernel-mds2450-3.0.22

default:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
#	arm-linux-gnu-gcc -o $(APP) $(APP).c
	arm-none-linux-gnueabi-gcc -o $(APP) $(APP).c -static
```

makefile 수정 후 


```bash
# insmod mydrv.ko
mydrv_init done
# ./test_mydrv
size=78
age = 0
name =
address =
phone_number = 0
depart =
# rmmod mydrv.ko
mydrv_exit done
```

## 07_LED

```bash

```