#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure
struct Node {
    char data[100];           // Assuming input is a string
    struct Node* next;
};

int main() {
    char iuser[100];
    printf("Enter a value: ");
    scanf("%s", iuser);  // Read user input (no spaces)

    // Create a new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    strcpy(new_node->data, iuser);
    new_node->next = NULL;

    printf("Node created with data: %s\n", new_node->data);

    // Free the node after use
    free(new_node);
    return 0;
}
