#include <stdio.h>
long fabonacci(int n);
int main(void)
{
	int i, k;
	long sum = 0, *p = &sum;
	scanf("%d", &k);
	for (i = 1; i <= k; i++)
	{
		sum += fabonacci(i); //函数调用完后光标回到此调用行之前处
		printf("i=%d\tthe sum is %ld\n", i, *p);
	}
	return 0;
}
long fabonacci(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
		return fabonacci(n - 1) + fabonacci(n - 2); //最开始是3，3-2-3-1-3-2,最后返回2
}

