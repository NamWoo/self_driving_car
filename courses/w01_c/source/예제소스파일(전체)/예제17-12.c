#include <stdio.h>

enum season { SPRING, SUMMER, FALL, WINTER };  // ������ ����

int main(void)
{
	enum season ss;                            // ������ ���� ����
	char *pc;                                  // ���ڿ��� ������ ������

	ss = SPRING;                               // ���� ����� �� ����
	switch (ss)                                // ���� ��� �Ǵ�
	{
	case SPRING:                               // ���̸�
		pc = "inline"; break;                  // �ζ��� ���ڿ� ����
	case SUMMER:                               // �����̸�
		pc = "swimming"; break;                // ���� ���ڿ� ����
	case FALL:                                 // �����̸�
		pc = "trip"; break;                    // ���� ���ڿ� ����
	case WINTER:                               // �ܿ��̸�
		pc = "skiing"; break;                  // ��Ű ���ڿ� ����
	}
	printf("���� ���� Ȱ�� => %s\n", pc);      // ���õ� ���ڿ� ���

	return 0;
}