#include <stdio.h>

int main(void)

{
	int num1;
	while(1)
	{
  
		printf("숫자를 입력하세요 (종료는 0) : ");	
		scanf("%d",&a);
		
		// 소수 판단
		if(((a%2)!=0)||(a==2)){
		if(((a%3)!=0)||(a==3)){
			if(((a%5)!=0)||(a==5)){
				if(((a%7)!=0)||(a==7)){
					if(a!=1){
				printf("소수입니다.\n");
			     }
			     else{
			     	printf("소수가 아닙니다.\n");
				   }
		        }
		        else{
			     	printf("소수가 아닙니다.\n");
				   }
			  }
			  else{
			     	printf("소수가 아닙니다.\n");
				   }
		  }
		  else{
			     	printf("소수가 아닙니다.\n");
				   }
		}
		else if(a!=0){
			     	printf("소수가 아닙니다.\n");
				   }
		if(a==0){
		
		printf("Bye~~ \n");
		break;
		}
	}
	return 0;
  
}
