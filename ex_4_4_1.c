#include <stdio.h>
#include <math.h>
#define AVERAGE(x,y,z) ((x)+(y)+(z))/2.0
#define CACULATOR(s,a,b,c) sqrt((s)*(s-a)*(s-b)*(s-c))
int main(void)
{
	double s, a, b, c, area;
	while (scanf("%lf %lf %lf", &a, &b, &c) == 3)
	{
		s = AVERAGE(a, b, c);
		area = CACULATOR(s, a, b, c);
		printf("%.0lf %lf\n",s, area);
	}
	return 0;
}