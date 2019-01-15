#include <stdio.h>
void itoa(int n, char s[]);
int main(void)
{
	int n[1024],N,i;      //最多处理1024个整数
	scanf("%d", &N);
	char s[100];
	for(i=0;i<=N-1;i++)
		scanf("%d",&n[i]);
	for (i = 0; i <= N - 1; i++)
	{
		itoa(n[i], s);
		s[32] = '\0';         //32个数字字符之后组装空字符
		printf("%s\n", s);    //将字符数组中的字符串输出
	}
	return 0;
}
void itoa(int n, char s[])
{
	unsigned int mask = (1 << 31),i;      //使最高位为1，其余位是0，然后做与运算，一直保留n的最高位
	for (i = 0; i <= 31; i++)
	{
		if (n&mask)
			s[i] = 1+'0';
		else
			s[i] = 0+'0';
		n <<=1;              //每一次都把最高位存进去，1或0
	}
}