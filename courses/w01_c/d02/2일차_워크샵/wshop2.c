

int mdays[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int main() {

	int year, month;
	int start;  		// 1���� ��µǴ� ������ġ�� ���߱� ���� ����  ( 0 ~ 6�� �� �� ������, 0�� ��� �Ͽ���)
	int days;		    // �� ���� �� ���� ������ ����

	// �Է� �κ�
	printf("# Input Year, Month : "); 
	scanf("%d%d", &year, &month);

	// ����� ��, ���� �ش��ϴ� 1���� ���� ���
	// start = get_weekday(year, month);

	// ����� ���� �ϼ� ���
	// days = get_days(year, month);

	// �޷� ���
	// disp_calender(year, month, start, days);

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

