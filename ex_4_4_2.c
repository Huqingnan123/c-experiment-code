#include <stdio.h>
#define CHANGE ((c) % 2)     //看首字符的ASCII码是不是偶数
int main(void)
{
	int N, i;
	char c;
	scanf("%d", &N);
	while ((c = getchar()) != '\n')
		continue;
	for (i = 1; i <= N; i++)
	{
		c = getchar();
		if (!CHANGE)    
		{                  //如果是偶数，则change是0，原文输出，但要先把第一个字符输出，再开始循环检索
			putchar(c);
			while ((c = getchar()) != '\n')
				putchar(c);
		}
		else
		{
			if (c >= 65 && c <= 90)
				putchar(c + 32);
			else if (c >= 97 && c <= 122)
				putchar(c - 32);
			else
				putchar(c);                   //先将第一个用于判断的字符按正确形式输出
			while ((c = getchar()) != '\n')
			{
				if (c >= 65 && c <= 90)
					putchar(c + 32);
				else if (c >= 97 && c <= 122)
					putchar(c - 32);
				else
					putchar(c);
			}
		}
		putchar('\n');
	}
	return 0;
}