/*****************************************************
 *
 * myproject.c
 *
 * Description : Hello World in C, ANSI-style
 *
 */

typedef int (*FN)(int, int);
typedef int ARR[2][3];
typedef int (*ID)[3];

int main(void)
{

	ID var;
	ARR var1 = {{1,2,3},{4,5,6}};
	int tmp;

	//var1 : int [2][3]
	//tmp = var1(1,2);
	//var1();  �̷��� �ϸ� ȣ���� ���� �ʴ´�. �̰� ȣ���� �� �ְ� �� �� �ִ�. ���? �̷���
	tmp = ((FN)var1)(1,2);
	//����ȯ �ϸ� �ȵȴ�. �޸� �뵵�� ���������� �ƴ� �뵵�� �� �� �ְ� �ϱ� ������. ���� �迭�ε� �Լ��� ����ȯ.
	//�Լ��� ����ȯ��Ű�ϱ� �迩���ϱ� ��ɾ� �����ϱ�.


//	tmp = ((int (*)(int, int))var1)(1, 2);
//	((void (*)(void))var1))();

}
