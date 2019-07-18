
## 실행

* 우분투 Ubuntu10.10 설치 후 실행
* `ifconfig` 입력시 기존에 하던 eth0, eth1, lo 총 3가지가 보이지 않는다. 
* 선생님 계실 때는 잘 보이던게.. 안보이고.. 안보이니 연결도 안되고..
* 그래서 `구글`신께 빌기 시작... 무한 삽질..

```
root@ubuntu-vm ~
# ifconfig
eth0      Link encap:Ethernet  HWaddr 00:0c:29:61:58:dd  
          inet addr:192.168.190.128  Bcast:192.168.190.255  Mask:255.255.255.0
          inet6 addr: fe80::20c:29ff:fe61:58dd/64 Scope:Link
          UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
          RX packets:680 errors:0 dropped:0 overruns:0 frame:0
          TX packets:528 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:1000 
          RX bytes:180917 (180.9 KB)  TX bytes:149664 (149.6 KB)
          Interrupt:19 Base address:0x2024 

lo        Link encap:Local Loopback  
          inet addr:127.0.0.1  Mask:255.0.0.0
          inet6 addr: ::1/128 Scope:Host
          UP LOOPBACK RUNNING  MTU:16436  Metric:1
          RX packets:153 errors:0 dropped:0 overruns:0 frame:0
          TX packets:153 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:0 
          RX bytes:12060 (12.0 KB)  TX bytes:12060 (12.0 KB)
```


### 삽1
```
sudo ifconfig eth0 down
sudo ifconfig eth0 192.168.11.130 up
# ifconfig
eth0      Link encap:Ethernet  HWaddr 00:0c:29:61:58:dd  
          inet addr:192.168.190.128  Bcast:192.168.190.255  Mask:255.255.255.0
          inet6 addr: fe80::20c:29ff:fe61:58dd/64 Scope:Link
          UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
          RX packets:699 errors:0 dropped:0 overruns:0 frame:0
          TX packets:586 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:1000 
          RX bytes:183229 (183.2 KB)  TX bytes:158546 (158.5 KB)
          Interrupt:19 Base address:0x2024 

lo        Link encap:Local Loopback  
          inet addr:127.0.0.1  Mask:255.0.0.0
          inet6 addr: ::1/128 Scope:Host
          UP LOOPBACK RUNNING  MTU:16436  Metric:1
          RX packets:153 errors:0 dropped:0 overruns:0 frame:0
          TX packets:153 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:0 
          RX bytes:12060 (12.0 KB)  TX bytes:12060 (12.0 KB)

```

변함이 없다.....  그래서  sudo.. 명령어를 쓰지 않고 그냥 up!


```
root@ubuntu-vm ~
# ifconfig eth0 192.168.20.90 up
root@ubuntu-vm ~
# ifconfig
eth0      Link encap:Ethernet  HWaddr 00:0c:29:61:58:dd  
          inet addr:192.168.20.90  Bcast:192.168.20.255  Mask:255.255.255.0
          inet6 addr: fe80::20c:29ff:fe61:58dd/64 Scope:Link
          UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
          RX packets:715 errors:0 dropped:0 overruns:0 frame:0
          TX packets:595 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:1000 
          RX bytes:185011 (185.0 KB)  TX bytes:160753 (160.7 KB)
          Interrupt:19 Base address:0x2024 

lo        Link encap:Local Loopback  
          inet addr:127.0.0.1  Mask:255.0.0.0
          inet6 addr: ::1/128 Scope:Host
          UP LOOPBACK RUNNING  MTU:16436  Metric:1
          RX packets:153 errors:0 dropped:0 overruns:0 frame:0
          TX packets:153 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:0 
          RX bytes:12060 (12.0 KB)  TX bytes:12060 (12.0 KB)
```

`inet addr:192.168.20.90` 

갓봉준 해결완료!