#include <stdio.h>

int main()
{
	int arr[5];
	int i,max=0,min=10,sum=0,count=0;
	double avg;
	
	printf("5�� �ɻ������� ���� �Է� : ");
	scanf("%d%d%d%d%d",&arr[0],&arr[1],&arr[2],&arr[3],&arr[4]);
	
	printf("��ȿ ���� : ");
	
	for(i=0;i<5;i++)
	{
		if(arr[i]>max)
			max = arr[i];
		
		if(arr[i]<min)
			min = arr[i];
	}
	
	for(i=0;i<5;i++)
	{
		if(arr[i] != max && arr[i] != min)
		{
			printf("  %d",arr[i]);
			sum += arr[i];
			count++;
		}
	}
	printf("\n");
	avg = (double)sum / count;
	
	printf("��� : %.1lf",avg);
	return 0;
}
