#include <stdio.h>

char *my_strcpy(char *pd, char *ps);        // �Լ� ����

int main(void)
{
	char str[80] = "strawberry";

	printf("�ٲٱ� �� ���ڿ� : %s\n", str);
	my_strcpy(str, "apple");                // ���ڿ� "apple" ����
	printf("�ٲ� �� ���ڿ� : %s\n", str);
	printf("�ٸ� ���ڿ� ���� : %s\n", my_strcpy(str, "kiwi"));  // ��ȯ������ ���

	return 0;
}

char *my_strcpy(char *pd, char *ps)         // ������� ��(pd)�� ������ ��(ps)�� ������
{
	char *po = pd;                          // pd���� ���߿� ��ȯ�ϱ� ���� ����

	while (*ps != '\0')                     // ps�� ����Ű�� ���ڰ� �ι��ڰ� �ƴ� ����
	{
		*pd = *ps;                          // ps�� ����Ű�� ���ڸ� pd�� ����Ű�� ��ġ�� ����
		pd++;                               // ������� ���� ��ġ�� ������ ����
		ps++;                               // ������ ���� ������ ��ġ�� ������ ����
	}
	*pd = '\0';                             // ���簡 ��� ���� �� ������� ���� �ι��ڷ� ������

	return po;                              // ���簡 ���� ���� ������ ���� �ּ� ��ȯ
}