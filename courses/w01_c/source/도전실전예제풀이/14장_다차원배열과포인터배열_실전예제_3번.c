#include <stdio.h>
#include <string.h>

int main(void)
{
	char branch[4][10] = {"������", "������", "����", "�븲��"};
	int selling[4][7] = { 
		{70, 45, 100, 92, 150, 81},
		{88, 92, 77, 30, 52, 55},
		{50, 90, 88, 75, 77, 49},
		{120, 92, 80, 150, 130, 105}
	};
	char *bp[4];
	int *sp[4];
	int i, j, tot;
	char *btp;
	int *stp;

	for(i = 0; i < 4; i++)
	{
		tot = 0;
		for(j = 0; j < 6; j++)
		{
			tot += selling[i][j];
		}
		selling[i][6] = (int)(tot / 6.0 + 0.5);
	}
	
	for(i = 0; i < 4; i++)
	{
		sp[i] = selling[i];
	}

	for(i = 0; i < 4; i++)
	{
		bp[i] = branch[i];
	}

	for(i = 0; i < 3; i++)
	{
		for(j = i + 1; j < 4; j++)
		{
			if(sp[i][6] < sp[j][6])
			{
				stp = sp[i];
				sp[i] = sp[j];
				sp[j] = stp;

				btp = bp[i];
				bp[i] = bp[j];
				bp[j] = btp;
			}
		}
	}

	printf("> ������ ���...\n");
	for(i = 0; i < 4; i++)
	{
		printf("%s", bp[i]);
		for(j = 0; j < 7; j++)
		{
			printf("%5d", sp[i][j]);
		}
		printf("\n");
	}

	printf("\n> ������ ���...\n");
	for(i = 0; i < 4; i++)
	{
		printf("%s", branch[i]);
		for(j = 0; j < 7; j++)
		{
			printf("%5d", selling[i][j]);
		}
		printf("\n");
	}

	return 0;
}
