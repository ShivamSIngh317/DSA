#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void addAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void displayList(struct Node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void insertAfterValue(struct Node* head, int target, int value) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with value %d not found.\n", target);
    } else {
        struct Node* newNode = createNode(value);
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Node %d inserted after %d.\n", value, target);
    }
}

int main() {
    struct Node* head = NULL;
    int n, value, target, newValue;

    printf("How many nodes do you want to create? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);
        addAtEnd(&head, value);
    }

    printf("\nBefore insertion:\n");
    displayList(head);

    printf("\nEnter the value of the node after which to insert: ");
    scanf("%d", &target);
    printf("Enter the new value to insert: ");
    scanf("%d", &newValue);

    insertAfterValue(head, target, newValue);

    printf("\nAfter insertion:\n");
    displayList(head);

    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
