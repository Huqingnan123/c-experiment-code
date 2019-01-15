#include <stdio.h>
char u[] = "UVWXYZ";
char v[] = "xyz";
struct T {
	int x;
	char c;
	char *t;
}a[] = { {11,'A',u},{100,'B',v} }, *p = a;
int main(void)
{
	printf("%d\n", (++p)->x); p = a;
	printf("%c\n", (p++,p->c)); p = a;
	printf("%c\n",(*p++->t,*p->t)); p = a;
	printf("%c\n", *(++p)->t); p = a;
	printf("%c\n", *++p->t); p = a; p->t--;  //再把t所指的位置返回去
	printf("%c\n", ++*p->t); p = a;
	return 0;
}