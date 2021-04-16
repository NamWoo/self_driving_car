#include <stdio.h>
#define FEMALE
#define LEVEL 5

int main(void)
{
#ifdef MALE
#if LEVEL == 3
	double std_height[LEVEL] = {49.4, 74.8, 85.0};              // 남자 3단계
#else
	double std_height[LEVEL] = {49.4, 66.3, 74.8, 79.9, 85.0};  // 남자 5단계
#endif
#elif LEVEL == 3
	double std_height[LEVEL] = {50.1, 76.0, 86.2};              // 여자 3단계
#else
	double std_height[LEVEL] = {50.1, 67.6, 76.0, 81.2, 86.2};  // 여자 5단계
#endif
	double my_height[LEVEL];
	double tot = 0, avg, diff;
	int i;

	printf("@ 단계별 키 입력(%d단계) : ", LEVEL);
	for(i = 0; i < LEVEL; i++)
	{
		scanf("%lf", my_height + i);
	}

	printf("@ 단계별 표준키와 차이 : ");
	for(i = 0; i < LEVEL; i++)
	{
		diff = my_height[i] - std_height[i];
		tot += diff;
		printf("%.1lf  ", diff);
	}
	printf("\n");
	avg = tot / LEVEL;
	printf("@ 차이 평균 : %.1lf\n", avg);

	return 0;
}
