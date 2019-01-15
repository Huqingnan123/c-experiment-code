#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stu_info {
	char ID[12];
	char name[20];
	int English;
	int math;
	int physics;
	int C_program;
	double average;
	double allscore;
	struct stu_info *prior;
	struct stu_info *next;
};
typedef struct stu_info Stu_info;
void Input(Stu_info **head,Stu_info **prev);         /*传入指针地址对指针进行改变*/
void Output(Stu_info *p);
void Modify(char *p, Stu_info *head);
void Cal_avg(Stu_info *p);
void Output_r(Stu_info *p);
int main(void)
{
	char temp[12];
	Stu_info *head = NULL,*prev=NULL;    /*通过传头和尾的地址进行直接操作*/
	Input(&head,&prev);
	Output(prev);
	printf("Please input an student's ID and modify his information:");
	gets_s(temp, 11);
	Modify(temp, head);
	Cal_avg(head);
	Output_r(head);
	return 0;
}
void Input(Stu_info **head, Stu_info **prev)
{
	Stu_info *current, student;
	while (gets_s(student.ID, 11) != NULL && student.ID[0] != '\0')
	{
		current = (Stu_info *)malloc(sizeof(Stu_info));
		if (*head == NULL)                /*因为头指针只是指向了第一个节点，不存在双向，单独考虑*/
		{
			*head = current;
			current->next = NULL;
			current->prior=NULL;
			strcpy(current->ID, student.ID);
			printf("Please input this student's name:");
			gets_s(current->name, 19);
			printf("Please input this student's scores:");
			scanf("%d %d %d %d", &current->English, &current->math, &current->physics, &current->C_program);
			getchar();
			*prev = current;
		}
		else                         /*后续节点双向连接*/
		{
			current->prior = *prev;
			(*prev)->next = current;
			current->next = NULL;
			strcpy(current->ID, student.ID);
			printf("Please input this student's name:");
			gets_s(current->name, 19);
			printf("Please input this student's scores:");
			scanf("%d %d %d %d", &current->English, &current->math, &current->physics, &current->C_program);
			getchar();
			*prev = current;
		}
	}
	putchar('\n');
}
void Output(Stu_info *p1)        /*借用双向链表特性，逆向输出*/
{
	printf("This is students'information: \n");
	while (p1)
	{
		printf("%s %s %d %d %d %d\n", p1->ID, p1->name, p1->English, p1->math, p1->physics, p1->C_program);
		p1 = p1->prior;
	} 
	putchar('\n');
}
void Modify(char *s, Stu_info *p)                /*查找ID，进行修改信息*/
{
	while (p)
	{
		if (strcmp(p->ID, s) == 0)
		{
			p->English = 100;
			printf("This student's information is changed in:%s %s %d %d %d %d\n", p->ID, p->name, p->English, p->math, p->physics, p->C_program);
			break;
		}
		else
			p = p->next;
	}
	putchar('\n');
}
void Cal_avg(Stu_info *p)
{
	while (p)
	{
		double add = 0;
		add = p->English + p->math + p->physics + p->C_program;
		p->average = add / 4;
		printf("The student whose ID is %s gets average:%.2lf\n", p->ID, p->average);
		p = p->next;
	}
	putchar('\n');
}
void Output_r(Stu_info *p)
{
	while (p)
	{
		double add = 0;
		add = p->English + p->math + p->physics + p->C_program;
		p->allscore = add;
		printf("%s %s all:%.2lf average:%.2lf\n", p->ID, p->name, p->allscore, p->average);
		p = p->next;
	}
}