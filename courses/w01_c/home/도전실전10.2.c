#include <stdio.h>

int check_same(int *lotto_nums, int *my_nums);

void main(void)
{
	int lotto_num[6] = {4,10,25,30,41,45};
	int my_nums[6] = {1,4,7,22,41,43};	
	
	check_same(lotto_num, my_nums);
}


int check_same(int *lotto_nums, int *my_nums)
{
	int i, j, cnt=0;
	for(i=0; i<6; i++)
	{
		printf("�ζǹ�ȣ�� %d �϶�\n",lotto_nums[i]);
		for(j=0; j<6; j++)
		{	
			printf("%d ",my_nums[j]);
			if(lotto_nums[i] == my_nums[j])
			{	
				cnt++;
				printf("\n���� ��ȣ����%d %d\n",my_nums[j],cnt);
			
			} 
		}
		printf("\n");
	}
	printf("��ġ�ϴ� ��ȣ�� ���� : %d",cnt);
	
}
