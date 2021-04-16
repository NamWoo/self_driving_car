/*
 * idcheck.c
 */

#include "wshop1.h"

#ifdef IDCHECK

int strtoNum(char *str, int s, int e);
int leap_year(int year);
int formatErrorCheck(char *p_num);
int isY(void);
void idCheck(void);

int strtoNum(char *str, int s, int e)
{
	int num = 0;
	int multi = 1;
	int idx;
	int diff = '1' - 1;

	for (idx = e; idx >= s; idx--) {
		num += multi * (str[idx] - diff);
		multi *= 10;
	}
	return num;
}

int leap_year(int year)
{
	int leap = 0;
	// TODO: �̰��� �ڵ带 �ۼ��ϼ���.

}

int formatErrorCheck(char *p_num)
{
	int dayofmonth[] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int check_num;
	int i, mod = 0, sum = 0;
	int year, leap = 0;

	// �ֹι�ȣ ���̴� 13
	if (strlen(p_num) != 13) {
		return 0;
	}
	// ���� 12���� �Ѿ�� �� �ȴ�.
	if () {
		return 1;
	}
	// ���� ������ ��¥�� �Ѿ�� �� �ȴ�.
	if () {
		return 2;
	}
	// �����̸� 1
	year = (strtoNum(p_num, 6, 6) <= 2) ? 1900 : 2000;
	year += strtoNum(p_num, 0, 1);
	leap = leap_year(year);
	// 2���̰� ����̸� 29�� ������ �� �ȴ�.
	if () {
		return 3;
	}
	if (p_num[6] - '0' < 1 || p_num[6] - '0' > 4) {
		return 4;
	}

	// �ֹι�ȣ �����ڵ�(�����ѹ�) �˻�
	if (mod != p_num[12] - '0')
		return 5;

	return -1;
}

int isY(void)
{
	char answer;
	printf("�ٽ� �Է��Ͻðڽ��ϱ�? (y/n) "); OUT;
	fflush(stdin);
	scanf("%c", &answer);
	if (answer == 'Y' || answer == 'y')
		return 1;
	return 0;
}

int main(void)
{
	char *errormsg[] = {
			"�ֹε�Ϲ�ȣ ���̰� Ʋ�Ƚ��ϴ�.",
			"�߸� �Էµ� ����ȣ�Դϴ�.",
			"�߸� �Էµ� �Ϲ�ȣ�Դϴ�.",
			"����ε� ���� ��¥�Դϴ�.",
			"���� ��ȣ�� �߸� �ԷµǾ����ϴ�.",
			"�����ڵ� ������ �ֹε�Ϲ�ȣ�Դϴ�." };
	char p_num[15];
	int errorno = 0;

	do {
		printf("\"-\"�� ������ Ȯ���� �ֹε�Ϲ�ȣ 13�ڸ��� �Է��ϼ��� : "); OUT;
		scanf("%s", p_num);

		errorno = formatErrorCheck(p_num);
		if (errorno >= 0)
			printf("%s\n", errormsg[errorno]);
		else
			printf("�ùٸ� �ֹε�Ϲ�ȣ�Դϴ�.\n");
	} while (isY());

	return 0;
}

#endif
