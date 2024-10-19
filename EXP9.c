#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *left, *right;
};

struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d -> ", root->key);
    inorder(root->right);
  }
}

struct node *insert(struct node *node, int key) {
  if (node == NULL) return newNode(key);

  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

struct node *minValueNode(struct node *node) {
  struct node *current = node;
  while (current && current->left != NULL)
    current = current->left;
  return current;
}

struct node *deleteNode(struct node *root, int key) {
  if (root == NULL) return root;

  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    struct node *temp = minValueNode(root->right);
    root->key = temp->key;
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

int main() {
  struct node *root = NULL;
  int choice, value;

  while (1) {
    printf("\nMenu:\n");
    printf("1. Insert a node\n");
    printf("2. Delete a node\n");
    printf("3. Display in-order traversal\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter value to insert: ");
        scanf("%d", &value);
        root = insert(root, value);
        break;
      case 2:
        printf("Enter value to delete: ");
        scanf("%d", &value);
        root = deleteNode(root, value);
        break;
      case 3:
        printf("In-order traversal: ");
        inorder(root);
        printf("\n");
        break;
      case 4:
        printf("Exiting...\n");
        exit(0);
      default:
        printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}
