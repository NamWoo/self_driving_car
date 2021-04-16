#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE *ifp, *ofp;                  // 파일 포인터 선언
	char str[80];                     // 입력한 문자열을 저장할 배열
	char *res;                        // fgets 함수의 반환값을 저장할 변수

	ifp = fopen("a.txt", "r");        // 입력 파일을 읽기 전용으로 개방
	if (ifp == NULL)                  // 개방 여부 확인
	{
		printf("입력 파일을 열지 못했습니다.\n");
		return 1;
	}

	ofp = fopen("b.txt", "w");        // 출력 파일을 쓰기 전용으로 개방
	if (ofp == NULL)                  // 개방 여부 확인
	{
		printf("출력 파일을 열지 못했습니다.\n");
		return 1;
	}

	while (1)                         // 문자열을 입력하고 출력하는 과정 반복
	{
		res = fgets(str, sizeof(str), ifp);
		if (res == NULL)              // 반환값이 널포인터면 반복 종료
		{
			break;
		}
		str[strlen(str) - 1] = '\0';  // 개행문자 제거
		fputs(str, ofp);
		fputs(" ", ofp);
	}
	fclose(ifp);                      // 입력 파일 닫기
	fclose(ofp);                      // 출력 파일 닫기

	return 0;
}