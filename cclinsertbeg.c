#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Head pointer
struct Node* head = NULL;

// Function to create circular linked list from array
void createCircularList(int arr[], int n) {
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

// Add at beginning
void addAtBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

// Display circular list
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
    printf("How many nodes to create initially? ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d values:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Create initial circular list
    createCircularList(arr, n);
    printf("\nInitial ");
    display();

    // Add new node at beginning
    int newVal;
    printf("\nEnter a number to add at the beginning: ");
    scanf("%d", &newVal);
    addAtBeginning(newVal);

    printf("\nAfter adding at beginning ");
    display();

    return 0;
}
