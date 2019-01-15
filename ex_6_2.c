#include "stdio.h"
#include "string.h"
int main(void)       //返回值应该是int类型
{
	char * (*p)(char a[],char b[]);    //定义函数指针(且指的函数有两个char类型的参数,返回值也是字符指针char *
	char a[80], b[80], c[160], *result = c;   //是c数组的首地址
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
	result = p(a, b);   //p就是一个函数指针名，指向一个函数，函数指针返回值是result指针，指向C数组，进行存储
	printf("the result is %s\n", result);
	down:
		;
	return 0;
}
