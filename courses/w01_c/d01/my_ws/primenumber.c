/*
 * primenumber.c
 */

#include "wshop1.h"

#ifdef PRIME

int main(void)
{
	int result = 0;
	int inputNumber = 0;
	int i = 0;

	while (1) {
		result = 0;
		printf("���ڸ� �Է��ϼ���(���� : 0) : "); OUT;
		scanf("%d", &inputNumber);

		if (inputNumber == 0) {
			printf("Bye~~");
			break;
		}

		if (inputNumber > 1) {
			result = 1;

			for (i = 2; i < inputNumber; i++) {
				if (inputNumber % i == 0) {
					result = 0;
					break;
				}
			}
		}
		if (result)
			printf("�Ҽ��Դϴ�.\n");
		else
			printf("�Ҽ��� �ƴմϴ�.\n");
	}

	PAUSE;
	return 0;
}

#endif
