// 8�� �迭 ���� ���� ���� 2��

#include <stdio.h>

int main(void)
{
	char str[80];
	int cnt = 0;
	int i;

	printf("���� �Է� : ");
	gets(str);

	for(i=0; str[i] != '\0'; i++)
	{
		if((str[i] >= 'A') && (str[i] <= 'Z'))
		{
			str[i] += ('a'-'A');
			cnt++;
		}
	}

	printf("�ٲ� ���� : ");
	puts(str);
	printf("�ٲ� ���� �� : %d\n", cnt);

	return 0;
}