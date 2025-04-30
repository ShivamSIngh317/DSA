#include <stdio.h>
int main()
{
    int r, c;
    printf("\nEnter rows and columns of array rowsxcolumns: ");
    scanf("%dx%d", &r, &c);
    int arr[r][c], count = 0;
    printf("\nEnter elements of array:\n");

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
            if (arr[i][j] != 0)
            {
                count++;
            }
        }
    }

    printf("\nThe no. of non-zero elements in the entered 2D array is -> %d\n\n", count);
    return 0;
}