#include <stdio.h>
#include <ctype.h>
#define N 31                              //(整数加小数加小数点)本题应该确定是20位整数和十位小数
int main(void)
{
	int num1[N], num2[N], Addnum[N + 1];
	int i, carry = 0,flag=0;                     //carry记住进位数
	for (i = 0; i <= N; i++)
		*(Addnum + i) = 0;                //将和数组清零（0）
	for (i = N - 1; i > 10 && isdigit(*(num1 + i) = getchar()); i--)
	{
		*(num1 + i) -= '0';
	}  
	*(num1 + 10) = getchar();             //读取小数点
	for (i = 9; i >= 0 && isdigit(*(num1 + i) = getchar()); i--)
	{
		*(num1 + i) -= '0';
	}
	getchar();                            //吃掉回车（防止对num2循环造成影响）
	for (i = N - 1; i > 10 && isdigit(*(num2 + i) = getchar()); i--)
	{
		*(num2 + i) -= '0';
	}
	*(num2 + 10) = getchar();             
	for (i = 9; i >= 0 && isdigit(*(num2 + i) = getchar()); i--)
	{
		*(num2 + i) -= '0';               //将读取的数字字符全部转换为十进制数字运算
	}

	for (i = 0; i <= N - 1; i++)
	{
		if (i == 10)
			*(Addnum+10)='.';             //小数点不参与加减法计算
		else
		{
			*(Addnum + i) = *(num1 + i) + *(num2 + i) + carry;
			carry = *(Addnum + i) / 10;   //记住进位
			*(Addnum + i) = *(Addnum + i) % 10;    
			*(Addnum + i) += '0';         //和数组该位上实际记的数转换为字符
		}
	}
	*(Addnum + N) = carry + '0';          //和数组里每一位又重新都变为字符来输出
	for (i = N; i >= 0; i--)
	{
		if (flag==0&&*(Addnum + i) != '0')
			flag=1;                      //前导0跳过不输出
		if(flag==1)
			putchar(*(Addnum + i));
	}
	putchar('\n');
	return 0;
}
