#include <stdio.h>
#include <string.h>

void init_intro(char (*intro)[80], char **intp);
int input_intro(char (*intro)[80]);
void sort_intro(char **intp, int cnt);
void print_intro(int mode, void *vp, int cnt);

int main(void)
{
	char intro[10][80];          // �λ縻�� �Է��� �迭
	char *intp[10];              // �� �λ縻�� ������ ������ �迭
	int cnt;                     // �Էµ� �λ縻�� ����

	init_intro(intro, intp);     // intro�� intp����
	cnt = input_intro(intro);    // �λ縻 �Է�, �Է��� �λ縻 �� ��ȯ
	sort_intro(intp, cnt);       // �λ縻 ������ ����
	print_intro(1, intp, cnt);   // ���ĵ� �λ縻 ���
	print_intro(0, intro, cnt);  // ���� �Էµ� �λ縻 ���

	return 0;
}

void init_intro(char (*intro)[80], char **intp)
{
	int i;

	for(i = 0; i < 10; i++)
	{
		intp[i] = intro[i];
	}
}

int input_intro(char (*intro)[80])
{
	char temp[80];
	int cnt = 0;

	while(1)
	{
		printf("> �λ縻 �Է� : ");
		gets(temp);
		if(strcmp(temp, "end") == 0) break;
		strcpy(intro[cnt], temp);
		cnt++;
	}

	return cnt;
}

void sort_intro(char **intp, int cnt)
{
	int i, j;
	char *tp;

	for(i = 0; i < cnt -1; i++)
	{
		for(j = i + 1; j < cnt; j++)
		{
			if(strcmp(intp[i], intp[j]) > 0)
			{
				tp = intp[i];
				intp[i] = intp[j];
				intp[j] = tp;
			}
		}
	}
}

void print_intro(int mode, void *vp, int cnt)
{
	int i;

	if(mode == 0)
	{
		char (*intro)[80] = vp;
		printf("\n@ �Է¼����� ���...\n");
		for(i = 0; i < cnt; i++)
		{
			printf("%s\n", intro[i]);
		}
	}
	else if(mode == 1)
	{
		char **intp = vp;
		printf("\n@ ���������� ���...\n");
		for(i = 0; i < cnt; i++)
		{
			printf("%s\n", intp[i]);
		}
	}
}