#include <stdio.h>
#include <math.h>

void main(void){
	char ch, temp[10];
	int cnt=0, t, nct=1, tot;
	
	while(((ch = getchar()) != '\n')&&(cnt != 10)){
		temp[cnt++] = ch;
	}
	
	for (t=cnt-1; t>-1; t--){		
		tot += ((temp[t] -'0') * nct);
		nct *=10;	 
	}
	printf("%d\n",tot+10);
}


