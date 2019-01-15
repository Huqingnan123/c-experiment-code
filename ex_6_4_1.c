#include <stdio.h>        //注意i,j必要时就声明，不要为了省时间就在嵌套中使用同一初始变量！！！
int main(void)
{
	long number;
	int N,i,j;
	scanf("%d", &N);
	for (i = 0; i <= N - 1; i++)
	{
		scanf("%ld", &number);
		char *p = (char *)(&number), *pp = p + 3; //强制把x地址赋给字符指针p，p一次移动一字节，pp在高字节处
		char up_half, low_half;               
		char mask = 0x0f;                     //取出低4位
		for (j = 0; j < 4; j++)
		{
			low_half = (*pp)&mask;
			if (low_half < 10)
				low_half += '0';                  //将每四位的数值(<10)转换为数字字符0-9
			else
				low_half = low_half - 10 + 'A';    //将每四位的数值(>10)转换为数字字符A-F
			up_half = (*pp >> 4)&mask;         //将高四位移向低位再取高四位
			if (up_half < 10)
				up_half += '0';
			else
				up_half = up_half - 10 + 'A';
			if (pp != p)
				printf("%c %c ", up_half, low_half);
			else
				printf("%c %c", up_half, low_half);
			pp--;
		}
		putchar('\n');
	}
	return 0;
}