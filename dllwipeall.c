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

void deleteList(struct Node** head_ref) {
    struct Node* ptr = *head_ref;
    struct Node* next;

    while (ptr != NULL) {
        next = ptr->next;
        free(ptr);
        ptr = next;
    }

    *head_ref = NULL;
}

int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);

    printf("Original List:\n");
    printList(head);

    deleteList(&head);

    if (head == NULL) {
        printf("List deleted successfully.\n");
    }

    return 0;
}
