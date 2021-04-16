#include <stdio.h>

void swap(double *ap, double *bp);                       // �� �Ǽ��� �ٲٴ� �Լ�
void line_up(double *maxp, double *midp, double *minp);  // �Լ��� ����

int main(void)
{
	double max, mid, min;

	printf("�Ǽ��� �� �� �Է� : ");
	scanf("%lf%lf%lf", &max, &mid, &min);
	line_up(&max, &mid, &min);                 // �� ������ ���� �����ϴ� �Լ� ȣ��
	printf("���ĵ� �� ��� : %.1lf, %.1lf, %.1lf\n", max, mid, min);

	return 0;
}

void swap(double *ap, double *bp)
{
	double temp;

	temp = *ap;
	*ap = *bp;
	*bp = temp;
}

void line_up(double *maxp, double *midp, double *minp)
{
	if (*maxp < *midp) swap(maxp, midp);
	if (*maxp < *minp) swap(maxp, minp);
	if (*midp < *minp) swap(midp, minp);
}