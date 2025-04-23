#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void reverseList(struct Node** head_ref) {
    struct Node* prev = NULL;
    struct Node* ptr = *head_ref;
    struct Node* next = NULL;

    while (ptr != NULL) {
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }

    *head_ref = prev;
}

int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    printf("Original List:\n");
    printList(head);

    reverseList(&head);

    printf("Reversed List:\n");
    printList(head);

    return 0;
}
