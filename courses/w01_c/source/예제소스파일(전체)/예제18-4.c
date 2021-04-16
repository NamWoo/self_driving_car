#include <stdio.h>

int main(void)
{
	int ch;              // 입력한 문자를 저장할 변수

	while (1)
	{
		ch = getchar();  // 키보드에서 문자 입력
		if (ch == EOF)   // Ctrl + Z로 입력 종료
		{
			break;
		}
		putchar(ch);     // 화면에 문자 출력
	}

	return 0;
}