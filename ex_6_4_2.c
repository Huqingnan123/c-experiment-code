#include <stdio.h>            //��ҪǶ��ʹ��ͬһ�����������׳���
#include <string.h>           //���뵽��malloc����ռ䣬����һ�����������
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
			p[i] = (char *)malloc(80 * sizeof(char));           //��ָ���������ָ��һһ����ռ�

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
	char news[80];									 //��������µ��ַ��������㣩
	length = strlen(p);
	for (j = 0, flag = 1, count = 0; j <= length - 1; j++)
	{
		if (flag == 0 && isspace(p[j]))              //��ʽ�������㱻���Ե��Ŀո��ַ�����
			count++;
		if (flag == 1 ||(!isspace(p[j])))            //ֻ�е���flagֵΪ1���������ǿո��ַ���ʱ���Ż�����ƣ����������ո�flag�ͱ�Ϊ0
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

