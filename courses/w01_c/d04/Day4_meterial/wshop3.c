// 사번 등록, 로그인 메뉴 관련 함수와 변수
//---------------------------------------------------------------
#include <stdio.h>
int disp_menu(void);
void enroll_num(void);
void login_out(void);
int is_enroll_num(int num);

int e_num[5];           	// 사번
int e_pwd[5];          		// 비밀번호
int e_cnt;              		// 등록인원 수
int login_num = 0;      	// 로그인 되면 사번 저장
int mdays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };   // 각 달의 일수

//-----------------------------------------------------------------

// 달력 출력 관련 함수
//-----------------------------------------------------------------
int leap_check(int year);
int get_days(int year, int month);
int get_weekday(int year, int month);
void disp_calendar(int year, int month);
//-----------------------------------------------------------------

// 스케줄 등록, 조회 관련 함수와 변수
//-----------------------------------------------------------------
void input_schedule(void);
int on_schedule(int year, int month, int day);
void search_schedule(void);

int s_day[100][4];      // 최대 100개의 스케줄 날짜 저장, 사번, 년, 월, 일
int s_cnt = 0;             // 스케줄 등록 수
//-----------------------------------------------------------------

int main(void)
{
	int num;

	while (1)
	{
		num = disp_menu();
		if (num == 0) break;

		switch (num)
		{
		case 1:
			enroll_num(); break;
		case 2:
			login_out(); break;
		case 3:
			input_schedule();	break;
		case 4:
			search_schedule(); break;
		default:
			printf("@ 메뉴 번호가 아닙니다!\n\n");
			break;
		}
	}
   // PAUSE;
	return 0;
}

// 메뉴 출력 후 선택 번호 반환
int disp_menu(void)
{
	int num;

	printf("\n===[ 회의실 예약 시스템 ]===\n");
	printf("1. 사번 등록/삭제\n");
	printf("2. 로그인/로그아웃\n");
	printf("3. 회의실 예약\n");
	printf("4. 예약 상태 조회\n");
	printf("0. 종료\n");
	printf("---------------------------\n");

	printf("> 번호 선택 : "); //OUT;
	scanf("%d", &num);

	return num;
}


int get_checkRange(char* what, int min, int max) {
	int input = 0;
	printf("> %s(%d-%d) : ", what, min, max); //OUT;
	scanf("%d", &input);
	if ((input < min) || (input > max))     // 허용 범위의 숫자가 아니면 반환
	{
		printf("@ 유효한 번호가 아닙니다!\n");
		return -1;
	}
	return input;
}

void deleteFromIDList(int dno) {
	int i=0;

	for (i = dno; i < (e_cnt - 1); i++)
	{
		e_num[i] = e_num[i + 1];
		e_pwd[i] = e_pwd[i + 1];
	}
	e_cnt--;										// 등록된 사번 수 감소
}

void insertToIDList(int id, int pwd) {
	e_num[e_cnt] = id;
	e_pwd[e_cnt] = pwd;
	e_cnt++;                                   // 등록된 사번 수 증가
	printf("# %d번이 등록되었습니다!\n", id);
}

void printIDList(){
	int i=0;

	printf("\n>> 현재 등록된 사번(비밀번호) : ");
	for (i = 0; i < e_cnt; i++)
	{
		printf("%5d(%d)", e_num[i], e_pwd[i]);
	}
	printf("\n\n");
}


void deleteID(int dno) {
	char yn = 0;

	printf("@ 이미 등록되었습니다!\n");
	printf("@ 삭제 하시겠습니까(Y/N)?"); //OUT;

	fflush(stdin);
	scanf("%c", &yn);
	if ((yn == 'Y') || (yn == 'y'))
	{
		deleteFromIDList(dno);
		printf("@ %d번이 삭제 되었습니다!\n", e_num[dno]);
		printIDList();
	}
	printf("@ 취소 되었습니다!\n");
}

void insertID(int id){
	int pwd = 0;
	int cnt =  sizeof(e_num) / sizeof(e_num[0]);    	// 최대 등록인원 수 계산
	if (e_cnt == cnt)                          						// 등록인원 수가 최대 인원 수와 같으면 반환
	{
		printf("@ 등록 인원이 초과되었습니다!");
		return;
	}
	pwd = get_checkRange("비밀번호", 0, 9999);
	if (pwd == 0)  return;
	insertToIDList(id, pwd);
	printIDList();
}

// 사번 등록 / 삭제
void enroll_num(void)
{
	int num;                          			// 사번
	int index;                                  // 사번이 있는 배열의 위치
	int i,pwd;
	char ch;
	
	if (login_num != 0)                   // 이미 로그인 된 상태면 반환
	{
		printf("@ 로그아웃 후 사용할 수 있습니다!\n");
		return;
	}

	printf("\n[ 사번 등록/삭제 ]\n\n");
    // todo: 사번 등록 / 삭제 코드 작성
    
    printf("> 사번(1 - 9999) : ");
    scanf("%d",&num);
    
    
    if( num < 0 && num > 9999){
    	printf("@ 유효하지 않은 사번입니다.\n");
    	return;
	}
	
	for(i=0;i<5;i++){
		if(e_num[i] == num){
			printf("@ 이미 등록되어 있습니다.\n");
			printf("@ 삭제 하시겠습니까? (Y/N) : ");
			fflush(stdin);
			scanf("%c",&ch);
			
			if(ch == 'y' || ch == 'Y')
			{
				e_num[i] = 0;
				e_pwd[i] = 0;
				
				printf("@ 삭제 되었습니다!\n");
				
				return;
			}
			else
			{
				printf("@ 취소되었습니다.\n");
				return;
			}
			
		}
	}
	for(index=0;index<5;index++)
	{
		if(e_num[index] == 0)
		{
			printf("> 비밀번호 ( 1 - 9999) :");
			scanf("%d",&pwd);
			
			printf("check.\n");
			if(pwd < 1 && pwd >9999)
			{
				printf("@ error!!!\n");
				return;
			}
			else
			{
				e_num[index] = num;
				e_pwd[index] = pwd;
				printf("@ 등록되었습니다.\n");
				
				printf("@ 현재 등록되어 있는 사원 : ");
				for(i=0;i<5;i++){
					if(e_num[i]!=0)
					{
						printf("%d(%d) ",e_num[i],e_pwd[i]);
					}
				}
				
				return;
			}
		}
	}
	
	
	

}

// 로그인 / 로그아웃
void login_out(void)
{
	int num, pwd;
	int index;

	//printf("login num == %d \n",login_num);
	// todo: 로그인, 로그아웃 코드 작성
	if(login_num == 0){
		printf("> 사번 : ");
		scanf("%d",&num);
		for(index =0;index<5;index++){
			if(e_num[index] == num)
			{
				printf(" 비밀번호 : ");
				scanf("%d",&pwd);
				
				if(pwd == e_pwd[index])
				{
					login_num = num;
					printf("@ 로그인 되었습니다!\n");
					return;
				}
				else
				{
					printf("@ 비밀번호가 다릅니다!\n");
					return;
				}
			}
		}
		printf("@ 존재하지 않는 사번입니다.\n");
		return;
		
	}
	else
	{
		login_num = 0;
		printf("@ 로그아웃 되었습니다.\n");
		return;
	}

}

// 등록된 번호인지 확인
int is_enroll_num(int num)
{
	int i;

	// todo: 등록된 번호인지 확인 코드 작성

	return -1;
}

// 회의실 예약 등록
void input_schedule(void)
{
	int year, month, day;    // 스케줄을 입력할 날
	int i;
	if (login_num == 0)      // 로그인되지 않았다면 반환
	{
		printf("@ 로그인 후 사용할 수 있습니다!\n");
		return;
	}

	printf("\n[ 회의실 예약 ]\n\n");

	printf("> 년, 월 입력 : "); //OUT;
	scanf("%d%d", &year, &month);
	// todo: 회의실 예약 등록 코드 작성

	disp_calendar(year,month);
	
	printf("# 날짜를 입력하세요 : ");
	scanf("%d",&day); 
	
	if(on_schedule(year,month,day) != 0)
	{
		printf("# 등록되어 있는 날짜입니다.\n");
		return;
	}
	

	
	for(i=0;i<100;i++){
		if(s_day[i][0] == 0){
			s_day[i][0] = login_num ;
			s_day[i][1] = year;
			s_day[i][2] = month;
			s_day[i][3] = day;
			break;
		}
	}

	printf("@ 회의실 예약이 등록되었습니다!\n");

}

// 해당 날짜에 대한 스케줄 수 확인, 없는 경우 0 반환
int on_schedule(int year, int month, int day)
{
	int cnt = 0;
	int i;
    // todo: year, month, day에 해당하는 스케쥴 수 반환
	
	for(i=0;i<100;i++){
		if(s_day[i][1] == year && s_day[i][2] == month && s_day[i][3] == day){
			cnt++;
		}
		
	}
	
	return cnt;
}

// 회의실 예약 상태 조회
void search_schedule(void)
{
	int year, month, day;    // 예약 상태를 검색할 날
	int cnt=0;                		    // 예약 건 수
	int i;
	if (login_num == 0)      // 로그인되지 않았다면 반환
	{
		printf("@ 로그인 후 사용할 수 있습니다.\n");
		return;
	}

	printf("\n[ 회의실 예약 상태 조회 ]\n\n");

	printf("> 년, 월 입력 : "); //OUT;
	scanf("%d%d", &year, &month);
	// todo: 회의실 예약 상태 확인 코드 작성

	disp_calendar(year,month);
	
	for(i=0;i<100;i++)
	{
		if(s_day[i][1] == year && s_day[i][2] == month)
			cnt++;
	}



	printf("@ %d건의 예약된 스케줄이 있습니다!\n", cnt);

}


//=======< 여기서 부터는 달력 출력 관련 함수 >=================================================

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

	// 1월부터 month-1월 까지의 총 일수 누적
	for(i=0; i<month-1; i++){
		tot+=mdays[i];
	}

	// 윤년이고 달이 3월 이상이면 2월이 29일이므로 하루를 더한다.
	if(leap_check(year) && month>=3) tot++;

	// 당월의 1일을 누적
	tot++;

	return tot%7;  // 요일 위치 반환
}

// 달력 출력
void disp_calendar(int year, int month)
{
	int i=0;
	int cnt=0; 			 // 탭을 포함해 한 줄에 7일을 출력하기 위한 변수
	int start;                // 1일이 출력될 시작 요일 위치
	int days;                // 출력 달의 마지막 날

	start = get_weekday(year, month);                                          // 1일이 출력될 시작 요일 위치 계산
	days =get_days(year, month);

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
		if (on_schedule(year, month, i) > 0)
			printf("%3c%2d", '*', i);
		else
			printf("%5d", i);
		cnt++;  // 출력할 때마다 카운트
		if(cnt%7==0) printf("\n");  // 한 줄에 7일이 출력되면 줄 바꾼다.
	}
	printf("\n");
	printf("------------------------------------\n");

}


