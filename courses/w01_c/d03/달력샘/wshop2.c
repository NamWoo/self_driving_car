
int mdays[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int leap_check(int year);
int get_days(int year, int month);
int get_weekday(int year, int month);
void disp_calender(int year, int month, int start, int days);

int main() {

	int year, month;
	int start;  		// 1일이 출력되는 시작위치를 맞추기 위한 변수  ( 0 ~ 6이 될 수 있으며, 0의 경우 일요일)
	int days;		// 각 월의 일 수를 저장할 변수

	// 입력 부분
	printf("# Input Year, Month : ");
//	scanf("%d%d", &year, &month);
	year = 2018;
	month = 7;

	// 출력할 년, 월에 해당하는 1일의 요일 계산
	start = get_weekday(year, month);

	// 출력할 달의 일수 계산
	days = get_days(year, month);

	// 달력 출력
	disp_calender(year, month, start, days);

    
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

// 출력할 달의 일수 계산
int get_days(int year, int month)
{
	int days =0;
	days=mdays[month-1];
	if(leap_check(year) && month==2) ++days;  // 윤년이고 2월이면 29일로 계산
	return days;
}

// 요일 구하는 함수
int get_weekday(int year, int month)
{
	int i, tot=0;

	// 1년부터 year-1년도까지의 총 일수 누적
	for(i=1; i<year; i++){
		if(leap_check(i)) tot+=366;
		else tot+=365;
	}
	printf("년합%d", tot);
	// 1월부터 month-1월 까지의 총 일수 누적
	for(i=0; i<month-1; i++){
		tot+=mdays[i];
	}
	printf("월합%d", tot);
	// 윤년이고 달이 3월 이상이면 2월이 29일이므로 하루를 더한다.
	if(leap_check(year) && month>=3) tot++;

	// 당월의 1일을 누적
	tot++;

	return tot%7;  // 요일 위치 반환
}

// 달력을 출력하는 함수
void disp_calender(int year, int month, int start, int days)
{
	int i=0;
	int cnt=0; 	// 탭을 포함해 한 줄에 7일을 출력하기 위한 변수


	printf("\n============< %4d. %2d >============\n\n", year, month);
	printf("------------------------------------\n");
	printf("%5s%5s%5s%5s%5s%5s%5s\n", "Sun","Mon","Tue","Wed","Thu","Fri","Sat");
	printf("------------------------------------\n");

	// 앞에서부터 요일 위치까지 공백 출력
	for(i=0; i<start; i++){
		printf("%5c", ' ');
		cnt++;  // 공백도 한 줄의 일부로 카운트한다.
	}

	// 날짜 출력 (1 ~ 그 달의 출력할 일 수)
	for(i=1; i<=days; i++){
		printf("%5d", i);
		cnt++;  // 출력할 때마다 카운트
		if(cnt%7==0) printf("\n");  // 한 줄에 7일이 출력되면 줄 바꾼다.
	}
	printf("\n");
	printf("------------------------------------\n");
}
