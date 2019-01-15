#include <stdio.h>
#include <string.h>
void SelectionSort(int a[], int n, char name[][100]);
int Findscore(int score[], int n, int score_);
int main(void)
{
	int score[100], i, n;
	char name[100][100];
	scanf("%d", &n);
	for (i = 0; i <= n - 1; i++)
	{
		scanf("%s %d", &name[i][0], &score[i]);
	}
	SelectionSort(score, n, name);
	for (i = 0; i <= n - 1; i++)
		printf("%-20s %d\n", &name[i][0], score[i]);
	printf("\n");
	int score_[100], num, N;        //score_[100]用来存储要查找的分数，N表示要查多少个成绩，num来存储返回值       
	scanf("%d", &N);
	for (i = 0; i <= N - 1; i++)
		scanf("%d", &score_[i]);   //一次性输入要查找的成绩（最多100个）
	for (i = 0; i <= N - 1; i++)
	{
		num = Findscore(score, n, score_[i]);
		if (num == -1)
			printf("Not found!\n");
		else
			printf("%-20s %d\n", &name[num][0], score[num]);
	}
	return 0;
}
void SelectionSort(int a[], int n, char name[][100])             //记住是降序排列！！1
{
	int i;
	for (i = 0; i < n - 1; i++)
	{
		int max = i, j, temp1;
		char temp2[100][100];
		for (j = i + 1; j <= n - 1; j++)
		{
			if (a[j] > a[max])
				max = j;
		}
		temp1 = a[i]; strcpy(&temp2[0][0], &name[i][0]);          //用首地址来作为操作数
		a[i] = a[max]; strcpy(&name[i][0], &name[max][0]);        //字符串不能直接赋值，要一个一个字符复制过去
		a[max] = temp1; strcpy(&name[max][0], &temp2[0][0]);
	}
}
int Findscore(int score[], int n, int score_)     //记住是降序排列！！！(升序则下面的符号相反）
{
	int front = 0, back = n - 1, middle;   //作为下标值
	while (front <= back)
	{
		middle = (front + back) / 2;
		if (score_ < score[middle])
			front = middle + 1;
		else if (score_ > score[middle])
			back = middle - 1;
		else
			return middle;    //找到则返回下标值
	}
	return -1;   //没找到则返回-1
}