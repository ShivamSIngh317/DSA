#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Create circular linked list
void createList(int n) {
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

// Delete the node after a given value
void deleteAfterValue(int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;

    // Find the node with the given value
    do {
        if (current->data == value) {
            struct Node* toDelete = current->next;

            if (toDelete == head) {
                // Deleting the head
                if (head->next == head) {
                    free(head);
                    head = NULL;
                } else {
                    // Find last node to update its next
                    struct Node* last = head;
                    while (last->next != head) {
                        last = last->next;
                    }
                    head = head->next;
                    current->next = head;
                    last->next = head;
                    free(toDelete);
                }
            } else {
                current->next = toDelete->next;
                free(toDelete);
            }

            printf("Node after value %d deleted.\n", value);
            return;
        }
        current = current->next;
    } while (current != head);

    printf("Value %d not found in the list.\n", value);
}

// Display list
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
    int n, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    createList(n);
    printf("\nList before deletion:\n");
    display();

    printf("\nEnter the value after which you want to delete a node: ");
    scanf("%d", &val);

    deleteAfterValue(val);

    printf("\nList after deletion:\n");
    display();

    return 0;
}
