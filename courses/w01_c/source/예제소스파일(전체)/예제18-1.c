#include <stdio.h>

int main(void)
{
	FILE *fp;                                   // 파일 포인터

	fp = fopen("a.txt", "r");                   // a.txt 파일을 읽기 전용으로 개방
	if (fp == NULL)                             // fp가 널포인터면 파일 개방 실패
	{
		printf("파일이 열리지 않았습니다.\n");  // 안내 메시지 출력
		return 1;                               // 프로그램 종료
	}
	printf("파일이 열렸습니다.\n");
	fclose(fp);                                 // 파일 닫기

	return 0;
}