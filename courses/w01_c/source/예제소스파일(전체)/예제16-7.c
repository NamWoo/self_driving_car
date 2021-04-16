#include <stdio.h>
#include <string.h>
#include <stdlib.h>                   // malloc, atoi 함수 사용을 위한 헤더 파일

void print_str(char **);              // 문자열 출력 함수 선언

int main(int argc, char **argv)
{
	char temp[80];                    // 문자열 입력을 위한 임시 char 배열
	char **str;                       // 포인터 배열로 사용할 동적 할당 영역 연결
	int max;                          // 최대 입력 문자열 수를 저장
	int i;

	max = atoi(argv[1]);              // 두 번째 명령행 인수를 정수로 변환
	str = (char **)malloc((max + 1) * sizeof(char *));  // 포인터 배열의 동적 할당
	i = 0;
	while (1)
	{
		printf("문자열을 입력하세요 : ");
		gets(temp);                                     // 문자열 입력
		if (temp[0] == '\0') break;                     // 엔터만 입력하면 반복 종료

		str[i] = (char *)malloc(strlen(temp) + 1);      // 문자열 저장 영역 동적 할당
		strcpy(str[i], temp);                           // 문자열 복사
		i++;
		if (i == max)                                   // 입력된 문자열의 수를 검사
		{
			printf("문자열 입력이 최댓값을 모두 채웠습니다.\n");
			break;
		}
	}
	str[i] = 0;                       // 입력이 끝난 후 널포인터로 마감
	print_str(str);                   // 입력된 문자열 출력

	i = 0;
	while (str[i] != 0)
	{
		free(str[i]);                 // 문자열을 저장한 동적 할당 영역 반환
		i++;
	}
	free(str);                        // 포인터 배열을 위해 동적 할당한 영역 반환

	return 0;
}

void print_str(char **ps)             // 2중 포인터 ps는 포인터 배열처럼 사용
{
	while (*ps != 0)                  // ps 배열 요소의 값이 널포인터가 아닌 동안
	{
		printf("%s\n", *ps);          // ps 배열 요소가 연결하고 있는 문자열 출력
		ps++;                         // 다음 요소로 이동
	}
}