#include <stdio.h>

int main(void)
{
	double weight, height, bmi;

	printf("������(kg)�� Ű(cm) �Է� : ");
	scanf("%lf%lf", &weight, &height);
	height=height/100.0;
	bmi=weight/(height*height);
	(bmi>=20.0&&bmi<25.0)?printf("ǥ���Դϴ�.\n"):printf("ü�߰����� �ʿ��մϴ�.\n");

	return 0; 
}

