#include <stdio.h>
#include <ctype.h>
#define N 31                              //(������С����С����)����Ӧ��ȷ����20λ������ʮλС��
int main(void)
{
	int num1[N], num2[N], Addnum[N + 1];
	int i, carry = 0,flag=0;                     //carry��ס��λ��
	for (i = 0; i <= N; i++)
		*(Addnum + i) = 0;                //�����������㣨0��
	for (i = N - 1; i > 10 && isdigit(*(num1 + i) = getchar()); i--)
	{
		*(num1 + i) -= '0';
	}  
	*(num1 + 10) = getchar();             //��ȡС����
	for (i = 9; i >= 0 && isdigit(*(num1 + i) = getchar()); i--)
	{
		*(num1 + i) -= '0';
	}
	getchar();                            //�Ե��س�����ֹ��num2ѭ�����Ӱ�죩
	for (i = N - 1; i > 10 && isdigit(*(num2 + i) = getchar()); i--)
	{
		*(num2 + i) -= '0';
	}
	*(num2 + 10) = getchar();             
	for (i = 9; i >= 0 && isdigit(*(num2 + i) = getchar()); i--)
	{
		*(num2 + i) -= '0';               //����ȡ�������ַ�ȫ��ת��Ϊʮ������������
	}

	for (i = 0; i <= N - 1; i++)
	{
		if (i == 10)
			*(Addnum+10)='.';             //С���㲻����Ӽ�������
		else
		{
			*(Addnum + i) = *(num1 + i) + *(num2 + i) + carry;
			carry = *(Addnum + i) / 10;   //��ס��λ
			*(Addnum + i) = *(Addnum + i) % 10;    
			*(Addnum + i) += '0';         //�������λ��ʵ�ʼǵ���ת��Ϊ�ַ�
		}
	}
	*(Addnum + N) = carry + '0';          //��������ÿһλ�����¶���Ϊ�ַ������
	for (i = N; i >= 0; i--)
	{
		if (flag==0&&*(Addnum + i) != '0')
			flag=1;                      //ǰ��0���������
		if(flag==1)
			putchar(*(Addnum + i));
	}
	putchar('\n');
	return 0;
}
