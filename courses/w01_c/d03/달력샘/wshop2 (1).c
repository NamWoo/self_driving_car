

int mdays[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int main() {

	int year, month;
	int start;  		// 1일이 출력되는 시작위치를 맞추기 위한 변수  ( 0 ~ 6이 될 수 있으며, 0의 경우 일요일)
	int days;		    // 각 월의 일 수를 저장할 변수

	// 입력 부분
	printf("# Input Year, Month : "); 
	scanf("%d%d", &year, &month);

	// 출력할 년, 월에 해당하는 1일의 요일 계산
	// start = get_weekday(year, month);

	// 출력할 달의 일수 계산
	// days = get_days(year, month);

	// 달력 출력
	// disp_calender(year, month, start, days);

	return 0;
}


// 윤년 검사 함수
int leap_check(int year)
{
	if(year%4!=0) return 0;
	else if(year%100!=0) return 1;
	else if(year%400==0) return 1;
	else return 0;
}

