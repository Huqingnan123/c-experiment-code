#include <stdio.h>
char *strcpy(char *s, char *t);
int main(void)
{
	char a[40], b[60] = "there is a boat on the lake.";
	printf("%s\n",strcpy(a, b));       //aΪʵ�Σ�֮ǰ���ַ�ָ��s������strcpy�ķ���ֵ
	return 0;
}
char *strcpy(char *s, char *t)
{
	char *p = s;
while ((*s++) = (*t++))
		;
	return (p);           //��ָ�����p����ס����ĳ�ʼλ�ã��������
}