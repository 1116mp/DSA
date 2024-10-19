#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StudentNode {
    int roll_number;
    char name[50];
    char division[10];
    struct StudentNode *left;
    struct StudentNode *right;
} StudentNode;

StudentNode* createNode(int roll_number, const char* name, const char* division) {
    StudentNode* newNode = (StudentNode*)malloc(sizeof(StudentNode));
    newNode->roll_number = roll_number;
    strcpy(newNode->name, name);
    strcpy(newNode->division, division);
    newNode->left = newNode->right = NULL;
    return newNode;
}

StudentNode* insert(StudentNode* root, int roll_number, const char* name, const char* division) {
    if (root == NULL) {
        return createNode(roll_number, name, division);
    }
    if (roll_number < root->roll_number) {
        root->left = insert(root->left, roll_number, name, division);
    } else {
        root->right = insert(root->right, roll_number, name, division);
    }
    return root;
}

StudentNode* search(StudentNode* root, int roll_number) {
    if (root == NULL || root->roll_number == roll_number) {
        return root;
    }
    if (roll_number < root->roll_number) {
        return search(root->left, roll_number);
    }
    return search(root->right, roll_number);
}

void display(StudentNode* root) {
    if (root != NULL) {
        display(root->left);
        printf("Roll No: %d, Name: %s, Division: %s\n", root->roll_number, root->name, root->division);
        display(root->right);
    }
}

int main() {
    StudentNode* bst = NULL;
    int choice, roll_number;
    char name[50], division[10];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Student Record\n");
        printf("2. Search Student Record\n");
        printf("3. Display All Students\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Roll Number: ");
                scanf("%d", &roll_number);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Division: ");
                scanf("%s", division);
                bst = insert(bst, roll_number, name, division);
                printf("Student record inserted successfully.\n");
                break;

            case 2:
                printf("Enter Roll Number to search: ");
                scanf("%d", &roll_number);
                StudentNode* student = search(bst, roll_number);
                if (student) {
                    printf("Found: Roll No: %d, Name: %s, Division: %s\n", student->roll_number, student->name, student->division);
                } else {
                    printf("Student not found.\n");
                }
                break;

            case 3:
                printf("All student records:\n");
                display(bst);
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

