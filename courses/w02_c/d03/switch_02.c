//INIT 
///////////////////////////////////////////////////////////////////
//LED init, off state
//GPG4,GPG5,GPG6,GPG7
//GPGCON OUTPUT mode 01 
//GPG4[9:8] ~ GPG7[15:14]
//all clear 0
rGPGCON &= ~(0xff<<8);	//ready 00
rGPGCON &= ~(0x55<<8);	//OUTPUT mode 01
//00으로 초기화 한 뒤에 GPG4 부터 GPG7까지 사용할 LED 출력모드 설정 
//0101(55)로 설정할 것이기에 해당부분만 00으로 바꿔준뒤에 01 설정.
//해당 비트 8~15에 1100 같이 잘못된 설정(?)이 있을 수 있으니 
//0101을 설정하기 위해 먼저 0000 으로 설정 후 0101로 바꿔줬다. 

//GPGDAT
//GPG[15:0]
rGPGDAT |= (0xf<<4);	//set 1, LED off
//출력모드로 설정한 핀을 풀업저항에 맞게 1로 LED 끔 설정 
//여긴 바로 1111 이니까 0이든 1이든 초기화 없이 모두 1로 설정

///////////////////////////////////////////////////////////////////
//KEY init
//풀업이기 때문에 하단 GPG0, GPF7 두 부분의 
//GPGCON을 OUTPUT mode 로 
//GPGDAT를 0으로 GND 설정을 해준다. 
//GPG0
rGPGCON &= ~(0x11);		//ready 00
rGPGCON |= (0x01);		//OUTPUT mode 01 
//위와 마찬가지로 00으로 초기화 한 뒤에 GPG0부분만 01로 설정 

rGPGDAT &= ~(0x01);		//GND, 해당 비트만 clear 0. 

//GPF7
rGPFCON &= ~(11<<14);	//ready 00
rGPFCON |= (0x01<<14);	//OUTPUT mode 01
//위와 마찬가지로 00으로 초기화 한 뒤에 GPF7부분만 01로 설정 

rGPFDAT &= ~(0x01<<14);	//GND, 해당 비트만 clear 0.
//여기까지 풀업저항 회로도에서 상단에 VDD 전압이
//지금 설정한 두 곳을 0으로 설정해 전류가 흐르게끔 설정했다.

///////////////////////////////////////////////////////////////////
//GPF[2:6] 부분에서 신호의 변화를 확인하기 위해 
//GPFCON을 INPUT mode 로 설정해 들어오는 신호를 확인하게 설정하고 
//GPFDAT에서 실제 변하는 값을 if 문으로 확인하게 된다. 
//먼저 여기도 역시 초기화 설정 진행
//GPF[2:6] GPF2[4:5]~ GPF6[12:13] 까지 모두 INPUT mode clear 00.
rGPFCON &= ~(3ff<<4);	//ready 00 and INPUT mode clear 00.
//GPF2,GPF3,GPF4,GPF5,GPF6 을 모두 0으로 INPUT mode 로 설정하면
//이 핀에서 신호를 확인할 수 있게, 들어올 수 있게 한 것이고
//스위치를 누르면 기존에 1이었던 신호가 0이 되면서 확인할 수 있게 되는 것. 


//SWITCH CHECKING
///////////////////////////////////////////////////////////////////
//SW4번 또는 SW9번을 누르면 GPF2	//해당 GPF 가 1 to 0 
//SW5번을 누르면 GPF3
//SW6번을 누르면 GPF4
//SW7번을 누르면 GPF5
//SW8번을 누르면 GPF6	//GPF7 와 연결 

//SW9번을 누르면 GPF2	//해당 GPF 가 1 to 0 
//SW10번을 누르면 GPF3
//SW11번을 누르면 GPF4
//SW12번을 누르면 GPF5
//SW13번을 누르면 GPF6	//GPG0 와 연결

//현재 GPG0, GPF7 둘 다 회로도에 의해 
//OUTPUT mode 0으로 되어있는 상태 
//SW4과 SW9번은 같은 반응 
//SW5과 SW10번은 같은 반응 
//SW6과 SW11번은 같은 반응 
//SW7과 SW12번은 같은 반응
//SW8과 SW13번은 같은 반응 

//먼저 스위치 짝이 같은 반응이 나오는지 확인하기 위해선 
//SW4번 또는 SW9번을 누르면 해당 비트가 1 to 0 
//SW4, SW9는 GPF2 의 GPFDAT[0:7]중 해당 비트를 확인하니 
//-----1-- 나머지는 그대로 두고 3번째 1 부분만 0이 되는지 확인한다. 
if (rGPFDAT & 0x4) == 0x00) return 4;
//스위치를 누르기 전 -----1-- 과 00000100 를 and(&)연산을 하면
//모든 비트는 0으로 변하고 해당 비트만 1로 나타난다. 00000100
//이때 스위치를 누르면 1이 0으로 변하면서 모든 비트가 0이 되고 
//그때 조건문을 걸어 모든 비트가 0이면
//return 값으로 스위치 설정을 하면 된다. 



