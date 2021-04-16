#include <stdio.h>

int main(void)
{
	int i=0,buf=0;
	const int ans = 17;
	for(i=1 ; i<=30 ; i++) {
		printf("insert number (1~30) : ");
		scanf("%d",&buf);
		
		if(buf==ans) {
			puts("success!!");
			puts("success!!");
			puts("success!!");
			break;
		}
		else {
			puts("wrong ans");
			if(buf<ans) {
				puts("UP");
			}
			else {
				puts("DOWN");
			}
		}
	}
	
	return 0;
}
