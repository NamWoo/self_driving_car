#include <stdio.h>
 
int main(void)
{
	double bmi;
	float weight, height;
	printf("몸무게와 키 입력 : ");
	scanf("%f %f", &weight, &height);
	printf("몸무게는 %.1fcm, 키는 %.1fcm\n", weight, height);
	height = height * 0.01;
	bmi = weight / (height) * (height);
	printf("BMI는 %.1lf\n", bmi);

	if ((bmi>20) && (bmi<25))
	{
		printf("표준입니다.");
	}
	else
		printf("체중관리가 필요합니다.");
	return 0;
}
