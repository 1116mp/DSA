#include <stdio.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;

int isFull() {
    if ((front == rear + 1) || (front == 0 && rear == MAX_SIZE - 1))
        return 1;
    return 0;
}

int isEmpty() {
    if (front == -1)
        return 1;
    return 0;
}

void enqueue(int data) {
    if (isFull()) {
        printf("Queue is Full\n");
        return;
    }
    
    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = data;
    printf("Element %d inserted\n", data);
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return -1;
    }
    int data = queue[front];
    
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
    printf("Dequeued element: %d\n", data);
    return data;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue[rear]);
}

int main() {
    int choice, value;

    do {
        printf("\nQueue Operations Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
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

