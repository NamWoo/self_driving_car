#include <stdio.h>

int main(void)
{
	int mileage, speed, rest;
	int hour, min;
	double sec;

	printf("�Ÿ��� �ӷ� �Է� : ");
	scanf("%d%d", &mileage, &speed);

	hour = mileage / speed;
	rest = mileage % speed;
	min = (rest * 60) / speed;
	rest = (rest * 60) % speed;
	sec = (rest * 60.0) / speed;
	
	printf("�ҿ� �ð��� %d�ð� %d�� %.3lf���Դϴ�.\n", hour, min, sec);

	return 0;
}