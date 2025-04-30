#include <stdio.h>
int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j1 = 4-i; j1 > 0; j1--)
        {
            printf(" ");
        }
        for (int j = 0; j < ((2*i)+1); j++)
        {
            printf("*");
        }
        for (int j1 = 4-i; j1 > 0; j1--)
        {
            printf(" ");
        }
        printf("\n");
    }
return 0;
}