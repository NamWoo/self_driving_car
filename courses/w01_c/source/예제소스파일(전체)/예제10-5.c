#include <stdio.h>

int main(void)
{
	int ary[5] = {10, 20, 30, 40, 50};
	int *pa = ary;                       // 첫 번째 배열 요소 주소
	int *pb = pa + 3;                    // 네 번째 배열 요소 주소

	printf("pa : %u\n", pa);
	printf("pb : %u\n", pb);
	pa++;                                // pa를 다음 배열 요소로 이동
	printf("pb - pa : %u\n", pb - pa);   // 두 포인터의 뺄셈

	printf("앞에 있는 배열 요소의 값 출력 : ");
	if (pa < pb) printf("%d\n", *pa);    // pa가 배열의 앞에 있으면 *pa 출력
	else printf("%d\n", *pb);            // pb가 배열의 앞에 있으면 *pb 출력

	return 0;
}