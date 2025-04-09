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

void deleteAfterValue(struct Node* head, int value) {
    struct Node* temp = head;

    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Given node with value %d not found.\n", value);
    } else if (temp->next == NULL) {
        printf("No node exists after the node with value %d.\n", value);
    } else {
        struct Node* toDelete = temp->next;
        temp->next = toDelete->next;
        free(toDelete);
        printf("Node after %d deleted successfully.\n", value);
    }
}

int main() {
    struct Node* head = NULL;
    int n, value, target;

    printf("How many nodes do you want to create? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);
        addAtEnd(&head, value);
    }

    printf("\nBefore deletion:\n");
    displayList(head);

    printf("\nEnter the value of the node after which you want to delete: ");
    scanf("%d", &target);

    deleteAfterValue(head, target);

    printf("\nAfter deletion:\n");
    displayList(head);

    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
