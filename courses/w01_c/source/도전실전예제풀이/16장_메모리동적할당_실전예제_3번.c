#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dup_check(char **sp, char *temp, int cnt);

int main(void)
{
	char temp[80];
	char *sp[100] = { 0 };
	int i, cnt;

	i = 0;
	while(1)
	{
		printf("> �ܾ� �Է� : ");
		scanf("%s", temp);
		if ((strcmp(temp, "end") == 0) || (i == 100)) break;
		if((i != 0) && (sp[i - 1][strlen(sp[i - 1]) - 1] != temp[0]))
		{
			printf("> �ܾ� �ձⰡ �Ұ����մϴ�!\n");
			continue;
		}
		if (dup_check(sp, temp, i))
		{
			printf("> �̹� �����ϴ� �ܾ��Դϴ�!\n");
			continue;
		}
		sp[i] = (char *)malloc(strlen(temp) + 1);
		if(sp[i] == NULL)
		{
			printf("> �޸� ����...\n");
			break;
		}
		strcpy(sp[i], temp);
		i++;
	}
	cnt = i;

	for(i = 0; i < cnt; i++)
	{
		printf("%s ", sp[i]);
	}

	for(i = 0; i < cnt; i++)
	{
		free(sp[i]);
	}

	return 0;
}

int dup_check(char **sp, char *temp, int cnt)
{
	int i;

	for(i = 0; i < cnt; i++)
	{
		if(strcmp(temp, sp[i]) == 0)
		{
			return 1;
		}
	}
	return 0;
}