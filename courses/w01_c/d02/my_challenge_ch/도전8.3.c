//20190514
//������������ ����3 �ζ����α׷�

#include <stdio.h>

int main(void)
{
	int ary[6];
	int inp, flag, i, c = 0;

	c = 0;
	while(c < 6)
	{
		printf("�ζǹ�ȣ �Է� : ");
		scanf("%d", &inp);
		flag = 0;
		for(i=0; i<c; i++)
		{
			if(inp == ary[i])
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			ary[c] = inp;
			c++;
		}
		else
		{
			printf("���� ��ȣ�� �ֽ��ϴ�!\n");
		}
	}

	printf("�Էµ� �ζǹ�ȣ : ");
	for(i=0; i<6; i++)
	{
		printf("%3d", ary[i]);
	}

	return 0;
}
