#include <stdio.h>
void printReverse(int arr[], int i) 
{
    if (i < 0)
    return;
    printf("%d ", arr[i]);          
    printReverse(arr, i - 1);       
}
int main() 
{
    int arr[100], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);
    printf("Array in reverse order:\n");
    printReverse(arr, n - 1); 
    return 0;
}