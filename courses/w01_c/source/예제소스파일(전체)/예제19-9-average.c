// ���� �̸��� '����19-9-average.c'���� average.c�� �ٲ� ����ϼ���.

extern int cnt;                // main.c�� ���� ���� cnt ����
extern int tot;                // input.c�� ���� ���� tot ����

double average(void)
{
	return tot / (double)cnt;  // �Է°��� ��� ��ȯ
}
