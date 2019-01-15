#include <stdio.h>
#include <assert.h>
#define  R
int integer_fraction(double x);
int main(void)
{
	double r, s;
	int s_integer = 0;
	printf("input a number: ");
	scanf("%lf", &r);
#ifdef  R
	s = 3.14159*r*r;
	printf("area of round is: %lf\n", s);
	s_integer = integer_fraction(s);
	printf("the integer fraction of area is %d\n", s_integer);
	assert((s - s_integer) < 1.0);
#endif
}

int integer_fraction(double x)     //x值为7.0685774999999991
{
	int i = x;
	return i;     //此时会突变为7
}
