#include <stdio.h>

int main(void)
{
	printf("%.1lf\n", 1e6);     // 지수 형태의 실수를 소수점 형태로 출력
	printf("%.7lf\n", 3.14e-5); // 소수점 이하 7자리까지 출력

	return 0;
}