#include <stdio.h>
int main(void)      
{
	float a,*p=&a;   //不应该是一个悬挂指针
	scanf("%f", p);
	printf("%f\n", *p);  //*p对应的就是变量a的值
	return 0;
}