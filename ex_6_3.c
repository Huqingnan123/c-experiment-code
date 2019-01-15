#include <stdio.h>
char *strcpy(char *s, char *t);
int main(void)
{
	char a[40], b[60] = "there is a boat on the lake.";
	printf("%s\n",strcpy(a, b));       //a为实参，之前用字符指针s来接受strcpy的返回值
	return 0;
}
char *strcpy(char *s, char *t)
{
	char *p = s;
while ((*s++) = (*t++))
		;
	return (p);           //用指针变量p来记住数组的初始位置，方便输出
}