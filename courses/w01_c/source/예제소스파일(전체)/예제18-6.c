#include <stdio.h>

int main(void)
{
	FILE *fp;
	int ary[10] = {13, 10, 13, 13, 10, 26, 13, 10, 13, 10};
	int i, res;

	fp = fopen("a.txt", "wb");   // ���̳ʸ� ���Ϸ� ����
	for (i = 0; i < 10; i++)
	{
		fputc(ary[i], fp);       // �迭 ����� �� ���� �ش��ϴ� �ƽ�Ű���� ���
	}
	fclose(fp);                  // ���� ����

	fp = fopen("a.txt", "rt");   // ���� ������ �ؽ�Ʈ ���Ϸ� ����
	while (1)
	{
		res = fgetc(fp);         // ���Ͽ��� �� ���� �Է�
		if (res == EOF) break;
		printf("%4d", res);      // �Է��� ������ �ƽ�Ű �ڵ尪 ���
	}
	fclose(fp);                  // ���� ����

	return 0;
}