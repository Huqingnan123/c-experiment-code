#include <stdio.h>
#include <string.h>
int main(void)
{
	int i;
	char *(*p[2])(const char*, const char*);    //ע����const����
	p[0] = strstr;       //���ص�����s1�е�һ�γ���s2�Ӵ���λ��
	p[1] = strpbrk;      //���ص���s1�е�һ����s2��Ҳ���ڵ��ַ���λ��
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