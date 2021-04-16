#include <stdio.h>


int Max(int arr[], int size);
int Min(int arr[], int size);


int main(void)
{
	int ary[5];
	int i, size;
	printf("5�� �ɻ������� ���� �Է�: ");
	size = sizeof(ary)/sizeof(ary[0]);
	int sum =0;
	for(i=0; i<size;i++) scanf("%d", &ary[i]);
	
	int maxindex = Max(ary, size);
	int minindex = Min(ary, size);
	printf("��ȿ����: ");
	for(i=0; i<size;i++)
	{
		if((i!=maxindex)&&(i!=minindex))
		{
			printf("%2d", ary[i]);
			sum+=ary[i];
		}		
	}
	printf("\n���: %.1lf", (double)sum/3); 
	return 0;
}


int Max(int arr[], int size)
{
	int i;
	int result = arr[0];
	int index;
	for(i=0; i< size;i++)
	{
		if(arr[i]>=result)
		{
			result = arr[i];
			index = i;
		}
	}
	return index;
}

int Min(int arr[], int size)
{
	int i;
	int result = arr[0];
	int index;
	for(i=0; i< size;i++)
	{
		if(arr[i]<=result)
		{
			result = arr[i];
			index = i;
		}
	}
	return index;
}
