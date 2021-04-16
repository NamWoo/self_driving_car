#include<stdio.h>

int main(void)
{
	int arr[6];
	int i;
	int size = sizeof(arr)/sizeof(arr[0]);
	for(i=0; i<size;i++)
	{
		int tmp, j;
		printf("로또번호 입력: ");
		scanf("%d", &tmp);
		arr[i]=tmp; 
		for(j=0;j<i;j++)
		{
			if(tmp==arr[j])
			{
				printf("같은 번호가 있습니다!\n");
				i-=1;
				break;
			}
		}
	}
	printf("입력된 로또번호 : ");
	for(i=0; i<size;i++)
	{
		printf(" %d", arr[i]);
	} 
}
