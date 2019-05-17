#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int input_intro(char (*intro)[80]);

int main(void)
{
	char temp[80];     // 임시 char 배열
	char *str[3];      // 동적 할당 영역을 연결할 포인터 배열
	int i, j, cnt;             // 반복 제어 변수

	while(1)
	{				
		if(cnt == 100)
		{
			printf("단어입력 100개 제한\n");
			break;
		}
		printf("단어 입력 : ");
//		gets(intro[cnt]);
		gets(temp);  

		if (strcmp(temp, "end")=0) break;
//		if(strcmp(intro[cnt], "end")==0) break;
		strcpy(intro[cnt], temp);
		
		str[cnt] = (char *)malloc(strlen(temp) + 1);  // 문자열 저장 공간 할당
		strcpy(str[cnt], temp);                       // 동적 할당 영역에 문자열 복사
		cnt++;
	}


	for (i = 0; i < 3; i++)
	{
		
		if (str[j] == str[i])
		
	}




	for (i = 0; i < 3; i++)
	{
		printf("%s ", str[i]);                     // 입력된 문자열 출력
	}

	for (i = 0; i < 3; i++)
	{
		free(str[i]);                               // 동적 할당 영역 반환
	}

	return 0;
}
