
### 로봇이란

robot 이란 단어는 체코의 극작가 카렐 차파크 karel Capek 가 1920년 희곡 로봇 RUR(합성한 유기물로 만든 인공적인 인간을 가리키는 말) 에서 처음 사용. 
카렐은 처음에 labori 일, 노농을 뜻하는 라틴어 용어를 사용하려 했지만 너무 인공적이라 동생에게 조언을 구했고, 동생 요세프는 로보티 라는 단어를 제안, 결국 이 단어를 사용하게 되었다 고 한다.

### 모터의 RPM 계산

* 최초 요구사항
  * 속도가 0.25m/s 에서 1m/s
  * 최저 지상고가 3cm 보다 커야 한다
* 결정사항
  * 속도를 0.35m/s 라고 정하고
  * 바퀴의 지름을 9cm 라고 할 때

RPM = (60 * 속도) / (3.14 * 바퀴지름)

대입해서 정리하면 

* $RPM = (60 * 0.35) / (3.14 * 0.09) = 21 / 0.2826 = 74 RPM$

### 모터의 토크 계산

1. 바퀴개수, 캐스터 바퀴를 포함해 4개
2. 모터개수 2개
3. 마찰계수 friction coefficient 0.6
4. 바퀴반지름 4.5cm
5. 전체로봇무게 = 로봇의 무게 + 적재물 중량 = 약 100N + 약 50N = 약 150N
   1. (전체질량 = 15kg인 경우, W=mg 공식 사용)
6. 로봇이 정지상테 있다고 가정, 필요한 최대 토크는 로봇이 움직이기 시작할 때, 이때 마찰을 이겨야한다.
7. 움직이기 직전까지 로봇의 토크 = 마찰력
   
$\mu*N*r-T=0$ (여기서 $\mu$는 (정지)마찰계수, $N$은 각 바퀴에 작용하는 평균무게, $r$은 바퀴의 반지름, $T$는 토크)

$N = W/4$ 로봇의 무게가 4바퀴에 고르게 분산된다고 가정

따러서 다음과 같은 결과를 얻는다.

$0.6*(150/4)*0.045-T=0$

그러므로 $T = 0.0125N-m$ 또는 $10.35kg-cm$

### 2D and 3D CAD

* 2D 모델 만들고
  * https://librecad.org/#home
    * https://sourceforge.net/projects/librecad/files/latest/download
* 3D 모델 다루고
  * https://www.blender.org/
    * https://www.blender.org/download/
    * [유튜브 튜토리얼](https://www.youtube.com/watch?v=DZ_ocmY8xEI&list=PLa1F2ddGya_8V90Kd5eC5PeBjySbXWGK1&index=35) 
* 3D 메시보여주기가지고 3D 모델 설계 및 검사 하고 보여주기
  * http://www.meshlab.net/
    * http://www.meshlab.net/#download

### 시뮬레이션

* Gazebo
  * 다중로봇 시뮬레이터 ROS, 오픈소스
* VREP
  * 산업용 로봇, 발전된3D 코펠리아 로보틱스에서 개발, c, C++ 파이썬 자바 루아 메트랩 어비, 다양한 언어와 교육플렛폼으로도 많이 사용
* Webots
  * 사이버보틱스가 개발, 교육, 연구 목적으로 널리 사용 다양한 언어, OpenCV 외부 라이브러리와 호환 가능
* RoboLogix
  * 로직 디자인에서 개발, 산업용 5축 산업용 로봇을 실제 세계에서 응용하는 것을 에뮬레이션 하기 위해 설계, ABB, Fanuc, Kawasaki 등 광범위한 산업로봇 지원

### 로봇의 운동학

* 이동로봇은 자세에서 6자유도 DOF, Degree of Freedom을 가진다.
* x,y,z roll pitch yaw
  * 롤은 좌우회전
  * 피치는 앞뒤회전
  * 요우 (때로는  heading orientation 기수방위) 방항 xy 평면상에 로봇이 향하는 방향
* 로차동 구동로봇에서 왼쪽 오른쪽 구동모터 속도 명칭 
  * V-left
  * V-right
* 로봇이 롤링하려고 할때, 로봇이 좌우 바퀴의 공통 축(또는 그 연장선에 놓여있는) 어떤 점을 중심으로 회전, 로봇이 회전하는 중심축을  ICC instantaneous Center of Curvature 순간 곡률 중심
  * 그러니까 차가 회전할때 오른쪽 왼쪽 이동거리, 속도가 다르다는말
* 바퀴의 속도는 $v=2\pi r/T$ T는 ICC를 중심으로 완전한 한 바퀴를 돌 때 걸리는 시간
* 각속도 $\omega$는 $2\pi /T$로 정의되고 보통 초당 라디안이라는 단위 사용
* $v=r\omega$
* 두 바퀴에 적용하면
  * $\omega(R+l/2)=Vr$
  * $\omega(R-l/2)=Vl$
    * (식 3)
  * R 은 ICC 와 바퀴 구동축의 중점 사이의 거리
  * l 은 바퀴 구동축의 길이
* 정리하면
  * $R=l/2(Vl+Vr)/(Vr-Vl)$
    * (식 4)
  * $\omega=(Vr-Vl)l$
    * (식 5)

로봇이 $\delta t$초 동안 각속도 $\omega$로 움직인다면 로봇의 방향 또는 기수방위는 다음과 같이 변한다
* $\theta'= \omega\delta t + \theta$ 
  * (식 6)

ICC 회전의 중심은 기본 삼각공식으로 구하고
* $ICC = [ICCx, ICCy]= [x+Rsin\theta , y+Rcos\theta]$ 
  * (식 7)

시작위치 (x, y)가 주어지면, 새로운 위치 (x',y')를 2D회전 행렬을 상요해 계산할 수 있다. 각속도 w 동안 $\delta t$ 초 동안 ICC 를 중심으로 회전시키면 $t + \delta t$ 시점에 다음과 같은 위치를 얻는다.

* $\left(\begin{array}{rrr} 
x'\\
y'\end{array}\right) = 
\left(\begin{array}{rrr} 
cos(\omega\delta t)&-sin(\omega\delta t)\\
sin(\omega\delta t)&cos(\omega\delta t)\end{array}\right)
\left(\begin{array}{rrr} 
x-ICC_x\\
y-ICC_y\end{array}\right)+
\left(\begin{array}{rrr} 
ICC_x\\
ICC_y\end{array}\right)$ 
  * (식 8)

$\omega$ $\delta$ $R$ 이 주어지면 새로운 자세 (x', y', $\theta'$)를 식6 식8에서 계산할 수 있다. $\omega$ 는 식 5에서 계산가능하지만 Vr과 Vl을 정확히 측정하는 것이 어려울 때가 많다.

그래서 속도를 측정하는 대신 바퀴인코더 센서를 이용해 각 바퀴의 회전을 측정할 수 있다. 바퀴 인코더에서 나온 데이터는 로봇의 주행거리 값. 이 신호를 카운터에 집어넣고 $v\delta t$ 가 시점 $t+\delta t$시점까지 움직인 거리라고 하면 다음과 같이 쓸 수 있다.
* $n*step = v\delta t$
  * (식 9)

식9를 식3과 식4에 넣으면
* $R=l/2(Vl+Vr)/(Vr-Vl) = l/2(nl+nr)/(nr-nl)$
  * (식 10)
* $\omega\delta t=(Vr-Vl)\delta t/l=(nr-nl)*step/l$
  * (식 11)
    * 여기서 nl과 nr 은 왼쪽과 오른쪽 바퀴의 인코더 횟수
    * Vl과 Vr은 각각 왼쪽과 오른쪽 바퀴의 속도

따라서 로봇이(x, y, $\theta$)라는 자세로 있었고 $\delta t$ 라는 시간단위동안 nl과 nr이라는 인코더 횟수만큼 움직였다면 새로운 자세 (x', y', $\theta'$)는 다음과 같다.
* $\left(\begin{array}{rrr} 
x'\\
y'\\
\theta'\end{array}\right) = 
\left(\begin{array}{rrr} 
cos(\omega\delta t)&-sin(\omega\delta t)&0\\
sin(\omega\delta t)&cos(\omega\delta t)&0\\
0&0&1\end{array}\right)
\left(\begin{array}{rrr} 
x-ICC_x\\
y-ICC_y\\
\theta\end{array}\right)+
\left(\begin{array}{rrr} 
ICC_x\\
ICC_y\\
\omega\delta t\end{array}\right)$
  * (식 12)

여기서 $R$ $\omega\delta t$ ICC 는 다음과 같다.
* $R=l/2(nl+nr)/(nr-nl)$
  * (식 12)
* $\omega\delta t = (nr-nl)*step/l$
  * (식 13)
* $ICC = [x+Rsin\theta , y+Rcos\theta]$
  * (식 14)

***지금까지 로봇이 t 시점에서 (x, y, $\theta$) 위치에 있다면, 제어 매개변수 V-left와 V-right가 주어졌을 때, $t+\delta t$ 시점의 자세 (x', y', $\theta'$)를 구했다.***

이제 이걸 역으로 (역운동학)

***로봇이 t 시점에서 (x, y, $\theta$) 위치에 있다면, $t+\delta t$ 시점의 자세가 (x', y', $\theta'$)를 만드는 제어 매개변수 V-left와 V-right를 구해라!***

도 역시 구할 수 있어야 한다.

차동구동의 경우 이 문제에는 해가 존재하지 않을 수 도 있다. 바퀴의 속도를 변경하는 것만으로 모든 종류의 자세를 취할 수 있는 것은 아니기 때문이다. 
* 그래서 이런 로봇의 제약사항을 일컬어 비홀로노믹
* 항상 풀수 있는 경우 홀로노믹 이런 로봇은 언제나 어떤 자세로든 옮겨갈 수 있다.

### 비전센서 프로그래밍

* OpenCV
  * 컴퓨터비전기반 라이브러리, 인텔 러시아 연구소 Itseez에 의해 주도적 지원
  * 파이썬 C C++주 
* OpenNI
  * 자연스러운 상호작용 어플리케이션 작성
* PCL 2D 3D 이미지와 포인트 클라우드 처리를 위한 대규모 오픈 프로젝트
  * 이미 로스에 통합 


리눅스를 설치해보자!

예전에 우분투 10.4를 이미 사용해봤지만 최신 우분투19.4 까지 나왔으니 내 개인노트북 안쓰는걸 가져다가 몽땅 날리고 우분투만 위한 노트북으로 만들면서 사용해보려한다.

우분투 버전은 ROS까지 지원가능한 그리고 가장 최신버전을 찾아보니 18.04로 일단 결정했다. 그리고 USB를 이용해 설치를 진행했다.


### 우분투 설치

<img src="https://idchowto.com/wp-content/uploads/2015/11/1234-1024x724.png" width="50%" height="100%">

* https://www.ubuntu.com/download/desktop
* 직전 버전이면서 많이 사용하는 버전은
  * ubuntu-16.04.6-desktop-amd64
  * 이거 다음 그리고 또 다음이 나왔으니 최신 버전중에서도 최적화된 건 뭘까 찾아봤다
* 가장 최신19는 아니지만 LTS 최신에 ROS 지원까지 제대로 맞춰져있는
  * ubuntu-18.04.2-desktop-amd64.iso
  * cd 이미지 파일로 받았고 이걸 아래 이어지는 USB 설치용으로 바꿀!

### 우분투 from USB

<img src="https://rufus.ie/pics/rufus_ko.png" width="40%" height="100%">

* https://rufus.ie/
  * 이렇게 USB에서 바로 설치할 수 있게 도와주는 프로그램
* Rufus 3.5 Portable (1 MB)
  * 포터블이라고 되어있는거 받아서 사용했다.
    * 상단에` USB 장치` 맞는지 확인하고
    * `부트선택`에 원하는 우분투 버전 선택한 다음에
    * 딴거 안건드리고 맨 밑 `시작` 버튼!

### 설치과정

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


### ROS

* http://wiki.ros.org/ko
* ROS Installation Options
  * ROS는 우분투 LTS 2년주기에 맞춰서 나온다
  * 각 ROS 버전은 5년을 보장(?) 한다.
* 로봇 쪽에선 2016년 버전을 많이 사용하는 듯 하다.
  * <img src="https://raw.githubusercontent.com/ros-infrastructure/artwork/master/distributions/kinetic.png" width="50%" height="100%">
  * Released May, 2016
    * LTS, supported until April, 2021
* 최근 버전 2018 
  * <img src="https://raw.githubusercontent.com/ros-infrastructure/artwork/master/distributions/melodic_with_bg.png" width="50%" height="100%">

    * Released May, 2018
    * Latest LTS, supported until May, 2023


아직 설치 안함.
