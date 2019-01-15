#include <stdio.h>
#define SUM (a+b)       //之后的SUM都会被(a+b)代替
#define DIF (a-b)       //之后的DIF都会被(a-b)代替
#define SWAP(a,b) t=a,a=b,b=t
int main(void)
{
	int a,b,t;
	printf("Input two integers a, b: ");
	scanf("%d %d", &a,&b);
	printf("\nSUM=%d\nthe difference between square of a and square of b is:%d",SUM, SUM*DIF);
	SWAP(a,b);
	printf("\nNow a=%d,b=%d\n",a,b);
	return 0;
}
