#include <stdio.h>
#include <stdlib.h>


void push(int stack[], int *top, int size, int value) {
    if (*top == size - 1) {
        printf("Stack Overflow\n");
    } else {
        (*top)++;
        stack[*top] = value;
        printf("%d pushed into stack\n", value);
    }
}


void pop(int stack[], int *top) {
    if (*top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d popped from stack\n", stack[*top]);
        (*top)--;
    }
}


void peek(int stack[], int top) {
    if (top == -1) {
        printf("Stack is Empty\n");
    } else {
        printf("Top element is %d\n", stack[top]);
    }
}

void display(int stack[], int top) {
    if (top == -1) {
        printf("Stack is Empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}


int main() {
    int stack[100];
    int top = -1;
    int choice, value;

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n 2. Pop\n 3. Peek\n 4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(stack, &top, 100, value);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                peek(stack, top);
                break;
            case 4:
                display(stack, top);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
