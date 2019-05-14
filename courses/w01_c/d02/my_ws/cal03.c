#include<stdio.h> 
#include<time.h> 
#define DAYSEC (24*60*60) 
int days(int year, int mon, int day) 
{ 
time_t next, now; 
struct tm tm_next, tm_now; 
int total = 0, ay = 0, am = 0; 

tm_next.tm_year = year - 1900; 
tm_next.tm_mon = mon - 1; 
tm_next.tm_mday = day+1; 
tm_next.tm_hour = 1; 
tm_next.tm_min = 0; 
tm_next.tm_sec = 0; 

time(&now); 
tm_now = *localtime(&now); 

next = mktime(&tm_next); 
now = mktime(&tm_now); 

now = next -now; 
total = now / DAYSEC; 

printf("%d년 %d월 %d일부터 %d년 %d월 %d일까지는 %d일 남았습니다.", tm_now.tm_year+1900,  
tm_now.tm_mon+1, tm_now.tm_mday, year, mon, day, total); 
} 


void main() 
{ 
int year, mon, day; 
printf("D-day 입력"); 
scanf_s("%d %d %d", &year, &mon, &day); 

days(year, mon, day); 
}

