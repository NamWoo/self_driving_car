#include <stdio.h>
#include <string.h>

int main(void)
{
	char word[10][21];  // 최대 10개의 단어, 단어의 길이는 최대 20자
	char temp[21];      // 단어 입력 시 사용할 임시 배열
	int cnt;            // 입력된 단어의 수
	int i, j, dup, find;

	i = 0;
	while(1)
	{
		printf("> 단어 입력 : ");
		scanf("%s", temp);
		if(strcmp(temp, "end") == 0) break;      // end가 입력되면 종료
		
		// 입력된 단어가 있는지 중복 여부 검사
		dup = 0;                                 // 입력된 단어가 없다고 가정
		for(j = 0; j < i; j++)                   // 현재 입력된 단어까지만 검사
		{
			if(strcmp(temp, word[i]) == 0)       // 같은 단어가 있으면
			{
				dup = 1;                         // dup의 상태를 바꾸고
				break;                           // 검사 종료
			}
		}
		if(dup == 1)                             // 검사 결과 같은 단어가 있으면
		{
			printf("# 이미 입력되었습니다!\n");  // 메시지 출력하고
			continue;                            // 배열에 넣는 작업을 건너 뜀
		}
		// 중복 검사 끝

		strcpy(word[i], temp);                   // 입력된 단어를 배열에 복사
		i++;                                     // 배열의 다음 위치로 이동
	}
	cnt = i;                                     // 입력된 단어의 수 보관
	printf("# 총 %d개의 단어가 입력되었습니다!\n\n", cnt);

	while(1)
	{
		printf("> 검색 단어 (종료는 end입력) : ");
		scanf("%s", temp);                       // 검색할 단어 입력
		if(strcmp(temp, "end") == 0) break;      // end와 같으면 종료

		find = 0;                                // 일단 같은 단어가 없다고 가정
		for(i = 0; i < cnt; i++)                 // 입력한 단어 수 만큼 찾는다
		{
			if(strcmp(temp, word[i]) == 0)       // 같은 단어가 있으면
			{
				find = 1;                        // find의 상태를 변경
				break;                           // 찾는 과정 종료
			}
		}

		if(find == 1)                            // find의 상태가 1이면 찾은 것임
		{
			printf("# %d번째 같은 단어가 있습니다!\n\n", i + 1);
		}
		else
		{
			printf("# 없는 단어입니다.\n\n");
		}
	}

	return 0;
}
