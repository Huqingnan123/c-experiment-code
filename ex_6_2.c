#include "stdio.h"
#include "string.h"
int main(void)       //����ֵӦ����int����
{
	char * (*p)(char a[],char b[]);    //���庯��ָ��(��ָ�ĺ���������char���͵Ĳ���,����ֵҲ���ַ�ָ��char *
	char a[80], b[80], c[160], *result = c;   //��c������׵�ַ
	int choice, i;   
	do {
		printf("\t\t1 copy string.\n");
		printf("\t\t2 connect string.\n");
		printf("\t\t3 exit.\n");
		printf("\t\tInput a number (1-3) please!\n");
		scanf("%d", &choice);
	} while (choice < 1 || choice>3);
	switch (choice) {
	case 1:
		p = strcpy;
		break;
	case 2:
		p = strcat;
		break;
	case 3:
		goto down;
	}
	while (getchar() != '\n')
		continue;
	printf("input the first string please!\n");
	i = 0;
	while ((a[i] = getchar()) != '\n')
		i++;
	a[i] = '\0';
	printf("input the second string please!\n");
	i = 0;
	while ((b[i] = getchar()) != '\n')
		i++;
	b[i] = '\0';
	result = p(a, b);   //p����һ������ָ������ָ��һ������������ָ�뷵��ֵ��resultָ�룬ָ��C���飬���д洢
	printf("the result is %s\n", result);
	down:
		;
	return 0;
}
