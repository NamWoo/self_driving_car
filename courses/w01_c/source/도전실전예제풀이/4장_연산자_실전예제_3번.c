#include <stdio.h>

int main(void)
{
	int mileage, speed, rest;
	int hour, min;
	double sec;

	printf("거리와 속력 입력 : ");
	scanf("%d%d", &mileage, &speed);

	hour = mileage / speed;
	rest = mileage % speed;
	min = (rest * 60) / speed;
	rest = (rest * 60) % speed;
	sec = (rest * 60.0) / speed;
	
	printf("소요 시간은 %d시간 %d분 %.3lf초입니다.\n", hour, min, sec);

	return 0;
}