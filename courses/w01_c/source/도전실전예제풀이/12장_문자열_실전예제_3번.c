#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[800];        // ������ �Է��� �迭
	char ss[80];          // �˻��� ���ڿ��� �Է��� �迭
	int cnt = 0, i;       // cnt ã�� ���ڿ��� ���� ������ ����, i�� �ݺ� �����
	int str_len, ss_len;  // ������ ���̿� ã�� ���ڿ��� ���̸� ������ ����

	printf("���� �Է� : ");
	fgets(str, sizeof(str), stdin);
	str[strlen(str) - 1] = '\0';                   // ���ٹ��� ����
	str_len = strlen(str);                         // �Էµ� ������ ���� ���

	while(1)
	{
		cnt = 0;                                   // ���� ���� �ʱ�ȭ

		printf("�˻��� ���ڿ� �Է� (����� end) : ");
		fgets(ss, sizeof(ss), stdin);
		ss[strlen(ss) - 1] = '\0';	
		if(strcmp(ss, "end") == 0) break;          // ã�� ���ڿ��� end�̸� �ݺ� ����
		ss_len = strlen(ss);                       // ã�� ���ڿ��� ���� ���

		for(i = 0; i < str_len; i++)               // ù ���ں��� ��ġ�ϴ� ���ڿ� �˻�
		{
			if((str_len - i) < ss_len) break;      // ���� ���̰� �˻��� ���ڿ����� ������ �˻� ����
			if(strncmp(ss, str + i, ss_len) == 0)  // ã�� ���ڿ��� ���� ��ŭ ��
			{
				cnt++;                             // ã�� ���ڿ� �� ����
				i += (ss_len - 1);                 // ã�� ���ڿ� ���ĺ��� �ٽ� �˻�
			}
		}

		printf("�˻� ��� : %d��\n", cnt);
	}

	return 0;
}
