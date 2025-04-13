#include <stdio.h>

int sumElements(int matrix[3][3], int row, int col) {
    if (row < 0) {
        return 0; 
    }
    if (col < 0) {
        return sumElements(matrix, row - 1, 2); 
    }
    return matrix[row][col] + sumElements(matrix, row, col - 1); 
}

int main() {
    int matrix[3][3];

    printf("Enter the elements of the 3x3 matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    int totalSum = sumElements(matrix, 2, 2); 
    printf("The sum of all elements in the matrix is: %d\n", totalSum);

    return 0;
}