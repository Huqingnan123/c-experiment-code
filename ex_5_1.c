#include<stdio.h>
void sort(int[], int);    //声明原型应在main函数之前
int main(void)
{
	int a[10] = { 27, 13, 5, 32, 23, 3, 17, 43, 55, 39 };
	int i;
	sort(a, 10);     //操作对象应该是a，数组名
	for (i = 0; i < 10; i++)
		printf("%6d", a[i]);
	printf("\n");
	return 0;
}
void sort(int b[], int n)
{
	int i, j, t;
	for (i = 0; i < n - 1; i++)         //n个数只需进行n-1轮比较，每一轮都把未排序序列中最大的数放在最后面
		for (j = 0; j < n - i - 1; j++)
			if (b[j] > b[j + 1])             //依次两个两个比过去，应该把小的放在前面，大的放在后面
				t = b[j], b[j] = b[j + 1], b[j + 1] = t;      //交换位置
}
