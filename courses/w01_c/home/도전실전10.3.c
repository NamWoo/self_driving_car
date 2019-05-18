#include <stdio.h>

void input_nums(int *lotto_nums);
void print_nums(int *lotto_nums);

void main(void)
{
	int lotto_nums[6];
	
	input_nums(lotto_nums);
	print_nums(lotto_nums);
}

void input_nums(int *lotto_nums)
{
	int k, cnt=0;
	int *temp, flag; 
	while (1)
	{
		flag=0;
		printf("번호 입력 : ");
		scanf("%d", &temp);
		
		for(k=0; k<6; k++)
		{		
			if (lotto_nums[k]==temp)
			{
				printf("같은 번호가 있습니다!\n");
				flag = 1;
				break;
			}
		}
		
		if (flag==1) continue;
		else
		{
			lotto_nums[cnt] = temp;
			cnt++;
		}
		
		if (cnt == 6) break;
	}
}

void print_nums(int *lotto_nums)
{
	int i;
	printf("로또 번호 : ");
	for (i=0; i<6; i++)
	{
		printf("%d ", lotto_nums[i]);
	}
}
