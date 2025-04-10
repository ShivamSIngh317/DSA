#include <stdio.h>

int main() {
    int n;

    // Get the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("At least two numbers are required!\n");
        return 0;
    }

    int arr[n];

    // Read elements
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array in descending order (Bubble Sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) { // Swap if the next element is larger
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Find the second largest number (ignoring duplicates)
    int secondLargest = -1;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[0]) {
            secondLargest = arr[i];
            break;
        }
    }

    // Display result
    if (secondLargest == -1) {
        printf("No second largest number found!\n");
    } else {
        printf("The second largest number is %d\n", secondLargest);
    }

    return 0;
}
