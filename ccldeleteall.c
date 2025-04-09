#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Create circular linked list by taking input from user
void createList(int n) {
    if (n <= 0) return;

    struct Node *newNode, *tail = NULL;
    int value;

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;

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

// Delete entire circular linked list
void deleteEntireList() {
    if (head == NULL) {
        printf("List is already empty.\n");
        return;
    }

    struct Node* current = head;
    struct Node* temp;

    // Traverse and delete all nodes
    do {
        temp = current->next;
        printf("Deleting node with value %d\n", current->data);
        free(current);
        current = temp;
    } while (current != head);

    head = NULL;
    printf("Entire list deleted successfully.\n");
}

// Display the circular linked list
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

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    createList(n);
    printf("\nList before deletion:\n");
    display();

    printf("\nDeleting the entire list...\n");
    deleteEntireList();

    printf("\nAfter deletion:\n");
    display();

    return 0;
}
