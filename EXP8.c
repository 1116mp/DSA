 #include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct DoublyCircularLinkedList {
    struct Node* head;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

struct DoublyCircularLinkedList* createList() {
    struct DoublyCircularLinkedList* list = (struct DoublyCircularLinkedList*)malloc(sizeof(struct DoublyCircularLinkedList));
    list->head = NULL;
    return list;
}

void insert(struct DoublyCircularLinkedList* list, int data) {
    struct Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        struct Node* tail = list->head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = list->head;
        list->head->prev = newNode;
    }
    printf("%d inserted into the list.\n", data);
}

void display(struct DoublyCircularLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* current = list->head;
    printf("List: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != list->head);
    printf("\n");
}

void deleteNode(struct DoublyCircularLinkedList* list, int key) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* current = list->head;
    do {
        if (current->data == key) {
            if (current->next == current) { 
                free(current);
                list->head = NULL;
            } else { 
                current->prev->next = current->next;
                current->next->prev = current->prev;
                if (current == list->head) { 
                    list->head = current->next;
                }
                free(current);
            }
            printf("Node %d deleted from the list.\n", key);
            return;
        }
        current = current->next;
    } while (current != list->head);
    printf("Node %d not found in the list.\n", key);
}

int main() {
    struct DoublyCircularLinkedList* dcll = createList();
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(dcll, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(dcll, value);
                break;
            case 3:
                display(dcll);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}







