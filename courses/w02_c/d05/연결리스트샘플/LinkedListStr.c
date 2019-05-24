#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*****************************************************************************
*  ex-1.c                                                                    *
*  ======                                                                    *
*  Description: Illustrates using a linked list (see Chapter 5).             *
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
/*****************************************************************************
*  ------------------------------ print_list ------------------------------  *
*****************************************************************************/
void insert_list(List *list, ListElmt *element);
void insert_list_after(List *list);
void delete_node(List *list);
static void print_list(const List *list) {
//to do
	ListElmt *tempLE;
	int cnt=1; 
	if(list_size(list) != 0)
	{
		tempLE = list->head;
		while(1)
		{
			printf("[%d]->%s   ", cnt, ((char*)(tempLE->data)));
			cnt++;
			if((tempLE=tempLE->next)==NULL)
				break;
		}
		printf("\n");
	}
	else
		printf("List is empty\n");
}
/*****************************************************************************
*  --------------------------------- main ---------------------------------  *
*****************************************************************************/
int list_menu(void){
	int select;
	do{
		printf("1. Insert node\n");
		printf("2. Insert node after...\n");
		printf("3. Find node\n");
		printf("4. Delete node\n");
		printf("5. Delete node after...\n");
		printf("6. Delete all node\n");
		printf("7. Display all node\n");
		printf("0. Quit\n");
		printf("Input Operation : ");
		scanf("%d", &select);
	}while(select<0||select>7);
	return select;
}
void start(List *list)
{
	int select;
	while((select=list_menu())!=0)
	{
		switch(select)
		{
			case 1:
				insert_list(list, NULL);
				break;
			case 2:
				insert_list_after(list);
				break;
			case 3:
				find_list(list);
				break;
			case 4:
				delete_node(list);
				break;
			case 5:
				delete_node_after(list);
				break;
			case 6:
				delete_node_all(list);
				break;
			case 7:
				print_list(list);
				break;
			case 0: 
				exit(1);
				break;
			default :
				break;
		}
	}
}

int main(int argc, char **argv) {

List               list;
ListElmt           *element;

int                *data, i;

/*****************************************************************************
*  Initialize the linked list.                                               *
*****************************************************************************/

	list_init(&list, free);
	start(&list);
/*****************************************************************************
*  Perform some linked list operations.                                      *
*****************************************************************************/
}

void insert_list(List *list, ListElmt *element)
{
	char str[30];
	void *data;
	data = (char *)malloc(sizeof(str)/sizeof(str[0]));
	printf("삽입할 값을 입력하시오 : ");
	scanf("%s", data);
	list_ins_next(list, NULL, data);
	print_list(list);
}

void insert_list_after(List *list)
{
	char str[30];
	void *data;
	int num, i;
	ListElmt *tempLE;
	if(list_size(list)==0)
	{
		printf("리스트가 비어있습니다.\n");
		return;
	}
	data = (char *)malloc(sizeof(str)/sizeof(str[0]));
	printf("삽입할 값을 입력하시오 : ");
	scanf("%s", data);
	print_list(list);
	printf("몇번째 값 후에 입력하시겠습니까? : ");
	scanf("%d", &num);
	tempLE = list->head;
	for(i=0;i<num-1;i++)
	{
		tempLE=tempLE->next;
	}
	list_ins_next(list, tempLE, data);
	print_list(list);
}

int find_list(List *list)
{
	char data[30];
	int cnta=0, cntb=1;
	int nums[10]={0,};
	int i;
	ListElmt *tempLE;
	if(list_size(list)==0)
	{
		printf("리스트가 비어있습니다.\n");
		return;
	}
	printf("찾고자 하는 값을 입력하시오 : ");
	scanf("%s", data);
	tempLE = list->head;
	while(1)
	{
	
		if(!(strcmp(((char*)(tempLE->data)),data)))
			nums[cnta++]=cntb;
		if(list_is_tail(tempLE)/*tempLE->next==NULL*/)
			break;
		tempLE=tempLE->next;
		cntb++;
	}
	if(nums[0]==0)
		printf("찾고자 하는 값이 없습니다.\n");
	else
	{
		print_list(list);
		for(i=0;i<cnta;i++)
		{
			printf("%d ", nums[i]);
		}
		printf("번째 값이 동일합니다.\n"); 
	}
}

void delete_node(List *list)
{
	void *data;
	if(list_size(list)==0)
	{
		printf("리스트가 비어있습니다.\n");
		return;
	}
	list_rem_next(list, NULL, &data);
	printf("list의 첫번째 값 %s이 제거되었습니다.\n", (char*)data);
	print_list(list);
}
void delete_node_after(List *list)
{
	ListElmt *tempLE;
	void *data;
	int num;
	int i;
	if(list_size(list)==0)
	{
		printf("리스트가 비어있습니다.\n");
		return;
	}
	print_list(list);	
	printf("몇번째 값의 다음값을 삭제하시겠습니까? : ");
	scanf("%d", &num);
	tempLE = list->head;
	for(i=0;i<num-1;i++)
	{
		tempLE=tempLE->next;
	}
	list_rem_next(list, tempLE, &data);
	print_list(list);
	printf("%d번째의 다음, %d번째 값 %s이 제거되었습니다.\n", num, num+1, (char*)data);
}
void delete_node_all(List *list)
{
	ListElmt *tempLE;
	int cnt=1;
	void *data;
	char yn;
	if(list_size(list)==0)
	{
		printf("리스트가 비어있습니다.\n");
		return;
	}
	fflush(stdin);
	printf("모든 노드를 비우시겠습니까? : (Y/N)");
	scanf("%c", &yn);	
	fflush(stdin);
	if(yn=='y'||yn=='Y')
	{
		while(1)
		{
			list_rem_next(list, NULL, &data);
			if(list->tail==NULL)
				break;
		}
	}
}
