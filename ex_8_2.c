#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])  //argv[]ָ���ַ���
{
	char ch;
	if (argc != 2) {
		printf("Arguments error!\n");
		exit(-1);
	}
	if ((freopen(argv[1], "r",stdin)) == NULL) {         
		printf("Can't open %s file!\n", argv[1]);
		exit(-1);
	}
	while ((ch = getchar()) != EOF)          /* ��filename�ж��ַ� */
		putchar(ch);                  /* ����ʾ����д�ַ� */       
	fclose(stdin);								  /* �ر�filename */
	return 0;
}
