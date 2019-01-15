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
	struct stu_info *next;
};
typedef struct stu_info Stu_info;
Stu_info *Input(void);
void Output(Stu_info *p);
void Modify(char *p, Stu_info *head);
void Cal_avg(Stu_info *p);
void Output_r(Stu_info *p);
Stu_info * SelectSort(Stu_info *p);
int main(void)
{
	char temp[12];
	Stu_info *head = NULL,*newhead;
	head = Input();
	Output(head);
	Cal_avg(head);
	Output_r(head);
	newhead=SelectSort(head);
	printf("Please input an student's ID and modify his information:");
	gets_s(temp, 11);
	Modify(temp, newhead);
	return 0;
}
Stu_info *Input(void)
{
	Stu_info *head = NULL, *prev, *current, student;
	while (gets_s(student.ID, 11) != NULL && student.ID[0] != '\0')
	{
		current = (Stu_info *)malloc(sizeof(Stu_info));
		if (head == NULL)
			head = current;
		else
			prev->next = current;
		current->next = NULL;
		strcpy(current->ID, student.ID);
		printf("Please input this student's name:");
		gets_s(current->name, 19);
		printf("Please input this student's scores:");
		scanf("%d %d %d %d", &current->English, &current->math, &current->physics, &current->C_program);
		getchar();
		prev = current;
	}
	putchar('\n');
	return head;
}
void Output(Stu_info *p)
{
	printf("This is students' information: \n");
	while (p)
	{
		printf("%s %s %d %d %d %d\n", p->ID, p->name, p->English, p->math, p->physics, p->C_program);
		p = p->next;
	}
	putchar('\n');
}
void Modify(char *s, Stu_info *p)
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
	putchar('\n');
}
Stu_info * SelectSort(Stu_info *p)  /*ѡ�� (��ָ�������������*/
{
	Stu_info *p1, *p2, *prev, *minprev, *tail, *newhead;   /*��һ��֮��tailָ�����ź����нڵ�����һ���ڵ�*/
	int length = 0, i, j;
	p1 = p;
	while (p1)
	{
		length++;
		p1 = p1->next;        /*����ڵ����*/
	}
	for (i = 0, p1 = p, tail = p; i <= length - 2; i++, p1 = tail->next)    /*p1��δ����ĵ�һ���ڵ㣬p2�ǵڶ���*/
	{
		Stu_info *min = p1, *temp;
		for (j = i + 1, p2 = p1->next, prev = p1, minprev = tail; j <= length - 1; j++, prev = p2, p2 = p2->next)      //��prev����ס��ǰ�ڵ����һ�ڵ�
		{
			if (p2->average < min->average)
			{
				min = p2;
				minprev = prev;       //����ǵ���С�ڵ����һ�ڵ�Ҳ���
			}
		}
		if (i == 0 && min == p1)
		{
			tail = p1;
			newhead = p1;
		}
		if (i == 0 && min != p1)
		{
			minprev->next = min->next;    //��min�ڵ��ǰһ��ֱ��ָ���һ��
			temp = tail;
			tail = min;                   //��tailָ������ź����min�ڵ�
			min->next = temp;       //����min->nextָ��ԭ��tailָ���δ�����
			newhead = min;
		}
		if (i != 0)
		{
			minprev->next = min->next;
			temp = tail->next;
			tail->next = min;
			min->next = temp;
		}
	}
	Output(newhead);    /*�������������*/
	return newhead;
}