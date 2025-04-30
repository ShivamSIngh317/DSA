#include <stdio.h>
int main()
{
    int r1, c1, r2, c2;
    
    printf("\nEnter order of Matrix-A: ");
    scanf("%dx%d", &r1, &c1);

    printf("\nEnter order of Matrix-B: ");
    scanf("%dx%d", &r2, &c2);

    int a[r1][c1], b[r2][c2];

    if (c1 == r2)
    {
        printf("\nMultiplication of Matrix-A and Matrix-B is possible.\n");
        int mul[r1][c2];
        int *ptr1 = &a[0][0], *ptr2 = &b[0][0], *ptr3 = &mul[0][0];
        printf("\nEnter Elements of Matrix-A:\n");

        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                printf("Matrix-A[%d][%d]: ", i, j);
                scanf("%d", &a[i][j]);
            }
        }

        printf("\nEnter Elements of Matrix-B:\n");

        for (int i = 0; i < r2; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                printf("Matrix-B[%d][%d]: ", i, j);
                scanf("%d", &b[i][j]);
            }
        }

        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                *(ptr3 + ((i * c2) + j)) = 0;

                for (int k = 0; k < r2; k++)
                {
                    *(ptr3 + ((i * c2) + j)) += (*(ptr1 + ((i * c1) + k))) * (*(ptr2 + ((k * c2) + j)));
                }
            }
        }

        printf("\nMultiplication of Matrix-A & Matrix-B is:\n\n");

        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                (r1 > c2) ? printf("%d\t\t", mul[i][j]) : printf("%d\t", mul[i][j]);
            }
            printf("\n\n");
        }
    }

    else
    {
        printf("\nThe multiplication of Matrix-A and Matrix-B is not possible.\n\n");
    }

    return 0;
}