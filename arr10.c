#include <stdio.h>

int main() {
    int n, min, pos;

 
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n]; 

    printf("Enter %d numbers:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize min with first element and position as 0
    min = arr[0];
    pos = 0;

    // Find the smallest element and its position
    for(int i = 1; i < n; i++) {
        if(arr[i] < min) {
            min = arr[i];
            pos = i;
        }
    }

    // Display result (position in 1-based index)
    printf("Smallest number is %d at position %d\n", min, pos + 1);

    return 0;
}
