#include <stdio.h>

int main(void)
{
	char *pary[5];                // ������ �迭 ����
	int i;                        // �ݺ� ���� ����

	pary[0] = "dog";              // �迭 ��ҿ� ���ڿ� ����
	pary[1] = "elephant";
	pary[2] = "horse";
	pary[3] = "tiger";
	pary[4] = "lion";

	for (i = 0; i < 5; i++)       // i�� 0���� 4���� 5�� �ݺ�
	{
		printf("%s\n", pary[i]);  // �迭 ��Ҹ� ����Ͽ� ��� ���ڿ� ���
	}

	return 0;
}