# SW개발 및 실무 프로젝트 과정

***NVIDIA 플랫폼 기반 자율주행차 구현을 위한 SW개발 및 실무프로젝트 과정*** with 한컴MDS


![](./img/intro.jpg)

* [한컴MDS Academy, 상세 커리큘럼](http://www.mdsacademy.co.kr/customer/board_view.php?board_idx=1585&schField=&schWord=nvidia&search_div=notice&size=10&page=1)


<img src="./intro.jpg" width="60%" height="60%">

* (.feat수업에 임하는 나의 자세)


>"Never give up. Without commitment, you’ll never start, but more importantly, without consistency, you’ll never finish. It’s not easy. Keep working. Keep striving. Never give up. Fall down seven times, get up eight. Ease is a greater threat to progress than hardship, so keep moving, keep growing, keep learning. See you at work.”
>
>"절대 포기하지 마세요. 헌신없이는 그 무엇도 시작할 수 없어요. 더 중요한 것은 꾸준함 없이는 결코 그 무엇도 끝낼 수 없다는 거죠. 그것은 쉽지 않습니다. 그래도 계속 하세요. 노력하세요. 결코 포기하지 마세요. 7번 넘어지면 8번 일어나세요. 성장을 방해하는 가장 큰 적은 편안함입니다. 계속 움직이고, 계속 성장하고, 계속 배워나가세요." ***덴젤워싱턴***





## 교육과정 그리고 정리

* 총 6개월 과정 (일 8시간, 총 24주)
* 단계별로 여러 보드를 다루면서 학습하고 Embedded 환경에서 머신러닝을 가지고 전력최적화 s/w최적화를 이루며 스스로 주행하는 차량구현을 모토로 한다.
  * ARM9 s3c2450 MDS2450 board
  * Infineon AURIX TC27CA + Lauterbach Trace32 debugging tool
  * NVIDIA TX2
* C, C++, Python, git, linux, shell, make, kernel, module, device driver, machine learning, deep learning, keras, algorithm, optimization ...
* 다뤄야하는 주제도 많고 거기다 어렵고 무겁고 끝도 없고...

>버티는게 이기는거다. 매일매일 쏟아지는 지식들 속에서 흘려 버릴건 흘리고 새로운 걸로 다시 퐉퐉 채우면서 정리를 하자! 나중에 다시 보고 되새김하며 주어담길 바라며 ***과정이 끝날 즈음 남우에게 시작 때 남우가***

| Week| course             |        Abstract        |실습장비|강사님|
|:---:| :----------------- | :------------- |:---:|:---:|
| 0 | [OT](./courses/OT.md)                 |   첫 오리엔테이션
| 1 | [C Programming](./courses/w01.md)        | C언어 집중교육           |               |김성영|
| 2 | [Embedded C](./courses/w02.md)           | Embedded C언어 집중교육  |ARM9 S3C2450 MDS2450 |김성영|
| 3 | [C++ Programming ](./courses/w03.md)     | C++언어 집중교육    ||서광원|
| 4 | [Python Programming ](./courses/w04.md)  | Python 집중교육   ||서영진|
| 5 | [차량용 프로세서 디바이스제어]           | 임베디드 리눅스, ARM 이해 |ARM9 S3C2450 MDS2450|홍영기|
| 6 | [차량용 프로세서 이해 및 활용]           | 리눅스 포팅, 어셈블리어 실습|ARM9 S3C2450 MDS2450|홍영기|
| 7 | [차량용 OS 시스템 프로그래밍]           | 리눅스 시스템 프로그래밍|ARM9 S3C2450 MDS2450 |서광원|
| 8 | [자율주행기능구현을위한차량용SW개발]     |인피니온보드 시스템 이해 그리고 실습|Infineon AURIX TC27CA, Lauterbach Trace32|황호현
| 9 | [차량용 OS 디바이스 프로그래밍]         |모듈, 디바이스 드라이버|ARM9 S3C2450 MDS2450|김성영
|...|                                         | 앞으로 11월까지....  |

<!-- | Week | course             |             Link              |       내용        |강사|
| :----- | :----------------- | :---------------------------: | :-------------: |:---:|
| !      | OT                 | [L I N K]|    첫 간단한 오티     | 
| 1 | [C Programming]((./courses/w01.md)       | [L I N K](./courses/w01.md)  |    C언어 집중교육     |
| 2 | Embedded C         | [L I N K](./courses/w02.md)  | ARM9 S3C2450 실습 |
| 3 | C++ Programming    | [L I N K](./courses/w03.md)  |   C++언어 집중교육    |
| 4 | Python Programming | [L I N K](./courses/w04.md)  |   Python 집중교육   |
| 5 | 차량용 프로세서 디바이스제어    |[L I N K]| 임베디드 리눅스 ARM 
| 6 | 차량용 프로세서 이해 및 활용   |[L I N K]| 리눅스 포팅, 어셈블리어
| 7 | 리눅스 OS 프로그래밍   |[L I N K]| 리눅스 프로그래밍, 쉘 스크립트
| 8 | 자율주행기능구현을위한차량용SW개발|[L I N K]|Infineon AURIX, Lauterbach, Trace32
| 9 | |[L I N K]|Infineon AURIX, Lauterbach, Trace32

| ...    |                    |                               | 앞으로 11월까지....  | -->

<!-- (./courses/OT/OT.md) -->

* 사용 칩, 보드 상세정보
* 강사님 상세정보

***정리 밀렸다.. 다시 하나씩 복구 시작!***


|||
|:---:|:---:|
|나의 주간 생활, 공부 리포트|[L I N K]
|||



## 아카데미 동기들 GITHUB

<!-- * 현재 총원 23명
* git 을 전혀 안쓰는 친구들이 대부분 아니 거의 전부였기에
  1. 열심히 전파해서 가입도모!
  2. Team Proj 진행!
  3. 그리고 merge의 세계로 ~~ 빠뜨리쟈!
     * 이땐 크라켄? 소스트리? -->

|  샘  |                                      |                                     |                                      |       |                                    |                문                |
|:---:| :----------------------------------: | :---------------------------------: | :----------------------------------: | :---: | :--------------------------------: | :-----------------------------: |
|      | [재필](https://github.com/seomyunfeel) | [이경](https://github.com/leekyung91) | [창호](https://github.com/changhonam)  |       |  [윤수](https://github.com/susu210)  | [한빈](https://github.com/Mombin) |
| 우성 | [민준](https://github.com/KimMinJoon)  |   [남우](https://github.com/NamWoo)   | [봉준](https://github.com/iambongjun)  |       | [동훈](https://github.com/d-h-k)|                                 |
| 윤형 |        |   [경호](https://github.com/bkh751)   | [태우](https://github.com/taewookimmr) |       | [보경](https://github.com/boku-kim)  |                                 |
|      |   [지선](https://github.com/LJSsun)    | [소현](https://github.com/So-Is-Cow)  |  [민지](https://github.com/youminji)   |       |                 현민                 |                                 |
| 강석 |                                      |[기찬](https://github.com/allowme2)|  |       |                 지윤                 |               규식                |

* 최초시작 25명, 현재는 21명
  * 취업 2명(3주차, 8주차)
  * 더 넓은 세상으로 2명(2주차, 8주차)
<!-- * 취업성공
  * [용준](https://github.com/chrno0621)
   -->
