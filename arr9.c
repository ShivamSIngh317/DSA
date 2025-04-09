#include <stdio.h>

int main() {
    int n, isDuplicate = 0;

    // Get the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Read elements
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Check for duplicates using nested loops
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = 1; // Duplicate found
                break;
            }
        }
        if (isDuplicate) break;
    }

    // Display result
    if (isDuplicate) {
        printf("Array contains duplicate numbers.\n");
    } else {
        printf("Array does not contain duplicate numbers.\n");
    }

    return 0;
}
