#include <stdio.h> /*ͨ����������headͷָ��ĵ�ַ���൱�ڴ�����ָ��**headp=&head��Ϊ�βΣ�Ȼ�󽫺����й�����ͷָ��loc_headֱ�Ӹ���*headp�����൱��ֱ���޸���headͷָ��*/
#include <stdlib.h>
struct s_list {
	int data; /* ������ */
	struct s_list *next; /* ָ���� */
};
void create_list(struct s_list **headp, int *p);
void main(void)
{
	struct s_list *head = NULL, *p;
	int s[] = { 1,2,3,4,5,6,7,8,0 }; /* 0Ϊ������� */
	create_list(&head, s); /* ���������� */
	p = head;
	while (p)
	{
		printf("%d\t", p->data); /* ����������ֵ */
		p = p->next; /*����ָ��pָ����һ��� */
	}
	printf("\n");
}
void create_list(struct s_list **headp, int *p)
{
	struct s_list * loc_head = NULL, *tail;
	if (p[0] == 0) /* �൱��*p==0 */
		;
	else { /* loc_headָ��̬����ĵ�һ����� */
		loc_head = (struct s_list *)malloc(sizeof(struct s_list));
		loc_head->data = *p++; /* ��������ֵ */
		tail = loc_head; /* tailָ���һ����� */
		while (*p) { /* tail��ָ����ָ����ָ��̬�����Ľ�� */
			tail->next = (struct s_list *)malloc(sizeof(struct s_list));
			tail = tail->next; /* tailָ���´����Ľ�� */
			tail->data = *p++; /* ���´����Ľ���������ֵ */
		}
		tail->next = NULL; /* ��ָ����NULLֵ */
	}
	*headp = loc_head; /* ʹԭ����ͷָ��headָ���´��������� */
}