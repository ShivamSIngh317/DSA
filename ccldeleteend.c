#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create the circular linked list
void createList(int n) {
    if (n <= 0) return;

    struct Node *newNode, *tail;
    int value;

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->next = head;
            tail = newNode;
        }
    }
}

// Delete the last node
void deleteLast() {
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

    struct Node* current = head;
    struct Node* prev = NULL;

    // Traverse to the last node
    while (current->next != head) {
        prev = current;
        current = current->next;
    }

    prev->next = head;
    free(current);
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
    int n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    createList(n);
    printf("\nBefore deleting last node:\n");
    display();

    deleteLast();
    printf("\nAfter deleting last node:\n");
    display();

    return 0;
}
