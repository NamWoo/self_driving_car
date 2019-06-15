

~ 2019.06.03 주말 내에 개인컴에 리눅스 설치해보기

>아래 내용은 주말에 빌린 책 `파이썬 로보틱스(랜틴 조셉)`, `ROS로봇프로그래밍(표윤석)` 앞 부분 참고했고 설치 부분만 따로 올림

자세한 설명은 내 깃헙에 정리 중.
* https://github.com/NamWoo

---

리눅스를 설치해보자!

예전에 우분투 10.4를 이미 사용해봤지만 최신 우분투19.4 까지 나왔으니 내 개인노트북 안쓰는걸 가져다가 몽땅 날리고 우분투만 위한 노트북으로 만들면서 사용해보려한다.

우분투 버전은 ROS까지 지원가능한 그리고 가장 최신버전을 찾아보니 18.04로 일단 결정했다. 그리고 USB를 이용해 설치를 진행했다.


# 우분투 설치

<img src="https://idchowto.com/wp-content/uploads/2015/11/1234-1024x724.png" width="50%" height="100%">

* https://www.ubuntu.com/download/desktop
* 직전 버전이면서 많이 사용하는 버전은
  * ubuntu-16.04.6-desktop-amd64
  * 이거 다음 그리고 또 다음이 나왔으니 최신 버전중에서도 최적화된 건 뭘까 찾아봤다
* 가장 최신19는 아니지만 LTS 최신에 ROS 지원까지 제대로 맞춰져있는
  * ubuntu-18.04.2-desktop-amd64.iso
  * cd 이미지 파일로 받았고 이걸 아래 이어지는 USB 설치용으로 바꿀!

## 우분투 from USB

<img src="https://rufus.ie/pics/rufus_ko.png" width="40%" height="100%">

* https://rufus.ie/
  * 이렇게 USB에서 바로 설치할 수 있게 도와주는 프로그램
* Rufus 3.5 Portable (1 MB)
  * 포터블이라고 되어있는거 받아서 사용했다.
    * 상단에` USB 장치` 맞는지 확인하고
    * `부트선택`에 원하는 우분투 버전 선택한 다음에
    * 딴거 안건드리고 맨 밑 `시작` 버튼!

## 설치과정

* CMOS 화면으로
  * 컴퓨터 켜질 때 CMOS 화면으로 가기 위해 F1~F12까지 어떤 버튼인지 찾으려고 12번 반복함...
  * 보통 f7이나 f8은 안전모드아 윈도우 부팅 명령프롬푸트부팅 등등
  * 내 노트북은 f2 ㅡㅡ+  한 바퀴 돌아옴
  * 부팅순서 usb 부팅을 젤 위로 해주고 부팅
    * 물론 그 전에 컴퓨터 싹 날려도 되게 백업 필수!
* 알아서 부팅해서 Ubuntu 화면 들어옴
  * Try Ubuntu
  * Install Ubuntu
    * Try 는 그냥 바로 설치없이 우분투 해보는 체험판 경험
    * 우린 Install!

그럼 우분투 설치 완료!


# ROS

* http://wiki.ros.org/ko
* ROS Installation Options
  * ROS는 우분투 LTS 2년주기에 맞춰서 나온다
  * 각 ROS 버전은 5년을 보장(?) 한다.
* 로봇 쪽에선 2016년 버전을 많이 사용하는 듯 하다. 
  * 직전버전이고 직전에 로봇연구가 활발했기에..
  * <img src="https://raw.githubusercontent.com/ros-infrastructure/artwork/master/distributions/kinetic.png" width="50%" height="100%">
  * Released May, 2016
  * LTS, supported until April, 2021
* 최근 버전 2018 
  * <img src="https://raw.githubusercontent.com/ros-infrastructure/artwork/master/distributions/melodic_with_bg.png" width="50%" height="100%">
  * Released May, 2018
  * Latest LTS, supported until May, 2023

앞으로 쭉 사용할 것이기에 2018년 나왔고 2023년까지 보장된(?) Melodic Morenia 가 좋아보임
* 게다가 이 버전은 마이크로소프트 및 많은 연구소에서 로봇연구에 적용, 이미 사용중.

---
>>*마지막 내용 업데이트 2019.06.02*