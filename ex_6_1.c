#include <stdio.h>
int main(void)      
{
	float a,*p=&a;   //��Ӧ����һ������ָ��
	scanf("%f", p);
	printf("%f\n", *p);  //*p��Ӧ�ľ��Ǳ���a��ֵ
	return 0;
}