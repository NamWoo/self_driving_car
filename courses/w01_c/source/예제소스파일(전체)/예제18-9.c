#include <stdio.h>

int main(void)
{
	FILE *ifp, *ofp;            // ���� ������ ����
	char name[20];              // �̸�
	int kor, eng, mat;          // �� ���� ����
	int tot;                    // ����
	double avg;                 // ���
	int res;                    // fscanf �Լ��� ��ȯ�� ����

	ifp = fopen("a.txt", "r");  // �Է� ������ �б� �������� ����
	if (ifp == NULL)            // ���� ���� Ȯ��
	{
		printf("�Է� ������ ���� ���߽��ϴ�.\n");
		return 1;
	}

	ofp = fopen("b.txt", "w");  // ��� ������ ���� �������� ����
	if (ofp == NULL)            // ���� ���� Ȯ��
	{
		printf("��� ������ ���� ���߽��ϴ�.\n");
		return 1;
	}

	while (1)
	{
		res = fscanf(ifp, "%s %d %d %d", name, &kor, &eng, &mat); // ������ �Է�
		if (res == EOF)         // ������ �����͸� ��� ������ EOF ��ȯ
		{
			break;
		}
		tot = kor + eng + mat;                            // ���� ���
		avg = tot / 3.0;                                  // ��� ���
		fprintf(ofp, "%s %5d %7.1lf\n", name, tot, avg);  // �̸�, ����, ��� ���
	}
	fclose(ifp);                                          // �Է� ���� �ݱ�
	fclose(ofp);                                          // ��� ���� �ݱ�

	return 0;
}