#include <stdio.h>

int main(void)
{
	char ch1 = 'A';  // 문자로 초기화
	char ch2 = 65;   // 문자 'A'의 아스키 코드값으로 초기화

	printf("문자 %c의 아스키 코드값 : %d\n", ch1, ch1);
	printf("아스키 코드값이 %d인 문자 : %c\n", ch2, ch2);

	return 0;
}