#include<stdio.h>
#include<string.h>
void MyStrcat(char s[], char t[], int n);
int main(void)
{
	char s[100], t[100];
	int n;
	printf("Input s:\n");
	fgets(s, 100, stdin);
	s[strlen(s) - 1] = s[strlen(s)];    //strlen不算空字符长度，所以数组s里面s[strlen(s)]是空字符，前一个是换行符，将空字符结尾
	printf("Input t:\n");
	fgets(t, 100, stdin);
	t[strlen(t) - 1] = t[strlen(t)];    //将空字符覆盖换行符并结尾
	printf("Input n:\n");
	scanf("%d", &n);
	getchar();
	MyStrcat(s, t, n);
	printf("%s\n", s);
	return 0;
}
void MyStrcat(char s[], char t[], int n)
{
	int len1 = strlen(t);           //除空字符之前的字符个数
	int len2 = strlen(s);
	int i, j;                  
	for (i = len2; i >= n; i--)    //将第n+1个字符之后的字符（带着空字符）都向后移空出位置，并且移的长度是t字符串的长度
		s[i + len1] = s[i];             
	for (i = n , j = 0;j<=len1-1; i++, j++)      //从s字符串的第n+1个字符位置插入t字符串,直到t的空字符之前（不要t的末尾空字符）
		s[i] = t[j];
}
