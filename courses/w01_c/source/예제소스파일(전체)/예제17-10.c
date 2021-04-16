#include <stdio.h>

struct list                            // �ڱ� ���� ����ü
{
	int num;                           // �����͸� �����ϴ� ���
	struct list *next;                 // ����ü �ڽ��� ����Ű�� ������ ���
};

int main(void)
{
	struct list a = {10, 0}, b = {20, 0}, c = {30, 0};        // ����ü ���� �ʱ�ȭ
	struct list *head = &a, *current;                         // ��� ������ �ʱ�ȭ

	a.next = &b;                       // a�� ������ ����� b�� ����Ŵ
	b.next = &c;                       // b�� ������ ����� c�� ����Ŵ

	printf("head->num : %d\n", head->num);                    // head�� ����Ű�� a�� num ��� ���
	printf("head->next->num : %d\n", head->next->num);        // head�� b�� num ��� ���

	printf("list all : ");
	current = head;                    // ���� temp �����Ͱ� a�� ����Ŵ
	while (current != NULL)            // ������ ����ü �������� ����ϸ� �ݺ� ����
	{
		printf("%d ", current->num);   // temp�� ����Ű�� ����ü ������ num ���
		current = current->next;       // temp�� ���� ����ü ������ ����Ű���� ��
	}
	printf("\n");

	return 0;
}