#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_name(void);

int main(void)
{
	char **name = NULL;
	int *donation = NULL;
	char *tp;
	int i = 0, cnt, size = 0;
	int tot = 0;

	while(1)
	{
		printf("> 이름 : ");
		tp = get_name();
		if (strcmp(tp, "end") == 0) break;
		if(i == size)
		{
			size += 5;
			name = (char **)realloc(name, size * sizeof(char *));
			donation = (int *)realloc(donation, size * sizeof(int));
		}
		name[i] = tp;
		printf("> 기부금 : ");
		scanf("%d", &donation[i]);
		i++;
	}
	cnt = i;
	for(i = 0; i < cnt; i++)
	{
		printf("%d. %s %d\n", i + 1, name[i], donation[i]);
		tot += donation[i];
	}
	printf("@ 평균 기부액 : %d\n", tot / cnt);
	for(i = 0; i < cnt; i++)
	{
		free(name[i]);
	}
	free(name);
	free(donation);

	return 0;
}

char *get_name(void)
{
	char temp[800];
	char *tp;

	fflush(stdin);
	fgets(temp, sizeof(temp), stdin);
	temp[strlen(temp) - 1] = '\0';
	tp = (char *)malloc(strlen(temp) + 1);
	strcpy(tp, temp);
	return tp;
}

