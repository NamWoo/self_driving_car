#include<stdio.h>

void main(void)
{

int segmentLEDs[] = {2, 3, 4, 5, 6, 7, 8, 9};
// 지정된 LED 개수
int segmentLEDsNum = 8;

// 각 숫자에 대한 LED 설정 값을 정의합니다.
// 숫자에 매칭되는 LED의 로직레벨을 LOW(0) 상태로 설정합니다.
int digitForNum[10][8] = {
	{0, 0, 0, 0, 0, 0, 1, 1}, //0
	{1, 0, 0, 1, 1, 1, 1, 1}, //1
	{0, 0, 1, 0, 0, 1, 0, 1}, //2
	{0, 0, 0, 0, 1, 1, 0, 1}, //3
	{1, 0, 0, 1, 1, 0, 0, 1}, //4
	{0, 1, 0, 0, 1, 0, 0, 1}, //5
	{0, 1, 0, 0, 0, 0, 0, 1}, //6
	{0, 0, 0, 1, 1, 1, 1, 1}, //7
	{0, 0, 0, 0, 0, 0, 0, 1}, //8
	{0, 0, 0, 0, 1, 0, 0, 1}  //9
};

// 실행시 가장 먼저 호출되는 함수이며, 최초 1회만 실행됩니다.
// 변수를 선언하거나 초기화를 위한 코드를 포함합니다.
void setup() {
	// 7세그먼트 각각 LED에 연결된 핀을 OUTPUT으로 설정합니다.
	for (int i = 0 ; i < segmentLEDsNum ; i++) {
		pinMode(segmentLEDs[i], OUTPUT);
	}
}

// setup() 함수가 호출된 이후, loop() 함수가 호출되며,
// 블록 안의 코드를 무한히 반복 실행됩니다.
void loop() {
	// 0부터 9까지 숫자를 순서대로 표시합니다.
	for (int i = 0 ; i < 10 ; i++) {
		// 각 숫자에 대한 각각 LED의 로직레벨을 설정합니다.
		for (int j = 0 ; j < segmentLEDsNum ; j++) {
			digitalWrite(segmentLEDs[j], digitForNum[i][j]);
		}
		// 1초 동안 대기합니다.
		delay(1000);
	}
}
	
	
}


