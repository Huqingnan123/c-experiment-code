#include <stdio.h>
int bitcount(int a);
int main(void)
{
    int number;
    while (scanf("%d", &number) == 1)
    {
        printf("%d\n", bitcount(number));
    }
    return 0;
}
int bitcount(int a)
{
    a = (a & 0x55555555) + ((a >> 1) & 0x55555555);
    a = (a & 0x33333333) + ((a >> 2) & 0x33333333);
    a = (a & 0x0F0F0F0F) + ((a >> 4) & 0x0F0F0F0F);
    a = (a & 0x00FF00FF) + ((a >> 8) & 0x00FF00FF);
    a = (a & 0x0000FFFF) + ((a >> 16) & 0x0000FFFF);
    return a;
}