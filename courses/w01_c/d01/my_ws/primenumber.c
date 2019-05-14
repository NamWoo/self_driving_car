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
		printf("숫자를 입력하세요(종료 : 0) : "); OUT;
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
			printf("소수입니다.\n");
		else
			printf("소수가 아닙니다.\n");
	}

	PAUSE;
	return 0;
}

#endif
