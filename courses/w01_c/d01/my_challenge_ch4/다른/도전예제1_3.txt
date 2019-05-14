static void MarkingProgram()
{
	int ary[5];
	int max = INT_MIN;
	int min = INT_MAX;
	int total = 0;

	printf("5명의 심사위원 점수 입력 : ");
	for (int i = 0; i < 5; ++i)
	{
		scanf_s("%d", ary + i);
		max = max > ary[i] ? max : ary[i];
		min = min < ary[i] ? min : ary[i];
		total += ary[i];
	}

	total -= (max + min);

	double result = (double)total / 3;
	result *= 10;
	result += 0.5;
	result = (int)result;
	result /= 10;
	printf("%lf", result);


}

static void LottoProgram()
{
	int num[6];
	printf("로또 프로그램\n ");
	for (int i = 0; i < 6; ++i)
	{
	ReadNum:
		printf("로또번호입력하기 : ");
		scanf_s("%d", num + i);
		for (int j = 0; j < i; ++j)
		{
			if (num[j] == num[i])
			{
				printf("중복된 번호가 잇습니다\n");
				goto ReadNum;
			}
		}
	}

	printf("입력된 로또번호 ");
	for (int i = 0; i < 6; ++i)
	{
		printf("%d ", num[i]);
	}
	printf("\n");

}

