//===========< main.c >===============

#include <stdio.h>
#include "friend.h"
#include "func.h"

int main(void)
{
	Friend my_friend[BEST_CNT];
	Friend oldest;

	input_data(my_friend);
	oldest = get_oldest_friend(my_friend);
	print_data(oldest);

	return 0;
}


//===========< friend.h >===============

#ifndef _FRIEND_H_
#define _FRIEND_H_

struct friend
{
	char gender;
	int age;
	char name[20];
	char phone_num[20];
};
typedef struct friend Friend;

#endif


//===========< func.h >===============

#ifndef _FUNC_H_
#define _FUNC_H_

#include "friend.h"
#define BEST_CNT 5

void input_data(Friend *);
Friend get_oldest_friend(Friend *);
void print_data(Friend);

#endif


//===========< func.c >===============

#include <stdio.h>
#include "func.h"

void input_data(Friend *my_friend)
{
	int i;

	for(i = 0; i < BEST_CNT; i++)
	{
		printf("> 성별 입력(m/f) : ");
		scanf("%c", &my_friend->gender);
		printf("> 나이 입력 : ");
		scanf("%d", &my_friend->age);
		printf("> 이름 입력 : ");
		scanf("%s", my_friend->name);
		printf("> 전화번호 입력 : ");
		scanf("%s", my_friend->phone_num);
		my_friend++;
		fflush(stdin);
	}
}

Friend get_oldest_friend(Friend *my_friend)
{
	int i, oldest = 0;
	int index = 0;
	
	for(i = 0; i < BEST_CNT; i++)
	{
		if(my_friend[i].age > oldest)
		{
			oldest = my_friend[i].age;
			index = i;
		}
	}
	
	return my_friend[index];
}

void print_data(Friend oldest)
{
	printf("> 나이가 가장 많은 친구 : ");
	printf("@ 성별 : ");
	if(oldest.gender == 'm') printf("남");
	else printf("여");
	printf(", 나이 : %d세, 이름 : %s, 전화번호 : %s\n",
		oldest.age, oldest.name, oldest.phone_num);
}