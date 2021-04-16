/etc$ rm wodim.conf
permission denied



하드웨어 레지스터 (hardware register)
프로세서 레지스터 (processor register)
시프트 레지스터 (shift register)


용도가 다르다


```asembley
ldr r0


```

인터럽트할 때 마스터 dma 123 함수 호출, 마스터 헨들러 먼저 나와야 한다.


##


원하는 단어 입력후 컨트론 쉽트트 에프

void HOW_TO_RETURN(void)
{
    return;
}

어셈블리에서 레이블은 만능. 함수이름, 배열이름, 변수이름 콘스탄트 변수이름 뭐든 변신할 수 있는 것들.

어셈블리 문법 단순

@레이블 작성법 /* */

1. 알파뉴메릭( _ 포함)으로 작성
2. 1번 COL에 작성
3. 콜론(:) 은 있을 수도 있고 없을 수 있다.. 어떤 컴파일은 안될 수도 있다.

HOW_TO_RETURN:   /*레이블*/ 하면 utf8로바뀜


mov r0, #0 이렇게 하면 레이블은 아니다. 
명령어는 탭문자! 공백~! 두칸, 4칸.
탭 많이 쓰지 말아라. 


대문자면 초지일관 대문자. 소문자는 소문자.

op코드? 하나로 밀고 가자. 소문자 추천.
레지스터 일반적이게 소문자.


브렌치 위드 링크 goto

링크레지스터를 가지고 브렌치한다 이걸 씨에서는 함수호출


bl HOW_TO_RETURN
* LR = 복귀주소(리턴어드레스 저장주소 가 LR)
* PC = 이동할 함수 주소
이렇게 하면 프로그램이 bl로 이동


bl	HOW_TO_RETURN
	.loc 1 30 0
	ldr	r0, .L2+12

.globl  HOW_TO_RETURN

글로발 해야 다른 파일에서 접근 가능.

슈도코드 유사어셈블러, .globl 이다.
sl

니모닉 코드 디렉티브즈 

. 붙어이으면 다 지시어 니모닉코드 유사코드 directives(지시어)


b . @ while(1); 어셈블리 무한루프 . self의미 나한테 가는 의미.


전달인자 방법, 리턴값 받는 방법 배우겠다. 이따가.

전달인자를 레지스터를 통해서 전달받는다?


	mov r1,r0 @r1=r0  



    user@linux:~/Desktop/m2450/lab/student/01_Hello_ARM_Student$ /opt/CodeSourcery/Sourcery_G++_Lite/bin/arm-none-eabi-gcc -c -I/home/user/Desktop/m2450/lab/student/01_Hello_ARM_Student -I/opt/CodeSourcery/Sourcery_G++_Lite/arm-none-eabi/lib/include -I/opt/CodeSourcery/Sourcery_G++_Lite/lib/gcc/arm-none-eabi/4.5.2/include -g -Wall -Wstrict-prototypes -Wno-trigraphs -O0 -fno-strict-aliasing -fno-common -pipe -march=armv4t -mtune=arm9tdmi -fno-builtin -mapcs -S -o Main.S Main.c


 int HOW_TO_RETURN(int,int,int,int,int,int,int);


	mov	r3, #5
	str	r3, [sp, #0]
	mov	r3, #6
	str	r3, [sp, #4]  6이 여기 써지고
	mov	r3, #7   ㄱ3 7s넣으면 
	str	r3, [sp, #8]  일로 들어가는
	mov	r0, #1
	mov	r1, #2
	mov	r2, #3
	mov	r3, #4

    4번째이후부턴 스택을 이용해서

    sp 가 가리키는 곳에 들어가는

    ㅇ리부는 레지이용해서 넘기고 일부는 여기로

    또 속도도 스택이 훨씬 느리다.

매개변숮 ㅓㄴ달방법, C언어랑 어셈블리 호출관계

`ATPCS(ARM/Thumb Procedure Call Standard)`

75p

psr레지스터부터 시작.


## 동작모드의 변환

operating Mode

IRQ 모드비트 어떻게 바뀌어야 할까?

Mode 10010
I/F 0/ x dont care
T bit 0


```Makefile 62
$(OBJDUMP) -d $(TOPDIR)/MDS2450 > $(TOPDIR)/MDS2450.dis
```


```bacch art
	.globl IsrIRQ
IsrIRQ: 
        sub     sp,sp,#4       //reserved for PC
        stmfd   sp!,{r8-r9}   
```

4차원세계 이상한 나라의 폴 예

```
cd ..
cd 04_De
subl .
```
c에서 하는 방법
__attribute__(()) 이게 동작모드 동시 업데이트 기능, 동작모드 동시 복원되는 거다. 이거 없으면그냥 부

어셈블리로 하는 방법도 배울 것이다.
