#include <stdio.h>
struct bits
{
	unsigned int bit0 : 1;
	unsigned int bit1 : 1;
	unsigned int bit2 : 1;
	unsigned int bit3 : 1;
	unsigned int bit4 : 1;
	unsigned int bit5 : 1;
	unsigned int bit6 : 1;
	unsigned int bit7 : 1;
};
union chars
{
	char n;        //八位无符号字节（一个char型）
	struct bits number;
}alpha;
void f0(unsigned int b);
void f1(unsigned int b);
void f2(unsigned int b);
void f3(unsigned int b);
void f4(unsigned int b);
void f5(unsigned int b);
void f6(unsigned int b);
void f7(unsigned int b);
void f0(unsigned int b)
{
	printf("the function 1 is called!%d\n", b);
}
void f1(unsigned int b)
{
	printf("the function 2 is called!%d\n", b);
}
void f2(unsigned int b)
{
	printf("the function 3 is called!%d\n", b);
}
void f3(unsigned int b)
{
	printf("the function 4 is called!%d\n", b);
}
void f4(unsigned int b)
{
	printf("the function 5 is called!%d\n", b);
}
void f5(unsigned int b)
{
	printf("the function 6 is called!%d\n", b);
}
void f6(unsigned int b)
{
	printf("the function 7 is called!%d\n", b);
}
void f7(unsigned int b)
{
	printf("the function 8 is called!%d\n", b);
}
int main(void)
{
	scanf("%c", &alpha);
	void *(*p_fun[8])(unsigned int b);
	p_fun[0] = f0;
	p_fun[1] = f1;
	p_fun[2] = f2;
	p_fun[3] = f3;
	p_fun[4] = f4;
	p_fun[5] = f5;
	p_fun[6] = f6;
	p_fun[7] = f7;
	if (alpha.number.bit0)
		p_fun[0](alpha.number.bit0);   //number.biti是unsigned int型
	if (alpha.number.bit1)
		p_fun[1](alpha.number.bit1); 
	if (alpha.number.bit2)
		p_fun[2](alpha.number.bit2); 
	if (alpha.number.bit3)
		p_fun[3](alpha.number.bit3); 
	if (alpha.number.bit4)
		p_fun[4](alpha.number.bit4); 
	if (alpha.number.bit5)
		p_fun[5](alpha.number.bit5); 
	if (alpha.number.bit6)
		p_fun[6](alpha.number.bit6);
	if (alpha.number.bit7)
		p_fun[7](alpha.number.bit7); 
	return 0;
}
