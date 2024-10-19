#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
    printf("Book %d is placed on the stack.\n", value);
}

int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = *top;
    int poppedValue = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedValue;
}

void displayStack(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Current stack of books:\n");
    struct Node* temp = top;
    while (temp != NULL) {
        printf("Book %d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Node* top = NULL;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push a book onto the stack\n");
        printf("2. Pop a book from the stack\n");
        printf("3. Display the current stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the book number to push onto the stack: ");
                scanf("%d", &value);
                push(&top, value);
                break;

            case 2:
                value = pop(&top);
                if (value != -1) {
                    printf("Removed book: %d\n", value);
                }
                break;

            case 3:
                displayStack(top);
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
