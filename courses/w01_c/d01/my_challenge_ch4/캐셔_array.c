#include <stdio.h>
 
int main(void)
{
	int item1, item2, item3, b, i, c;	
	int ringring[6] = {5000, 1000, 500, 100, 50, 10};
//	char ringname[] = {'��õ��', 'õ��', '�����', '���', '���ʿ�', '�ʿ�', '\0'};
	
	printf("�� ���� ���ǰ��� �Է��ϼ��� :");
	scanf("%d %d %d", &item1, &item2, &item3);
	b = 10000-(item1 + item2 + item3);
	printf("�Ž������� %d�� �Դϴ�.\n", b);

	for (i=0 ; i<6 ; i++)
	{
		c = ringring[i]; 
		printf("%d��¥�� %d��\n",c, b/c);			
		b = b%c;
	}

	return 0;	
}




