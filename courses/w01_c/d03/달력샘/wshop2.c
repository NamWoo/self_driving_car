
int mdays[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int leap_check(int year);
int get_days(int year, int month);
int get_weekday(int year, int month);
void disp_calender(int year, int month, int start, int days);

int main() {

	int year, month;
	int start;  		// 1���� ��µǴ� ������ġ�� ���߱� ���� ����  ( 0 ~ 6�� �� �� ������, 0�� ��� �Ͽ���)
	int days;		// �� ���� �� ���� ������ ����

	// �Է� �κ�
	printf("# Input Year, Month : ");
//	scanf("%d%d", &year, &month);
	year = 2018;
	month = 7;

	// ����� ��, ���� �ش��ϴ� 1���� ���� ���
	start = get_weekday(year, month);

	// ����� ���� �ϼ� ���
	days = get_days(year, month);

	// �޷� ���
	disp_calender(year, month, start, days);

    
	return 0;
}

// ���� �˻� �Լ�
int leap_check(int year)
{
	if(year%4!=0) return 0;
	else if(year%100!=0) return 1;
	else if(year%400==0) return 1;
	else return 0;
}

// ����� ���� �ϼ� ���
int get_days(int year, int month)
{
	int days =0;
	days=mdays[month-1];
	if(leap_check(year) && month==2) ++days;  // �����̰� 2���̸� 29�Ϸ� ���
	return days;
}

// ���� ���ϴ� �Լ�
int get_weekday(int year, int month)
{
	int i, tot=0;

	// 1����� year-1�⵵������ �� �ϼ� ����
	for(i=1; i<year; i++){
		if(leap_check(i)) tot+=366;
		else tot+=365;
	}
	printf("����%d", tot);
	// 1������ month-1�� ������ �� �ϼ� ����
	for(i=0; i<month-1; i++){
		tot+=mdays[i];
	}
	printf("����%d", tot);
	// �����̰� ���� 3�� �̻��̸� 2���� 29���̹Ƿ� �Ϸ縦 ���Ѵ�.
	if(leap_check(year) && month>=3) tot++;

	// ����� 1���� ����
	tot++;

	return tot%7;  // ���� ��ġ ��ȯ
}

// �޷��� ����ϴ� �Լ�
void disp_calender(int year, int month, int start, int days)
{
	int i=0;
	int cnt=0; 	// ���� ������ �� �ٿ� 7���� ����ϱ� ���� ����


	printf("\n============< %4d. %2d >============\n\n", year, month);
	printf("------------------------------------\n");
	printf("%5s%5s%5s%5s%5s%5s%5s\n", "Sun","Mon","Tue","Wed","Thu","Fri","Sat");
	printf("------------------------------------\n");

	// �տ������� ���� ��ġ���� ���� ���
	for(i=0; i<start; i++){
		printf("%5c", ' ');
		cnt++;  // ���鵵 �� ���� �Ϻη� ī��Ʈ�Ѵ�.
	}

	// ��¥ ��� (1 ~ �� ���� ����� �� ��)
	for(i=1; i<=days; i++){
		printf("%5d", i);
		cnt++;  // ����� ������ ī��Ʈ
		if(cnt%7==0) printf("\n");  // �� �ٿ� 7���� ��µǸ� �� �ٲ۴�.
	}
	printf("\n");
	printf("------------------------------------\n");
}
