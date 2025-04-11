#include <stdio.h>

int main() {
    int n, i;
    float sum = 0.0, mean;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    float arr[n]; 
    printf("Enter %d numbers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
        sum += arr[i];
    }

    mean = sum / n;
    printf("Mean = %.2f\n", mean);

    return 0;
}
