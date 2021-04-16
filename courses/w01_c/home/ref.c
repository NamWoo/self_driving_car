#define ENDMSG_RUTIN do{puts("Program terminated!!\n\n");}while(0);
#define WAITKEY_RUTIN do{printf("\ncontinue to press any key");fflush(stdin);getc(stdin);}while(0);
#define MID_DBL_LINE do{puts("=====================================================");}while(0);
#define MAXLEN 100 //max len of buf
#define WAIT_RUTIN do{puts("Looding..");sleep(1);puts("Looding......");sleep( 1 );}while(0);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void disp_calendar(int year, int month);
int get_weekday(int year, int month);
int get_weekday(int year, int month);
int leap_check(int year);
int app_Launcher(int mode);
//int print_accinfo(struct account myacc);//


int dispmenu(void);
int loginout(void);
int accprint(void);
int banktrns(void);
int withdraw(void);
int depositm(void);
int checkdps(void);
int calprint(void);
int levamesg(void);
int gamemode(void);



struct account {
	char *Name;
	
	int deposit;
	int trust;
	
	char ID[MAXLEN];
	char PW[MAXLEN];
	
};
struct account cur_user;

int mdays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int loginflag = 0;
char ID_admin[] = "admin";
char PW_admin[] = "admin";
char *msgfreq[10] ;


int main(void)
{
	
	return app_Launcher(1);
}


int app_Launcher(int mode) {
	//mode 1 : nomal mode
	//mode 2 : debug mode
	int num=1;

	while (num)
	{
		num = dispmenu();
		switch (num) {
		
		case 1:loginout();
			break;
		
		case 2:accprint();
			break;
		
		case 3:banktrns();
			break;
			
		case 4:withdraw();
			break;
		
		case 5:depositm();
			break;
						
		case 6:checkdps();
			break;

		case 7:calprint();
			break;
		
		case 8:levamesg();
			break;
		
		case 9:gamemode();
			break;
			
		default:
			ENDMSG_RUTIN	
			exit(1);
			break;
		}
	}
    //PAUSE;
}

// 메뉴 출력 후 선택 번호 반환
int dispmenu(void)
{
	int num;
	MID_DBL_LINE 
	puts("\n===[ Welcome DHKim BANK!! ]===\n");
	puts("===[ Select your menu ]=========");
	puts(">> 1. Login / Logout");
	puts(">> 2. account info print");
	puts(">> 3. Bank Transfer");
	puts(">> 4. withdraw money");
	puts(">> 5. Deposit money");
	puts(">> 6. Deposit Check");
	puts(">> 7. Calender");
	puts(">> 8. Leave a Message");
	puts(">> 9. Program Vision");
	puts(">> 0. Exit");
	MID_DBL_LINE 
	printf(">>insert your menu number : "); 
	scanf("%d", &num);
	//puts("\n");
	return num;
}

int loginout (void) {
	int idok=0, pwok=0;
	char buf[MAXLEN];
	char ch;

	
	if( loginflag == 1) {
		puts("already admin login");
		printf("do you want Logout? (Y/N)");
		fflush(stdin);
		scanf("%c",&ch);
		if(ch == 'Y' || ch == 'y') {
			puts("outout! bye bye");
			WAITKEY_RUTIN
		}
		else {
			puts("cancled");
			WAITKEY_RUTIN
		}
	}
	

	
	puts("======admin ID / Passward Check=====");
	puts("defulat : admin/admin") ;
	printf("ID : ");
	scanf("%s",&buf);
	
		if( 0 == strcmp(ID_admin,buf) ) {
			printf("PW : ");
			scanf("%s",&buf);
			if( 0 == strcmp(PW_admin,buf) ) {
				MID_DBL_LINE 
				puts("administor loginned!! WEEELLLCOME");
				MID_DBL_LINE 
				loginflag=1;	
				WAIT_RUTIN
				WAITKEY_RUTIN
			}
		}
		else {
			puts("ID is wrong!");
			WAITKEY_RUTIN
			return;
		}
	
		
	
}

int accprint (void) {
	int i=0;
	if(loginflag) {
		for(i=0;i<5;i++) {//
			puts("구조체포인터를 넘겨받아 계좌정보를 출력");
			//print_accinfo(/*acc 구조체 주소*/);
			
		}
		MID_DBL_LINE
		puts("end of the Lisht") ;
		MID_DBL_LINE
		WAITKEY_RUTIN
		//당신의 잔액, 송금계좌, 금액 
	}
	else {
		puts("Login First!");
		WAITKEY_RUTIN
	}

	
	
	
}

int banktrns (void) {
	if(loginflag) {
		//당신의 잔액, 송금계좌, 금액 
	}
	else {
		puts("Login First!");
		WAITKEY_RUTIN
	}

}

int withdraw (void) {
	
	if(loginflag) {
	}
	else {
		puts("Login First!");
		WAITKEY_RUTIN
	}

}

int depositm (void) {
	if(loginflag) {
		printf("ID : %s",cur_user.ID);//기능 추가구현 필요 
		printf("deposit : %d",9999999);
	}
	else {
		puts("Login First!");
		WAITKEY_RUTIN
	}
}

int checkdps (void) {
		if(loginflag) {
		printf("ID : %s",cur_user.ID);//기능 추가구현 필요 
		printf("deposit : %d",9999999);
	}
	else {
		puts("Login First!");
		WAITKEY_RUTIN
	}
}

int calprint (void) {
	char buf;
	disp_calendar(2019, 5);
	printf("continue to any key");
	fflush(stdin);
	getc(stdin);
}

int levamesg (void) {
	
}

int gamemode (void) {
	puts("\n\n");
	puts("======Comming soon======");
	puts("Meeting reservation");
	puts("FILE I/O-> Save : data.csv ");
	puts("Calculator");
	puts("Double Linked List custmer ");
	puts("");
	printf("continue to any key");
	fflush(stdin);
	getc(stdin);
}


int print_accinfo(struct account myacc) {
	printf("User name : $s\n", myacc.Name);
	printf("User deposit : %d\n", myacc.deposit);
	printf("User trust : %d\n", myacc.trust);
	printf("User Identiti : ", myacc.ID);
	printf("User password : ", myacc.PW);
	
	return 0;
	
}


//==================================================
//re-used func
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
		printf("%5d", i);
		cnt++;  // 출력할 때마다 카운트
		if(cnt%7==0) printf("\n");  // 한 줄에 7일이 출력되면 줄 바꾼다.
	}
	printf("\n");
	printf("------------------------------------\n");

}
