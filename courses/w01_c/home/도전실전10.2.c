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
		printf("로또번호가 %d 일때\n",lotto_nums[i]);
		for(j=0; j<6; j++)
		{	
			printf("%d ",my_nums[j]);
			if(lotto_nums[i] == my_nums[j])
			{	
				cnt++;
				printf("\n맞은 번호수는%d %d\n",my_nums[j],cnt);
			
			} 
		}
		printf("\n");
	}
	printf("일치하는 번호의 개수 : %d",cnt);
	
}
