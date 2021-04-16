// 가장 긴 단어찾기 프로그램

#include <stdio.h>

int main(void)
{
	int ch;
	int len, max = 0;

	while(1)
	{
		len = 0;

		ch = getchar();                    // 문자 입력
		while((ch != -1) && (ch != '\n'))  // Ctrl+Z키를 누르거나 엔터 키를 치지 않는 동안
		{
			len++;                         // 문자의 수를 센다
			ch = getchar();
		}
		if(ch == -1) break;                // Ctrl+Z키가 눌려진 경우 입력 종료
		if(len > max) max = len;           // 새로 입력한 단어의 길이가 현재 가장 긴 		                                   
	}                                      // 단어의 길이보다 길면 그 값을 가장 긴 길이로 설정
	printf("가장 긴 단어의 길이 : %d\n", max);

	return 0;
}