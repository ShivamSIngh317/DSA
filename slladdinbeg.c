#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create a new node with given data
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Add node at the end of the list
void addNode(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int value, choice;

    // Step 1: Create the first node
    printf("Enter data for the first node: ");
    scanf("%d", &value);
    struct Node* head = createNode(value);

    // Step 2: Add more nodes after creating the first one
    while (1) {
        printf("Do you want to add another node? (1 = Yes, 0 = No): ");
        scanf("%d", &choice);
        if (choice == 0)
            break;
        printf("Enter data for the new node: ");
        scanf("%d", &value);
        addNode(head, value);
    }

    // Step 3: Display the list
    displayList(head);

    // Free memory
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
