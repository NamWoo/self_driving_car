#include <stdio.h>

int main(void)
{
	int a = 10;                           // int�� ����
	double b = 3.5;                       // double�� ����
	void *vp;                             // void ������

	vp = &a;                              // int�� ������ �ּ� ����
	printf("a : %d\n", *(int *)vp);
	vp = &b;                              // double�� ������ �ּ� ����
	printf("b : %.1lf\n", *(double *)vp);

	return 0;
}