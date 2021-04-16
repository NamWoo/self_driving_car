/*
 * triangle.c
 */

#include "wshop1.h"

#ifdef TRIANGLE

int main(void)
{
	int num;
	int i, k; // for ���� �ݺ������� ���
	printf("Input number : "); OUT;
	scanf("%d", &num);

	if (!(num % 2)) {
		printf("# ¦���� �ԷµǾ����ϴ�!");
		PAUSE;
		return 0;
	}

    /*
                *
               **
              ***
             ****
            *****
    */
	for (i = num; i > 0; i--) {
		for (k = 0; k < i - 1; k++) {
			printf(" ");
		}
		for (k = 0; k <= num - i; k++) {
			printf("*");
		}
		printf("\n");
	}
	printf("\n");

	/*
            *****
             ****
              ***
               **
                *
    */
	for (i = num; i > 0; i--) {
		for (k = 0; k < num - i; k++) {
			printf(" ");
		}
		for (k = 0; k < i; k++) {
			printf("*");
		}
		printf("\n");
	}
	printf("\n");

	/*
              *
             ***
            *****
             ***
              *
    */
	for (i = 0; i < num / 2 + 1; i++) {
		for (k = 0; k < num / 2 - i; k++) {
			printf(" ");
		}
		for (k = 0; k < i * 2 + 1; k++) {
			printf("*");
		}
		printf("\n");
	}
	for (i = 0; i < num / 2; i++) {
		for (k = 0; k <= i; k++) {
			printf(" ");
		}
		for (k = num - i * 2; k > 2; k--) {
			printf("*");
		}
		printf("\n");
	}
	printf("\n");

	PAUSE;
	return 0;
}

#endif
