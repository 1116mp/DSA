#include <stdio.h>
#define SIZE 5

void enQueue(int);
void deQueue();
void display();
int items[SIZE], front = -1, rear = -1;

void enQueue(int value) {
    if (rear == SIZE - 1)
        printf("\nQueue is Full!!\n");
    else {
        if (front == -1)
            front = 0;
        rear++;
        items[rear] = value;
        printf("\nInserted the value %d\n", value);
    }
}

void deQueue() {
    if (front == -1)
        printf("\nQueue is Empty!!\n");
    else {
        printf("\nDeleted: %d\n", items[front]);
        front++;
        if (front > rear)
            front = rear = -1;
    }
}

void display() {
    if (rear == -1)
        printf("\nQueue is Empty!!!\n");
    else {
        int i;
        printf("\nQueue elements are:\n");
        for (i = front; i <= rear; i++)
            printf("%d  ", items[i]);
        printf("\n");
    }
}

int main() {
    int choice, value;
    
    do {
        printf("\nQueue Operations Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enQueue(value);
                break;
            case 2:
                deQueue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
