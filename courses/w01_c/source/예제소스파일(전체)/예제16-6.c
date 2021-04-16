#include <stdio.h>

int main(int argc, char **argv)   // 명령행 인수를 받을 매개변수
{
	int i;

	for (i = 0; i < argc; i++)    // 인수 개수 만큼 반복
	{
		printf("%s\n", argv[i]);  // 인수로 받은 문자열 출력
	}

	return 0;
}