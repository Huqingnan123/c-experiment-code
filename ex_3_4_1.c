#include <stdio.h>
int Divisor (int m,int n);
int main (void)
{
	int m, n;
	while(scanf("%d %d", &m, &n)&&m!=0)
	{
		Divisor(m, n);
	}
	return 0;
}
int Divisor(int m, int n)
{
	int temp;
	if (m > n)
	{
		temp = m - n;
		Divisor(temp, n);                //一直递归函数更相减损术
	}
	if (m == n)
		printf("the largest divisor number is %d\n\n", m);
	if (m < n)
	{
		temp = n - m;
		Divisor(temp, m);
	}
}
