#include <stdio.h>
#include <string.h>

int main(void)
{
	char word[10][21];  // �ִ� 10���� �ܾ�, �ܾ��� ���̴� �ִ� 20��
	char temp[21];      // �ܾ� �Է� �� ����� �ӽ� �迭
	int cnt;            // �Էµ� �ܾ��� ��
	int i, j, dup, find;

	i = 0;
	while(1)
	{
		printf("> �ܾ� �Է� : ");
		scanf("%s", temp);
		if(strcmp(temp, "end") == 0) break;      // end�� �ԷµǸ� ����
		
		// �Էµ� �ܾ �ִ��� �ߺ� ���� �˻�
		dup = 0;                                 // �Էµ� �ܾ ���ٰ� ����
		for(j = 0; j < i; j++)                   // ���� �Էµ� �ܾ������ �˻�
		{
			if(strcmp(temp, word[i]) == 0)       // ���� �ܾ ������
			{
				dup = 1;                         // dup�� ���¸� �ٲٰ�
				break;                           // �˻� ����
			}
		}
		if(dup == 1)                             // �˻� ��� ���� �ܾ ������
		{
			printf("# �̹� �ԷµǾ����ϴ�!\n");  // �޽��� ����ϰ�
			continue;                            // �迭�� �ִ� �۾��� �ǳ� ��
		}
		// �ߺ� �˻� ��

		strcpy(word[i], temp);                   // �Էµ� �ܾ �迭�� ����
		i++;                                     // �迭�� ���� ��ġ�� �̵�
	}
	cnt = i;                                     // �Էµ� �ܾ��� �� ����
	printf("# �� %d���� �ܾ �ԷµǾ����ϴ�!\n\n", cnt);

	while(1)
	{
		printf("> �˻� �ܾ� (����� end�Է�) : ");
		scanf("%s", temp);                       // �˻��� �ܾ� �Է�
		if(strcmp(temp, "end") == 0) break;      // end�� ������ ����

		find = 0;                                // �ϴ� ���� �ܾ ���ٰ� ����
		for(i = 0; i < cnt; i++)                 // �Է��� �ܾ� �� ��ŭ ã�´�
		{
			if(strcmp(temp, word[i]) == 0)       // ���� �ܾ ������
			{
				find = 1;                        // find�� ���¸� ����
				break;                           // ã�� ���� ����
			}
		}

		if(find == 1)                            // find�� ���°� 1�̸� ã�� ����
		{
			printf("# %d��° ���� �ܾ �ֽ��ϴ�!\n\n", i + 1);
		}
		else
		{
			printf("# ���� �ܾ��Դϴ�.\n\n");
		}
	}

	return 0;
}
