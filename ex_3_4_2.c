#include <stdio.h>
int Pri(int x);
int main(void)
{
	int BEGIN, END;
	int i, k;
	printf("GOLDBACH'S CONJECTURE\nEvery even number n>=4 is the sum of two primes\n");
	while (scanf("%d %d", &BEGIN, &END) && BEGIN != 0)
	{
		if (BEGIN % 2 != 0)
			BEGIN++;                //ÊÇÅ¼ÊýÊä³ö
		for (i = BEGIN; i <= END; i += 2)
		{
			for (k = 2; k <= i; k++)
			{
				Pri(k);
				Pri(i - k);
				if (Pri(k) == 1 && Pri(i - k) == 1)
				{
					printf("%d=%d+%d\n", i, k, i - k);
					break;
				}
				else
					continue;
			}
		}
		printf("\n");
	}
	return 0;
}
int Pri(int x)
{
	int i;
	for (i = 2; i <= x; i++)
	{
		if (i >= x)
			return 1;
		if (x%i != 0)
			continue;
		else
			break;
	}
}