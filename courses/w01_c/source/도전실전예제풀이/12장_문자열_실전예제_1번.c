#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[800] = {0};   // ���ڿ��� �̾���� �迭, �� ���ڷ� �ʱ�ȭ
	char temp[20];

	while(1)
	{
		printf("�ܾ� �Է� : ");
		scanf("%s", temp);
		if(strcmp(temp, "end") == 0) break;

		strcat(str, temp);
		printf("��������� ���ڿ� : %s\n", str);
		strcat(str, " ");
	}

	return 0;
}
