#include <stdio.h>
#define CHANGE ((c) % 2)     //�����ַ���ASCII���ǲ���ż��
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
		{                  //�����ż������change��0��ԭ���������Ҫ�Ȱѵ�һ���ַ�������ٿ�ʼѭ������
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
				putchar(c);                   //�Ƚ���һ�������жϵ��ַ�����ȷ��ʽ���
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