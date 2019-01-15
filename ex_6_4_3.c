#include <stdio.h>
#include <string.h>
#define N 5       //ѧ������
#define M 5       //�γ���Ŀ
double StudentAverage(int *p,char *pf);                 
double SubjectAverage(int (*p)[M], int i,char *pf);       //(*p)[M]������������p[][M]�ȼۣ�ָ��ָ�����һ�����飩
int Caculaterlower_average(int p[][M], int i, double add2, char *pf);
int Caculatebest(int p[][M], int i, char *pf);
int Caculatelowest(int p[][M], int i, char *pf);
int main(void)
{
	int StudentScore[N][M], i, j,number1;
	double add1, add2[M];
	char NameSubject[M][20],Studentname[N][100];
	for (i = 0; i <= M - 1; i++)
	{
		scanf("%s", NameSubject[i]);
	}
	for (i = 0; i <= N - 1; i++)
	{
		scanf("%s", Studentname[i]);
		getchar();
		for (j = 0; j <= M - 1; j++)
			scanf("%d", &StudentScore[i][j]);
	}
	for (i = 0; i <= N - 1; i++)
		add1 = StudentAverage(StudentScore[i],Studentname[i]);        //��ͬһ��ͬѧ�����з�������
	for (i = 0; i <= M - 1; i++)                //��ͬһ�ſ�Ŀ�Ĳ�ͬͬѧ�ķ�������
		add2[i] = SubjectAverage(StudentScore, i,NameSubject[i]);
	for (i = 0; i <= M - 1; i++)
		number1 = Caculaterlower_average(StudentScore, i, add2[i], NameSubject[i]);
	for (i = 0; i <= M - 1; i++)
		Caculatelowest(StudentScore, i, NameSubject[i]);
	for (i = 0; i <= M - 1; i++)
		Caculatebest(StudentScore, i, NameSubject[i]);
	return 0;
}
double StudentAverage(int *p,char *pf)
{
	double add1 = 0;
	int i;
	for (i = 0; i <= M - 1; i++)
		add1 += *(p + i);
	add1 /= M;
	printf("Average score of %s is %.2f\n",pf,add1);
	return add1;
}
double SubjectAverage(int(*p)[M], int i,char *pf)       //Ϊָ��pָ��ķ���ռ䣬������iָ�Եڼ��ſ�Ŀ����
{
	double add2 = 0;
	int j;
	for (j = 0; j <= N - 1; j++)
		add2 += *(*(p + j) + i);
	add2 /= N;
	printf("Average score of %s is %.2f\n",pf,add2);
	return add2;
}
int Caculaterlower_average(int p[][M], int i, double add2,char *pf)   //i��ʾ��һ�ſ�
{
	int j,number1 = 0;
	for (j = 0; j <= N - 1; j++)
	{
		if (*(*(p + j) + i) < add2)
			number1++;
	}
	printf("Number of students lower than avg of %s is %d\n",pf,number1);
	return number1;
}
int Caculatelowest(int p[][M], int i,char *pf)
{
	int j, number3_lowest = 0;
	for (j = 0; j <= N - 1; j++)
	{
		if (*(*(p + j) + i) < 60)
			number3_lowest++;
	}
	printf("Number of students %s fail is %d\n",pf, number3_lowest);
	return number3_lowest;
}
int Caculatebest(int p[][M], int i, char *pf)
{
	int j,number2_best = 0;
	for (j = 0; j <= N - 1; j++)
	{
		if (*(*(p + j) + i) >= 90)
			number2_best++;
	}
	printf("Number of students %s perfect is %d\n", pf, number2_best);
	return number2_best;
}