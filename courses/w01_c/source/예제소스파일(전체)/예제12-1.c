#include <stdio.h>

int main(void)
{
	printf("주소값 : %p\n", "mango");               // 주소값 출력
	printf("첫 번째 문자 : %c\n", *"mango");        // 간접참조 연산
	printf("두 번째 문자 : %c\n", *("mango" + 1));  // 포인터 연산식
	printf("세 번째 문자 : %c\n", "mango"[2]);      // 배열 표현식

	return 0;
}