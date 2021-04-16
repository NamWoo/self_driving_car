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
			printf("@ 10명을 모두 입력하였습니다!\n");
			break;
		}

		printf("> 이름 : ");
		scanf("%s", temp);
		if(strcmp(temp, "end") == 0) break;
		if(dup_check(name, temp, cnt))
		{
			printf("@ 이름이 이미 등록되었습니다!\n");
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

	printf("@ 총 %d명이 입력되었습니다.\n", cnt);
	for(i = 0; i < cnt; i++)
	{
		printf("%s\n", name[i]);
	}
}