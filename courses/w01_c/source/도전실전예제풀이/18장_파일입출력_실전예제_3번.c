#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char title[50];   // 책 제목
	double price;     // 매출단가
	int cnt;          // 입출고 부수
	double total;     // 총 매출액
} Books;

int dup_check(char *title, Books *ary, int cnt);

int main(void)
{
	FILE *ifp, *ofp;
	Books ary[10];
	char title[50];
	double price;
	int cnt, i, j, index, max;

	ifp = fopen("a.txt", "r");
	if(ifp == NULL)
	{
		printf("파일이 없습니다!\n");
		exit(1);
	}

	ofp = fopen("b.txt", "w");
	if (ifp == NULL)
	{
		printf("파일을 열 수 없습니다!\n");
		exit(1);
	}

	i = 0;
	fgets(title, sizeof(title), ifp);
	while(!feof(ifp))
	{
		title[strlen(title) - 1] = '\0';
		fscanf(ifp, "%lf%d", &price, &cnt);
		fgetc(ifp);
		index = dup_check(title, ary, i);
		if(index >= 0)
		{
			ary[index].total += (price * cnt);
		}
		else
		{
			strcpy(ary[i].title, title);
			ary[i].price = price;
			ary[i].cnt = cnt;
			ary[i].total = price * cnt;
			i++;
		}
		fgets(title, sizeof(title), ifp);
	}
	cnt = i;

	for(i = 0; i < cnt - 1; i++)
	{
		max = i;
		for(j = i + 1; j < cnt; j++)
		{
			if(ary[j].total > ary[max].total)
			{
				max = j;
			}
		}
		if(max != i)
		{
			Books temp = ary[i];
			ary[i] = ary[max];
			ary[max] = temp;
		}
	}

	for(i = 0; i < cnt; i++)
	{
		fprintf(ofp, "%d. %s - %.0lf원\n", i + 1, ary[i].title, ary[i].total * 10000.0);
	}

	fclose(ifp);
	fclose(ofp);

	
	return 0;
}

int dup_check(char *title, Books *ary, int cnt)
{
	int i;

	for(i = 0; i < cnt; i++)
	{
		if (strcmp(title, ary[i].title) == 0) return i;
	}
	return -1;
}