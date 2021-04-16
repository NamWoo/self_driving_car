// 파일 이름을 '예제19-1-main.c'에서 main.c로 바꿔 사용하세요.

#include <stdio.h>     // 시스템 헤더 파일의 내용 복사
#include "student.h"   // 사용자 정의 헤더 파일의 내용 복사

int main(void)
{
	Student a = { 315, "홍길동" };                   // 구조체 변수 선언과 초기화

	printf("학번 : %d, 이름 : %s\n", a.num, a.name); // 구조체 멤버 출력

	return 0;
}
