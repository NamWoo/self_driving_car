/*
 * packing.c
 */

#include "wshop1.h"

#ifdef PACKING

int main(void)
{
	unsigned int packing = 0;
	int id;
	int type;
	char gender;

	printf("# ���� ���� �Է�\n");

	printf("* ID : "); OUT;
	scanf("%d", &id);

	printf("* �۾� ���� : "); OUT;
	scanf("%d", &type);

	printf("* ����(M or F) : "); OUT;
	fflush(stdin);
	scanf(" %c", &gender);

	packing |= id;
	packing |= type << 20;
	packing |= ((gender == 'M') ? 0 : 1) << 28;

	printf("\n# ��ŷ ���\n");
	printf(">> %u\n", packing);

	printf("\n# ����ŷ ���\n");
	printf("* ID : %d\n", packing & 0xFFFFF);
	printf("* �۾� ���� : %d\n", (packing >> 20) & 0xFF);
	printf("* ���� : %s\n", (packing >> 28) ? "��" : "��");
	/*
	 printf("* ID : %d\n", (packing << 12) >> 12);
	 printf("* �۾� ���� : %d\n", (packing << 4 ) >> 24 );
	 printf("* ���� : %s\n", (packing >> 28)? "��" : "��");
	 */

	PAUSE;
	return 0;
}

#endif
