#include<stdio.h>
#include<string.h>
void MyStrcat(char s[], char t[], int n);
int main(void)
{
	char s[100], t[100];
	int n;
	printf("Input s:\n");
	fgets(s, 100, stdin);
	s[strlen(s) - 1] = s[strlen(s)];    //strlen������ַ����ȣ���������s����s[strlen(s)]�ǿ��ַ���ǰһ���ǻ��з��������ַ���β
	printf("Input t:\n");
	fgets(t, 100, stdin);
	t[strlen(t) - 1] = t[strlen(t)];    //�����ַ����ǻ��з�����β
	printf("Input n:\n");
	scanf("%d", &n);
	getchar();
	MyStrcat(s, t, n);
	printf("%s\n", s);
	return 0;
}
void MyStrcat(char s[], char t[], int n)
{
	int len1 = strlen(t);           //�����ַ�֮ǰ���ַ�����
	int len2 = strlen(s);
	int i, j;                  
	for (i = len2; i >= n; i--)    //����n+1���ַ�֮����ַ������ſ��ַ���������ƿճ�λ�ã������Ƶĳ�����t�ַ����ĳ���
		s[i + len1] = s[i];             
	for (i = n , j = 0;j<=len1-1; i++, j++)      //��s�ַ����ĵ�n+1���ַ�λ�ò���t�ַ���,ֱ��t�Ŀ��ַ�֮ǰ����Ҫt��ĩβ���ַ���
		s[i] = t[j];
}
