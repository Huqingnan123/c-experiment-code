#include <stdio.h>
#include <string.h>
int main(void)
{
	int i;
	char *(*p[2])(const char*, const char*);    //注意是const类型
	p[0] = strstr;       //返回的是在s1中第一次出现s2子串的位置
	p[1] = strpbrk;      //返回的是s1中第一个在s2中也存在的字符的位置
	char s1[100], s2[100], *p1 , *p2 ;
	printf("Input the first string please!\n");
	i = 0;
	while ((s1[i] = getchar()) != '\n')
		i++;
	s1[i] = '\0';
	printf("Input the second string please!\n");
	i = 0;
	while ((s2[i] = getchar()) != '\n')
		i++;
	s2[i] = '\0';
	p1 = p[0](s1, s2);
	p2 = p[1](s1, s2);
	printf("%p\n",p1);
	printf("%p\n",p2);
	return 0;
}