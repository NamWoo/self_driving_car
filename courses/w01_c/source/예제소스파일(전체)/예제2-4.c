#include <stdio.h>

int main(void)
{
	printf("%d\n", 10);       // %d 위치에 10 출력
	printf("%lf\n", 3.4);     // %lf 위치에 3.4를 소수점 이하 6자리까지 출력
	printf("%.1lf\n", 3.45);  // 소수점 이하 첫째 자리까지 출력
	printf("%.10lf\n", 3.4);  // 소수점 이하 10자리까지 출력
	printf("%d과 %d의 합은 %d입니다.\n", 10, 20, 10 + 20);
	printf("%.1lf - %.1lf = %.1lf\n", 3.4, 1.2, 3.4 - 1.2);

	return 0;
}