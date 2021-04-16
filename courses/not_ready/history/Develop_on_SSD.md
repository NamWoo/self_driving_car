https://www.youtube.com/watch?v=ZpQgRdg8RmA



sudo cp -ax / <path to partition root> && sync
sudo cp -ax / 'media/nvidia/jetsonSSD250' && sync

cd /boot/extlinux
ls
extlinux-conf

백업
sudo cp extlinux.conf extlinux.conf.original

아래 내용을 
sudo vi extlinux.conf
```bash extlinux.conf
TIMEOUT 30
DEFAULT primary

MENU TITLE p2371-2180 eMMC boot options

LABEL primary
    MENU LABEL primary kernel
    LINUX /boot/Image
    INITRD /boot/initrd
    APPEND ${cbootargs} root=/dev/mmcblk0p1 rw rootwait
```


이렇게 수정하기
```bash extlinux.conf
TIMEOUT 30
DEFAULT primary

MENU TITLE p2371-2180 eMMC boot options

LABEL primary
    MENU LABEL primary SSD
    LINUX /boot/Image
    INITRD /boot/initrd
    APPEND ${cbootargs} root=/dev/sda1 rw rootwait

LABEL eMMC
    MENU LABEL eMMC kernel
    LINUX /boot/Image
    INITRD /boot/initrd
    APPEND ${cbootargs} root=/dev/mmcblk0p1 rw rootwait
```

그리고 리붓팅


github.com/Jetsonhacks/
buildJetsonTX1Kernel

git clone https://github.com/jetsonhacks/buildJetsonTX1Kernel

cd buildJetsonTX1Kernel

새 터미널 열고
sudo ./jetson_clocks.sh
uname-r
4.4.38-tegra

다시 아까 터미널 /buildJetsonTX1Kernel/ 에서

./getKernelSources.sh
