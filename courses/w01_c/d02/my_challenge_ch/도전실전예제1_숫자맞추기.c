#include <stdio.h>

int main(void)
{
	int ans = 15;
	int num, c = 0;

	while(1)
	{
		printf("���� �Է� (1���� 30����) : ");
		scanf("%d", &num);
		c++;
		if(num == ans)
		{
			printf("�����Դϴ�!\n");
			break;
		}
		else if(num < ans)
		{
			printf("%d���� Ů�ϴ�!\n", num);
		}
		else if(num > ans)
		{
			printf("%d���� �۽��ϴ�!\n", num);
		}
	}
	printf("�õ��� Ƚ���� %dȸ �Դϴ�.\n", c);

	return 0;
}
