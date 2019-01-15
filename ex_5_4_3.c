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
	int score_[100], num, N;        //score_[100]�����洢Ҫ���ҵķ�����N��ʾҪ����ٸ��ɼ���num���洢����ֵ       
	scanf("%d", &N);
	for (i = 0; i <= N - 1; i++)
		scanf("%d", &score_[i]);   //һ��������Ҫ���ҵĳɼ������100����
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
void SelectionSort(int a[], int n, char name[][100])             //��ס�ǽ������У���1
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
		temp1 = a[i]; strcpy(&temp2[0][0], &name[i][0]);          //���׵�ַ����Ϊ������
		a[i] = a[max]; strcpy(&name[i][0], &name[max][0]);        //�ַ�������ֱ�Ӹ�ֵ��Ҫһ��һ���ַ����ƹ�ȥ
		a[max] = temp1; strcpy(&name[max][0], &temp2[0][0]);
	}
}
int Findscore(int score[], int n, int score_)     //��ס�ǽ������У�����(����������ķ����෴��
{
	int front = 0, back = n - 1, middle;   //��Ϊ�±�ֵ
	while (front <= back)
	{
		middle = (front + back) / 2;
		if (score_ < score[middle])
			front = middle + 1;
		else if (score_ > score[middle])
			back = middle - 1;
		else
			return middle;    //�ҵ��򷵻��±�ֵ
	}
	return -1;   //û�ҵ��򷵻�-1
}