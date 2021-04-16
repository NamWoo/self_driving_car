#include <stdio.h>
#include <stdlib.h>                              // malloc, free �Լ� ����� ���� ��� ����

int main(void)
{
	int *pi;                                     // ���� �Ҵ� ������ ������ ������ ����
	double *pd;

	pi = (int *)malloc(sizeof(int));             // �޸� ���� �Ҵ� �� ������ ����
	if (pi == NULL)                              // ���� �Ҵ翡 �����ϸ� NULL ������ ��ȯ
	{
		printf("#���� �޸𸮰� �����մϴ�.\n");  // ���� ��Ȳ �޽��� ���
		exit(1);                                 // ���α׷� ����
	}
	pd = (double *)malloc(sizeof(double));

	*pi = 10;                                    // �����ͷ� ���� �Ҵ� ���� ���
	*pd = 3.4;

	printf("���������� ��� : %d\n", *pi);       // ���� �Ҵ� ������ ����� �� ���
	printf("�Ǽ������� ��� : %lf\n", *pd);

	free(pi);                                    // ���� �Ҵ� ���� ��ȯ
	free(pd);

	return 0;
}