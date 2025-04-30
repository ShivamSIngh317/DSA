#include <stdio.h>
int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = i; j > 0; j--)
        {
            printf(" ");
        }
        for (int j1 = 5-i; j1 > 0; j1--)
        {
            printf("*");
        }
        printf("\n");
    }
return 0;
}