#include <stdio.h>

int main(void)
{
	int a = 10, b = 20, c = 10;
	int res;                       // 결과(result)값을 저장할 변수

	res = (a > b);                 // a가 b보다 크지 않으므로 결과값은 0
	printf("a > b : %d\n", res);
	res = (a >= b);                // a가 b보다 크지도 않고 같지도 않으므로 결과값은 0
	printf("a >= b : %d\n", res);
	res = (a < b);                 // a가 b보다 작으므로 결과값은 1
	printf("a < b : %d\n", res);
	res = (a <= b);                // a가 b보다 작으므로 결과값은 1
	printf("a <= b : %d\n", res);
	res = (a <= c);                // a가 c보다 작지는 않으나 같으므로 결과값은 1
	printf("a <= c : %d\n", res);
	res = (a == b);                // a와 b가 같지 않으므로 결과값은 0
	printf("a = = b : %d\n", res);
	res = (a != c);                // a와 c가 같으므로 결과값은 0
	printf("a != c : %d\n", res);

	return 0;
}