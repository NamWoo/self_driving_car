#include <stdio.h>

int main(void)
{
	int right = 19;
	int num, cnt = 0;

	while(1)
	{
		printf("���� �Է�(1���� 30����) : ");
		scanf("%d", &num);
		cnt++;
		if(num == right)
		{
			printf("�����Դϴ�!\n");
			break;
		}
		else if(num < right)
		{
			printf("%d���� Ů�ϴ�!\n", num);
		}
		else if(num > right)
		{
			printf("%d���� �۽��ϴ�!\n", num);
		}
	}
	printf("�õ��� Ƚ���� %dȸ �Դϴ�.\n", cnt);

	return 0;
}