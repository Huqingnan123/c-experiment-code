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
	int s[] = { 1,2,3,4,5,6,7,8,0 }; /* 0为结束标记 */
	create_list(&head, s); /* 创建新链表 */
	p = head; /*遍历指针p指向链头 */
	while (p) {
		printf("%d\t", p->data); 
		p = p->next; /*遍历指针p指向下一结点 */
	}
	printf("\n");
}
void create_list(struct s_list **headp, int *p)
{
	struct s_list * loc_head = NULL, *tail;
	if (p[0] == 0) 
		;
	else {
		tail = (struct s_list *)malloc(sizeof(struct s_list));/*最开始的节点放在末尾*/
		tail->data = *p++; 
		tail->next = NULL; 
		while (*p) { 
			loc_head = (struct s_list *)malloc(sizeof(struct s_list));
			loc_head->next = tail;
			loc_head->data = *p++;
			tail = loc_head;			/*新建节点变为下一个新节点的后一个节点*/
		}
	}
	*headp = loc_head; /* 使头指针headp指向新创建的链表 */
}
