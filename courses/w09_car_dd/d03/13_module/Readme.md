# result 

```bash
# insmod hello.ko
------------------------------
Let's go hell ya!!!!!!!!!!!!!
module's up
major number=251
keyint successfully SW14 loaded
keyint successfully SW15 loaded


# mknod /dev/hell c 251 0


# ./hello_app
hell opened
fd = 3
size=78
hell has been detected...
mydrv_read is invoked
hell released
age = 18
name = HONG KILDONG
address = SUWON CITY
phone_number = 121232
depart = ELAYER


# 14 Key pressed....
age : 18


15 Key pressed....
name : HONG KILDONG


14 Key pressed....
age : 18


15 Key pressed....
name : HONG KILDONG


# rmmod hello
bye hell
module's down
keyint successfully removed
```