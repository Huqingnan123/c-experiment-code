#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])  //argv[]指向字符串
{
	char ch;
	if (argc != 2) {
		printf("Arguments error!\n");
		exit(-1);
	}
	if ((freopen(argv[1], "r",stdin)) == NULL) {         
		printf("Can't open %s file!\n", argv[1]);
		exit(-1);
	}
	while ((ch = getchar()) != EOF)          /* 从filename中读字符 */
		putchar(ch);                  /* 向显示器中写字符 */       
	fclose(stdin);								  /* 关闭filename */
	return 0;
}
