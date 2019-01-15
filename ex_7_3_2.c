#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stu_info {
	char ID[12];
	char name[20];
	float English;
	float math;
	float physics;
	float C_program;
	double average;
	double allscore;
	struct stu_info *next;
};
typedef struct stu_info Stu_info;
Stu_info *Input(void);
void Output(Stu_info *p);
void Modify(char *p,Stu_info *head);
void Cal_avg(Stu_info *p);
void Output_r(Stu_info *p);
int main(void)
{
	char temp[12];
	Stu_info *head=NULL;
	head=Input();
	Output(head);
	printf("Please input an student's ID and modify his information:\n");
	while(gets_s(temp, 11)&&temp[0]!='\0')
		Modify(temp,head);
	Cal_avg(head);
	Output_r(head);
	return 0;
}
Stu_info *Input(void)
{
	Stu_info *head=NULL,*prev, *current, student;
	while (gets_s(student.ID,11)!=NULL&&student.ID[0]!='\0')
	{
		current = (Stu_info *)malloc(sizeof(Stu_info));
		if (head == NULL)
			head = current;
		else
			prev->next = current;
		current->next = NULL;
		strcpy(current->ID,student.ID);
		printf("Please input this student's name:");
		gets_s(current->name,19);
		printf("Please input this student's scores:");
		scanf("%f %f %f %f", &current->English, &current->math, &current->physics, &current->C_program);
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
		printf("%s %s %.2f %.2f %.2f %.2f\n", p->ID, p->name, p->English, p->math, p->physics, p->C_program);
		p = p->next;
	}
	putchar('\n');
}
void Modify(char *s,Stu_info *p)
{
	while (p)
	{
		if (strcmp(p->ID, s) == 0)
		{                 
			p->English = 100;
			printf("This student's information is changed in:%s %s %.2f %.2f %.2f %.2f\n", p->ID, p->name, p->English, p->math, p->physics, p->C_program);
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