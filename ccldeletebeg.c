#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Create a circular linked list
void createList(int arr[], int n) {
    if (n <= 0) return;

    struct Node* temp;
    struct Node* tail;

    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = arr[0];
    head->next = head;
    tail = head;

    for (int i = 1; i < n; i++) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = arr[i];
        temp->next = head;
        tail->next = temp;
        tail = temp;
    }
}

// Delete the first node
void deleteFirst() {
    if (head == NULL) {
        printf("List is already empty.\n");
        return;
    }

    // Only one node
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    // More than one node
    struct Node* temp = head;
    struct Node* last = head;

    // Find the last node
    while (last->next != head) {
        last = last->next;
    }

    head = head->next;
    last->next = head;
    free(temp);
}

// Display the list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

int main() {
    int n, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("List cannot be created with zero or negative nodes.\n");
        return 0;
    }

    int arr[n];
    printf("Enter %d values:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    createList(arr, n);
    printf("\nBefore deletion:\n");
    display();

    deleteFirst();
    printf("\nAfter deleting the first node:\n");
    display();

    return 0;
}
