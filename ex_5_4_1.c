#include <stdio.h>
int main(void)
{
	int i,j,m,n,array1[3][4],array2[4][3];
	for (i = 0; i <= 2; i++)
		for(j=0;j<=3;j++)
			scanf("%d", &array1[i][j]);
	for (i = 0; i <= 2; i++)
		for (j = 0; j <= 3; j++)
		{
			if (j != 3)
				printf("%5d", array1[i][j]);
			else
				printf("%5d\n", array1[i][j]);
		}
	printf("\n");
	for(m=0,j=0;m<=3;m++,j++)       //��ԭ�����ÿһ�ж��ŵ�ÿһ�У�Ҫ�����������
		for (n = 0,i=0; n <= 2; n++,i++)
		{
			array2[m][n] = array1[i][j];
		}
	for (m = 0; m <= 3; m++)
		for (n = 0; n <= 2; n++)
		{
			if (n!= 2)
				printf("%5d", array2[m][n]);
			else
				printf("%5d\n", array2[m][n]);
		}
	return 0;          //˳ʱ����ת��ʮ��
}