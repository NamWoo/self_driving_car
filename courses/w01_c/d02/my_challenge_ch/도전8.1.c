//20190514
//������������ ����1 

#include <stdio.h>

int main(void)
{
	int i, s, b, v=0;
	float c;
	int inp[5];

	printf("5�� �ɻ������� ���� �Է� : ");
	for (i = 0; i < 5; i++)         
	{
		scanf("%d", &inp[i]);
	}
//	int inp[5] = {9,7,4,8,5};
//	scanf("%d %d %d\n", &inp[i]);
	s = inp[0];	
	b = inp[0];
	for (i=1; i<5; i++)	
	{			
		if( s < (inp[i])) // �ִ� 
		{
			s = inp[i];
		}
		
		if( b > (inp[i])) // �ּ� 
		{
			b = inp[i];
		}	
	}


	// ��ȿ���� ���ϱ� 
	printf("��ȿ���� :\t");	
	for (i=0; i<5; i++)	
	{	
		if ((s != inp[i])&&(b != inp[i]))
		{			
			printf("%d\t",inp[i]);
			v = v + inp[i];
		}
	}
	c = v/3.0;
	printf("\n��� : %.1f", c);

	return 0;

}
