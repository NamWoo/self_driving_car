
전반적인 용어의 개략적 훑기! 자세한건 목요일날 다시 정리

* Abort mode
  * 비정렬 액세스 때 실행
* Undefined mode
  * 정의되지 않은 명령, 수행하려고 하면 수행되는 프로세서의 동작
* syetem mode
  * 애매한 모드
  * user, svc mode와 비슷하지만 쓰임새가 다르다. 
  * privilege mode

Operating 모드의 변경

저가형 마이크로컨트롤러, 익셉션, 인터럽트와 같은 의미다. 여기서는 ARM에서는  Exception. 약간 더 광범위한 범위다. 

* 정상적인 IRQ, FIQ 포함한
* 비정상적인 것들 모두!
  * 비정상의 대표적 ABORT

### ARM Processor 의 레지스터

32bit 길이의 37개 레지스터가 있다. 

* 30개의 범용 General purpose
  * r01 ~ r15까지
* 특수목적 reg
  * pc
  * cpsr
  * spsr
  * lr
    * r로 시작하지 않는다.


