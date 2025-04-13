#include <stdio.h>

void rearrangeMaxMin(int arr[], int n) {
    int temp[n]; 
    int left = 0, right = n - 1; 
    int index = 0;

    while (left <= right) {
        if (index % 2 == 0) {
            temp[index++] = arr[right--]; 
        } else {
            temp[index++] = arr[left++]; 
        }
    }

    
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array (sorted in ascending order):\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    rearrangeMaxMin(arr, n);

    printf("Array after rearranging in max-min form:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}