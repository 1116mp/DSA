#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* addToEmpty(struct Node* last, int data) {
    if (last != NULL) return last;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    last = newNode;
    last->next = last;

    return last;
}

struct Node* addFront(struct Node* last, int data) {
    if (last == NULL) return addToEmpty(last, data);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = last->next;
    last->next = newNode;

    return last;
}

struct Node* addEnd(struct Node* last, int data) {
    if (last == NULL) return addToEmpty(last, data);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = last->next;
    last->next = newNode;
    last = newNode;

    return last;
}

struct Node* addAfter(struct Node* last, int data, int item) {
    if (last == NULL) return NULL;

    struct Node* newNode, *p;
    p = last->next;

    do {
        if (p->data == item) {
            newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = data;
            newNode->next = p->next;
            p->next = newNode;

            if (p == last) last = newNode;
            return last;
        }
        p = p->next;
    } while (p != last->next);

    printf("\nThe given node is not present in the list\n");
    return last;
}

void deleteNode(struct Node** last, int key) {
    if (*last == NULL) return;

    if ((*last)->data == key && (*last)->next == *last) {
        free(*last);
        *last = NULL;
        return;
    }

    struct Node *temp = *last, *d;

    if ((*last)->data == key) {
        while (temp->next != *last) temp = temp->next;
        temp->next = (*last)->next;
        free(*last);
        *last = temp;
    }

    while (temp->next != *last && temp->next->data != key) {
        temp = temp->next;
    }

    if (temp->next->data == key) {
        d = temp->next;
        temp->next = d->next;
        free(d);
    }
}

void traverse(struct Node* last) {
    struct Node* p;

    if (last == NULL) {
        printf("The list is empty\n");
        return;
    }

    p = last->next;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != last->next);
    printf("\n");
}

int main() {
    struct Node* last = NULL;
    int choice, data, item;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add to Empty\n");
        printf("2. Add at Front\n");
        printf("3. Add at End\n");
        printf("4. Add After\n");
        printf("5. Delete Node\n");
        printf("6. Traverse List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to add to empty list: ");
                scanf("%d", &data);
                last = addToEmpty(last, data);
                break;

            case 2:
                printf("Enter data to add at front: ");
                scanf("%d", &data);
                last = addFront(last, data);
                break;

            case 3:
                printf("Enter data to add at end: ");
                scanf("%d", &data);
                last = addEnd(last, data);
                break;

            case 4:
                printf("Enter data to add: ");
                scanf("%d", &data);
                printf("Enter the item after which to add: ");
                scanf("%d", &item);
                last = addAfter(last, data, item);
                break;

            case 5:
                printf("Enter data of node to delete: ");
                scanf("%d", &data);
                deleteNode(&last, data);
                break;

            case 6:
                printf("Traversing list: ");
                traverse(last);
                break;

            case 7:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

