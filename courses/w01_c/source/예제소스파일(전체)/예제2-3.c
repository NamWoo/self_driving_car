#include <stdio.h>

int main(void)
{
	printf("12345678901234567890\n"); // 화면에 칸 번호 출력
	printf("Be happy\n");             // "Be happy"를 출력하고 줄을 바꿈
	printf("My\tfriend\n");           // "My"를 출력하고 탭 위치로 이동 후에 "friend" 출력
	printf("Goot\bd\tchance\n");      // t를 d로 바꾸고 탭 위치로 이동 후에 "chance" 출력
	printf("Cow\rW\a\n");             // C를 W로 바꾸고 벨 소리를 낸다.

	return 0;
}