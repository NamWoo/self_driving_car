#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int input_intro(char (*intro)[80]);

int main(void)
{
	char temp[80];     // �ӽ� char �迭
	char *str[3];      // ���� �Ҵ� ������ ������ ������ �迭
	int i, j, cnt;             // �ݺ� ���� ����

	while(1)
	{				
		if(cnt == 100)
		{
			printf("�ܾ��Է� 100�� ����\n");
			break;
		}
		printf("�ܾ� �Է� : ");
//		gets(intro[cnt]);
		gets(temp);  

		if (strcmp(temp, "end")=0) break;
//		if(strcmp(intro[cnt], "end")==0) break;
		strcpy(intro[cnt], temp);
		
		str[cnt] = (char *)malloc(strlen(temp) + 1);  // ���ڿ� ���� ���� �Ҵ�
		strcpy(str[cnt], temp);                       // ���� �Ҵ� ������ ���ڿ� ����
		cnt++;
	}


	for (i = 0; i < 3; i++)
	{
		
		if (str[j] == str[i])
		
	}




	for (i = 0; i < 3; i++)
	{
		printf("%s ", str[i]);                     // �Էµ� ���ڿ� ���
	}

	for (i = 0; i < 3; i++)
	{
		free(str[i]);                               // ���� �Ҵ� ���� ��ȯ
	}

	return 0;
}
