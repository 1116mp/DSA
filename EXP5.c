#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node Node;

Node* createNode(int value) {
    Node* newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void append(Node **head, int value) {
    Node *newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("\n%d appended to the Linked List", value);
}

void delete(Node **head, int value) {
    Node *temp = *head;
    Node *prev = NULL;

    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        printf("\n%d deleted from the Linked List", value);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\n%d not found in the Linked List", value);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("\n%d deleted from the Linked List", value);
}

void search(Node *head, int value) {
    Node *temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("\n%d is present in the Linked List", value);
            return;
        }
        temp = temp->next;
    }
    printf("\n%d is not present in the Linked List", value);
}

void print_LinkedList(Node *head) {
    if (head == NULL) {
        printf("\nLinked List is empty.");
        return;
    }
    Node *temp = head;
    printf("\nLinked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    int choice, value;

    while (1) {
        printf("\nEnter Your Choice:\n");
        printf("1. Append\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Search\n");
        printf("5. EXIT\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to append: ");
                scanf("%d", &value);
                append(&head, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete(&head, value);
                break;
            case 3:
                print_LinkedList(head);
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(head, value);
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    
    return 0;
}



