#include <stdio.h>

int main(void)
{
	int ch;                           // int�� ����

	printf("���� a�� �ƽ�Ű �ڵ尪 : %d\n", 'a');
	printf("�ƽ�Ű �ڵ尪�� 97�� ���� : %c\n", 97);
	printf("���� ����� ũ�� : %d����Ʈ\n", sizeof('a'));

	ch = 'a';                         // ���ڸ� int�� ������ ����
	ch++;                             // �ƽ�Ű �ڵ尪 1 ����
	printf("���� %c�� �ƽ�Ű �ڵ尪 : %d\n", ch, ch);

	return 0;
}