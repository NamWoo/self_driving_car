#include <stdio.h>
 
int main(void)
{
	double bmi;
	float weight, height;
	printf("�����Կ� Ű �Է� : ");
	scanf("%f %f", &weight, &height);
	printf("�����Դ� %.1fcm, Ű�� %.1fcm\n", weight, height);
	height = height * 0.01;
	bmi = weight / (height) * (height);
	printf("BMI�� %.1lf\n", bmi);

	if ((bmi>20) && (bmi<25))
	{
		printf("ǥ���Դϴ�.");
	}
	else
		printf("ü�߰����� �ʿ��մϴ�.");
	return 0;
}
