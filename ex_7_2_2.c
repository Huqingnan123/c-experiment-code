#include <stdio.h>
#include <stdlib.h>
struct s_list {
	int data; 
	struct s_list *next;
};
void create_list(struct s_list **headp, int *p);
void main(void)
{
	struct s_list *head = NULL, *p;
	int s[] = { 1,2,3,4,5,6,7,8,0 }; /* 0Ϊ������� */
	create_list(&head, s); /* ���������� */
	p = head; /*����ָ��pָ����ͷ */
	while (p) {
		printf("%d\t", p->data); 
		p = p->next; /*����ָ��pָ����һ��� */
	}
	printf("\n");
}
void create_list(struct s_list **headp, int *p)
{
	struct s_list * loc_head = NULL, *tail;
	if (p[0] == 0) 
		;
	else {
		tail = (struct s_list *)malloc(sizeof(struct s_list));/*�ʼ�Ľڵ����ĩβ*/
		tail->data = *p++; 
		tail->next = NULL; 
		while (*p) { 
			loc_head = (struct s_list *)malloc(sizeof(struct s_list));
			loc_head->next = tail;
			loc_head->data = *p++;
			tail = loc_head;			/*�½��ڵ��Ϊ��һ���½ڵ�ĺ�һ���ڵ�*/
		}
	}
	*headp = loc_head; /* ʹͷָ��headpָ���´��������� */
}
