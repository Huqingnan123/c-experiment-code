#include <stdio.h>
void itoa(int n, char s[]);
int main(void)
{
	int n[1024],N,i;      //��ദ��1024������
	scanf("%d", &N);
	char s[100];
	for(i=0;i<=N-1;i++)
		scanf("%d",&n[i]);
	for (i = 0; i <= N - 1; i++)
	{
		itoa(n[i], s);
		s[32] = '\0';         //32�������ַ�֮����װ���ַ�
		printf("%s\n", s);    //���ַ������е��ַ������
	}
	return 0;
}
void itoa(int n, char s[])
{
	unsigned int mask = (1 << 31),i;      //ʹ���λΪ1������λ��0��Ȼ���������㣬һֱ����n�����λ
	for (i = 0; i <= 31; i++)
	{
		if (n&mask)
			s[i] = 1+'0';
		else
			s[i] = 0+'0';
		n <<=1;              //ÿһ�ζ������λ���ȥ��1��0
	}
}