#include <stdio.h>

#define VER 7       // 치환될 부분이 있는 매크로명 정의
#define BIT16       // 치환될 부분이 없는 매크로명 정의

int main(void)
{
	int max;

#if VER >= 6                          // 매크로명 VER이 6 이상이면
	printf("버전 %d입니다.\n", VER);  // 이 문장 컴파일
#endif                                // if의 끝

#ifdef BIT16                          // 매크로명 BIT16이 정의되어 있으면
	max = 32767;                      // 이 문장 컴파일
#else                                 // BIT16이 정의되어 있지 않으면
	max = 2147483647;                 // 이 문장 컴파일
#endif                                // ifdef의 끝

	printf("int형 변수의 최댓값 : %d\n", max); // max 출력

	return 0;
}