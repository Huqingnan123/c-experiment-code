#include <stdio.h>        //ע��i,j��Ҫʱ����������ҪΪ��ʡʱ�����Ƕ����ʹ��ͬһ��ʼ����������
int main(void)
{
	long number;
	int N,i,j;
	scanf("%d", &N);
	for (i = 0; i <= N - 1; i++)
	{
		scanf("%ld", &number);
		char *p = (char *)(&number), *pp = p + 3; //ǿ�ư�x��ַ�����ַ�ָ��p��pһ���ƶ�һ�ֽڣ�pp�ڸ��ֽڴ�
		char up_half, low_half;               
		char mask = 0x0f;                     //ȡ����4λ
		for (j = 0; j < 4; j++)
		{
			low_half = (*pp)&mask;
			if (low_half < 10)
				low_half += '0';                  //��ÿ��λ����ֵ(<10)ת��Ϊ�����ַ�0-9
			else
				low_half = low_half - 10 + 'A';    //��ÿ��λ����ֵ(>10)ת��Ϊ�����ַ�A-F
			up_half = (*pp >> 4)&mask;         //������λ�����λ��ȡ����λ
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