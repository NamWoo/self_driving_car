#include<stdio.h>

int main(void)
{
	int arr[6];
	int i;
	int size = sizeof(arr)/sizeof(arr[0]);
	for(i=0; i<size;i++)
	{
		int tmp, j;
		printf("�ζǹ�ȣ �Է�: ");
		scanf("%d", &tmp);
		arr[i]=tmp; 
		for(j=0;j<i;j++)
		{
			if(tmp==arr[j])
			{
				printf("���� ��ȣ�� �ֽ��ϴ�!\n");
				i-=1;
				break;
			}
		}
	}
	printf("�Էµ� �ζǹ�ȣ : ");
	for(i=0; i<size;i++)
	{
		printf(" %d", arr[i]);
	} 
}
