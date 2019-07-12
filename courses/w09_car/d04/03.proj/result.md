```bash

# clear
# insmod sk.ko
SK Module is up...
major number=251
# mknod /dev/sk c 251 0
# ./sk_app

 [APP] = 1239



Device has been opened...

 [Kernel] id = 1239




fd = 3
SK has been detected...

 sig...0
data : this is read func...
[3]+  Stopped                    ./sk_app
# ps
PID   USER     COMMAND

 1218 root     ./sk_app
 1224 root     [flush-0:15]
 1230 root     ./sk_app
 1239 root     ./sk_app
 1240 root     ps
# kill -9 1218
[1]   Killed                     ./sk_app
# kill -9 1230
[2]-  Killed                     ./sk_app
# kill -9 1239
Device has been closed...
[3]+  Killed                     ./sk_app
# ps
PID   USER     COMMAND

 1206 root     /usr/sbin/dropbear
 1207 root     -sh
 1213 root     /lib/udev/udevd -d
 1224 root     [flush-0:15]
 1241 root     ps
# ./sk_app









 [APP] = 1242
Device has been opened...

 [Kernel] id = 1242







fd = 3
SK has been detected...

 sig...0
data : this is read func...
[1]+  Stopped                    ./sk_app
# ps
PID   USER     COMMAND

 1206 root     /usr/sbin/dropbear
 1207 root     -sh
 1213 root     /lib/udev/udevd -d
 1224 root     [flush-0:15]
 1242 root     ./sk_app
 1243 root     ps
# kill -10 1242
# fg
./sk_app

Device has been closed...
 sig...1#
# ps
PID   USER     COMMAND

 1191 dbus     dbus-daemon --system
 1206 root     /usr/sbin/dropbear
 1207 root     -sh
 1213 root     /lib/udev/udevd -d
 1224 root     [flush-0:15]
 1244 root     ps
#
```