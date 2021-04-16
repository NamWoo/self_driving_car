#include <stdio.h>
#include <string.h>
#include <stdlib.h>                   // malloc, atoi �Լ� ����� ���� ��� ����

void print_str(char **);              // ���ڿ� ��� �Լ� ����

int main(int argc, char **argv)
{
	char temp[80];                    // ���ڿ� �Է��� ���� �ӽ� char �迭
	char **str;                       // ������ �迭�� ����� ���� �Ҵ� ���� ����
	int max;                          // �ִ� �Է� ���ڿ� ���� ����
	int i;

	max = atoi(argv[1]);              // �� ��° ����� �μ��� ������ ��ȯ
	str = (char **)malloc((max + 1) * sizeof(char *));  // ������ �迭�� ���� �Ҵ�
	i = 0;
	while (1)
	{
		printf("���ڿ��� �Է��ϼ��� : ");
		gets(temp);                                     // ���ڿ� �Է�
		if (temp[0] == '\0') break;                     // ���͸� �Է��ϸ� �ݺ� ����

		str[i] = (char *)malloc(strlen(temp) + 1);      // ���ڿ� ���� ���� ���� �Ҵ�
		strcpy(str[i], temp);                           // ���ڿ� ����
		i++;
		if (i == max)                                   // �Էµ� ���ڿ��� ���� �˻�
		{
			printf("���ڿ� �Է��� �ִ��� ��� ä�����ϴ�.\n");
			break;
		}
	}
	str[i] = 0;                       // �Է��� ���� �� �������ͷ� ����
	print_str(str);                   // �Էµ� ���ڿ� ���

	i = 0;
	while (str[i] != 0)
	{
		free(str[i]);                 // ���ڿ��� ������ ���� �Ҵ� ���� ��ȯ
		i++;
	}
	free(str);                        // ������ �迭�� ���� ���� �Ҵ��� ���� ��ȯ

	return 0;
}

void print_str(char **ps)             // 2�� ������ ps�� ������ �迭ó�� ���
{
	while (*ps != 0)                  // ps �迭 ����� ���� �������Ͱ� �ƴ� ����
	{
		printf("%s\n", *ps);          // ps �迭 ��Ұ� �����ϰ� �ִ� ���ڿ� ���
		ps++;                         // ���� ��ҷ� �̵�
	}
}