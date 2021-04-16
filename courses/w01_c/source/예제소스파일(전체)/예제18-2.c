#include <stdio.h>

int main(void)
{
	FILE *fp;                  // 파일 포인터 선언
	int ch;                    // 입력한 문자를 저장할 변수

	fp = fopen("a.txt", "r");  // 읽기 전용으로 파일 개방
	if (fp == NULL)            // 파일이 개방되었는지 확인
	{
		printf("파일이 열리지 않았습니다.\n");
		return 1;
	}

	while (1)
	{
		ch = fgetc(fp);        // 개방한 파일에서 문자 입력
		if (ch == EOF)         // 함수의 반환값이 EOF면 입력 종료
		{
			break;
		}
		putchar(ch);           // 입력한 문자를 화면에 출력
	}
	fclose(fp);                // 파일 닫음

	return 0;
}