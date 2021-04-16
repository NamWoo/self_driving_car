#include <stdio.h>

int main(void)
{
	int ch;                           // int형 변수

	printf("문자 a의 아스키 코드값 : %d\n", 'a');
	printf("아스키 코드값이 97인 문자 : %c\n", 97);
	printf("문자 상수의 크기 : %d바이트\n", sizeof('a'));

	ch = 'a';                         // 문자를 int형 변수에 대입
	ch++;                             // 아스키 코드값 1 증가
	printf("문자 %c의 아스키 코드값 : %d\n", ch, ch);

	return 0;
}