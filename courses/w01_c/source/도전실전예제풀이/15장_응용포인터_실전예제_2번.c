#include <stdio.h>
#include <string.h>

void swap(char *type, void *ap, void *bp);

int main(void)
{
	int age1, age2;
	double height1, height2;

	printf("> ù ��° ����� ���̿� Ű �Է� : ");
	scanf("%d%lf", &age1, &height1);

	printf("> �� ��° ����� ���̿� Ű �Է� : ");
	scanf("%d%lf", &age2, &height2);

	swap("int", &age1, &age2);
	swap("double", &height1, &height2);

	printf("> ù ��° ����� ���̿� Ű : %d, %.1lf\n", age1, height1);
	printf("> �� ��° ����� ���̿� Ű : %d, %.1lf\n", age2, height2);

	return 0;
}

void swap(char *type, void *ap, void *bp)
{
	int temp;
	double dtemp;

	if(strcmp(type, "int") == 0)
	{
		temp = *(int *)ap;
		*(int *)ap = *(int *)bp;
		*(int *)bp = temp;
	}
	if(strcmp(type, "double") == 0)
	{
		dtemp = *(double *)ap;
		*(double *)ap = *(double *)bp;
		*(double *)bp = dtemp;
	}
}
