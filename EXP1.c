#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int count = 0;

struct stack {
    int items[MAX];
    int top;
};

typedef struct stack st;

void createEmptyStack(st *s) {
    s->top = -1;
}

int isfull(st *s) {
    if (s->top == MAX - 1)
        return 1;
    else
        return 0;
}

int isempty(st *s) {
    if (s->top == -1)
        return 1;
    else
        return 0;
}

void push(st *s, int newitem) {
    if (isfull(s)) {
        printf("STACK FULL\n");
    } 
    else {
        s->top++;
        s->items[s->top] = newitem;
        printf("%d pushed into stack\n", newitem);
    }
    count++;
}

void pop(st *s) {
    if (isempty(s)) {
        printf("\nSTACK EMPTY\n");
    } 
    else {
        printf("Item popped = %d\n", s->items[s->top]);
        s->top--;
        count--;
    }
}

void printStack(st *s) {
    printf("Stack: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

int main() {
    int ch, value;
    st *s = (st *)malloc(sizeof(st));
    
    createEmptyStack(s);
    
    do {
        printf("\nStack Operations Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                if (!isfull(s)) {
                    printf("Enter the value to push: ");
                    scanf("%d", &value);
                    push(s, value);
                } else {
                    printf("Stack is full, cannot push more items.\n");
                }
                break;
            case 2:
                pop(s);
                break;
            case 3:
                printStack(s);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (ch != 4);
    
    free(s); 
    return 0;
}

