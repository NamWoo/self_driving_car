#include <stdio.h>

void input_ary(int *pa,int cnt);
void output_ary(int *pa,int cnt);

void main(void)
{

	//������ ���� ���� 
	int pa; 
	scanf("%d", &pa);			//�׳� pa�� ���� 
	printf("pa : %d\n",pa);
	printf("&pa : %d\n",&pa);	//*pa ����  
	//��, �ּ�; 
	//������ ����pa�� �޸� �ּ� 1000�� ��
	//�޸� �ּҿ� ���� �Է� 
	
	//������ �����ͺ��� ���� 
	int *pb;
	scanf("%d", &pb);	
	printf("pb : %d\n", pb);	
	printf("&pb : %d\n",&pb);	//*pb ���� 
	//��, �ּ�; 
	//������ �����ͺ���pb�� �ּҸ� ����Ű�� ���� 
	//pb�� �ּҿ� �Է� �� pb, &pb �� ��� 
		  	
	//������ �����͹迭 10�� ���� 
	int *pc[10];
	scanf("%d", &pc);	
	printf("pc : %d\n",pc);
	printf("*pc : %d\n",*pc);
	printf("&pc : %d\n",&pc);
	//scanf �� pc, &pc �϶� �ּ�/��/�ּ�
	//scanf �� *pc �϶� �ּ�/???/�ּ�
	
}





//	input_ary(*ary)
void input_ary(int *pa,int cnt)
{
//	printf("�Է�:");
	
	
}
//
//void output_ary(int *pa,int cnt)
//{
//	
//}
