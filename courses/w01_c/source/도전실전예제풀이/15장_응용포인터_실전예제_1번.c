#include <stdio.h>
#include <string.h>

int input_name(char (*name)[20]);
int dup_check(char (*name)[20], char *temp, int cnt);
void print_name(char (*name)[20], int cnt);

int main(void)
{
	char name[10][20];
	int cnt;

	cnt = input_name(name);
	print_name(name, cnt);

	return 0;
}

int input_name(char (*name)[20])
{
	char temp[20];
	int cnt = 0;

	while(1)
	{
		if(cnt == 10)
		{
			printf("@ 10���� ��� �Է��Ͽ����ϴ�!\n");
			break;
		}

		printf("> �̸� : ");
		scanf("%s", temp);
		if(strcmp(temp, "end") == 0) break;
		if(dup_check(name, temp, cnt))
		{
			printf("@ �̸��� �̹� ��ϵǾ����ϴ�!\n");
			continue;
		}
		strcpy(name[cnt], temp);
		cnt++;
	}
	
	return cnt;
}

int dup_check(char (*name)[20], char *temp, int cnt)
{
	int i;

	for(i = 0; i < cnt; i++)
	{
		if(strcmp(name[i], temp) == 0) return 1;
	}
	return 0;
}

void print_name(char (*name)[20], int cnt)
{
	int i;

	printf("@ �� %d���� �ԷµǾ����ϴ�.\n", cnt);
	for(i = 0; i < cnt; i++)
	{
		printf("%s\n", name[i]);
	}
}