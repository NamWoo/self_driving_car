#include <stdio.h>

int main(void)
{
	int i;                     // 반복 횟수를 세기 위한 제어 변수
	int sum = 0;               // 1부터 10까지의 합을 누적할 변수

	for (i = 1; i <= 10; i++)  // i는 1부터 10까지 증가하면서 10번 반복
	{
		sum += i;              // i값을 sum에 누적
		if (sum > 30) break;   // 누적한 값이 30 보다크면 반복문을 끝낸다.
	}
	printf("누적한 값 : %d\n", sum);
	printf("마지막으로 더한 값 : %d\n", i);

	return 0;
}