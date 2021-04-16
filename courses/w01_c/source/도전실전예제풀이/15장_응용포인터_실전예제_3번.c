#include <stdio.h>
#include <string.h>

void init_intro(char (*intro)[80], char **intp);
int input_intro(char (*intro)[80]);
void sort_intro(char **intp, int cnt);
void print_intro(int mode, void *vp, int cnt);

int main(void)
{
	char intro[10][80];          // 인사말을 입력할 배열
	char *intp[10];              // 각 인사말을 연결할 포인터 배열
	int cnt;                     // 입력된 인사말의 개수

	init_intro(intro, intp);     // intro와 intp연결
	cnt = input_intro(intro);    // 인사말 입력, 입력한 인사말 수 반환
	sort_intro(intp, cnt);       // 인사말 사전순 정렬
	print_intro(1, intp, cnt);   // 정렬된 인사말 출력
	print_intro(0, intro, cnt);  // 최초 입력된 인사말 출력

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
		printf("> 인사말 입력 : ");
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
		printf("\n@ 입력순으로 출력...\n");
		for(i = 0; i < cnt; i++)
		{
			printf("%s\n", intro[i]);
		}
	}
	else if(mode == 1)
	{
		char **intp = vp;
		printf("\n@ 사전순으로 출력...\n");
		for(i = 0; i < cnt; i++)
		{
			printf("%s\n", intp[i]);
		}
	}
}