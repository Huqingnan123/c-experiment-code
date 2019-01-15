#include <stdio.h>
int main(int argc,char* argv[])
{
	int i = 0,flag=0;
	FILE *fp;
	char string[100];
	gets_s(string, 99);
	while (string[i] != '\0')
	{
		if (flag == 0)
		{
			if (string[i] >= 97 && string[i] <= 122)
				string[i] -= 32;
			flag = 1;
		}
		if (string[i] == ' ')
		{
			flag = 0;
		}
		if (flag == 1 && string[i] != ' ')
			;
		i++;
	}
	if((fp = fopen(argv[1], "w"))!=NULL)
		fprintf(fp, "%s", string);
	return 0;

}