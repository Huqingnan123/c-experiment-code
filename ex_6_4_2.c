#include <stdio.h>            //不要嵌套使用同一个变量，容易出错！
#include <string.h>           //多想到用malloc分配空间，多试一试特殊情况！
#include <stdlib.h>
#include <ctype.h>
void CutdownSpace(char *p);
int main(void)
{
	int i, length, n;
	while (scanf("%d", &n) && n)
	{
		char  *p[100];
		for (i = 0; i <= n - 1; i++)
			p[i] = (char *)malloc(80 * sizeof(char));           //把指针数组里的指针一一分配空间

		getchar();
		for (i = 0; i <= n - 1; i++)
		{
			fgets(p[i], 80, stdin);
			length = strlen(p[i]);
			p[i][length - 1] = p[i][length];
		}
		for (i = 0; i <= n - 1; i++)
			if (*p[i] != '\0')
				CutdownSpace(p[i]);
		putchar('\n');
	}
	return 0;
}
void CutdownSpace(char *p)
{
	int length, j, flag, count;
	char news[80];									 //用来存放新的字符串（方便）
	length = strlen(p);
	for (j = 0, flag = 1, count = 0; j <= length - 1; j++)
	{
		if (flag == 0 && isspace(p[j]))              //此式用来计算被忽略掉的空格字符个数
			count++;
		if (flag == 1 ||(!isspace(p[j])))            //只有当“flag值为1”或“遇到非空格字符”时，才会进复制，并且遇到空格flag就变为0
		{
			if (isspace(p[j]))
			{
				news[j - count] = p[j];
				flag = 0;
			}
			if (!isspace(p[j]))
			{
				news[j - count] = p[j];
				flag = 1;
			}
		}
	}
	news[length-count] = '\0';
	printf("%s\n", news);
}

