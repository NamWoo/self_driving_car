#include <stdio.h>
 
#define PI 3.14159                                 // ����� ��ũ�θ����� ����
#define LIMIT 100.0                                // ����� ��ũ�θ����� ����
#define MSG "passed!"                              // ���ڿ��� ��ũ�θ����� ����
#define ERR_PRN printf("������ ������ϴ�!\n")   // ��¹��� ��ũ�θ����� ����

int main(void)
{
	double radius, area;                           // �������� ���� ����

	printf("�������� �Է��ϼ��� : ");
	scanf("%lf", &radius);                         // ������ �Է�
	area = PI * radius * radius;                   // ���� ���
	if (area > LIMIT) ERR_PRN;                     // ������ 100�� �ʰ��ϸ� ���� �޽��� ���
	else printf("���� ���� : %.2lf (%s)\n", area, MSG); // ������ �޽��� ���

	return 0;
}