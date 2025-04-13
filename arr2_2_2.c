#include <stdio.h>

int main() {
    int arr[2][2][2];

    
    printf("Enter the elements of the 2 * 2 * 2 array:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                printf("Element [%d][%d][%d]: ", i, j, k);
                scanf("%d", &arr[i][j][k]);
            }
        }
    }

    printf("\nThe elements of the 2 * 2 * 2 array are:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                printf("Element [%d][%d][%d]: %d\n", i, j, k, arr[i][j][k]);
            }
        }
    }

    return 0;
}