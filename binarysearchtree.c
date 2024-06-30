/*
    Summary: This program enables us to simulate Binary Tree.
    In this program, we are able to Create, Add, Search, & Delete Nodes
    in our Binary Tree.

    Programmed by: James Ald Teves
    BS Computer Science
    Instructor: Assis. Prof. Melody Angelique Rivera

    Started: November 14, 2022
    Ended: November 15, 2022
*/

//  Preprocessor Directives
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

// Define the structure for the binary tree
typedef struct binarytree {
    int data;
    struct binarytree *left;
    struct binarytree *right;
} BinaryTree;

// Function prototypes
void createBinaryTree(BinaryTree **root, int *checkBinary);
BinaryTree *insertNode(BinaryTree *root, int element);
BinaryTree *searchNode(BinaryTree *root, int element);
BinaryTree *deleteNode(BinaryTree *root, int element);
BinaryTree *minValueNode(BinaryTree *node);
void inorderTraversal(BinaryTree *root);
int menu();

// Main function
int main() {
    BinaryTree *root = NULL;
    int checkBinary = 0;
    int choice, element;

    while ((choice = menu()) != 7) {
        switch (choice) {
            case 1:
                createBinaryTree(&root, &checkBinary);
                break;

            case 2:
                if (checkBinary) {
                    printf("Enter the element to insert: ");
                    scanf("%d", &element);
                    root = insertNode(root, element);
                } else {
                    printf("Binary Tree has not been created yet!\n");
                }
                break;

            case 3:
                if (checkBinary) {
                    printf("Enter the element to search: ");
                    scanf("%d", &element);
                    BinaryTree *found = searchNode(root, element);
                    if (found != NULL) {
                        printf("Element %d found in the tree.\n", element);
                    } else {
                        printf("Element %d not found in the tree.\n", element);
                    }
                } else {
                    printf("Binary Tree has not been created yet!\n");
                }
                break;

            case 4:
                // Code for finding min & max values can be added here
                break;

            case 5:
                if (checkBinary) {
                    printf("Enter the element to delete: ");
                    scanf("%d", &element);
                    root = deleteNode(root, element);
                } else {
                    printf("Binary Tree has not been created yet!\n");
                }
                break;

            case 6:
                if (checkBinary) {
                    printf("Inorder Traversal of the Binary Tree:\n");
                    inorderTraversal(root);
                    printf("\n");
                } else {
                    printf("Binary Tree has not been created yet!\n");
                }
                break;

            default:
                printf("Invalid Choice! Please try again.\n");
                break;
        }
    }

    printf("Program Terminated!\n");
    return 0;
}

// Function to create the binary tree
void createBinaryTree(BinaryTree **root, int *checkBinary) {
    char choice;

    if (*checkBinary == 0) {
        printf("Do you want to create a binary tree (Y/N)? ");
        scanf(" %c", &choice);

        if (choice == 'Y' || choice == 'y') {
            *checkBinary = 1;
            *root = NULL;
            printf("Binary Tree has been created.\n");
        } else {
            printf("Binary Tree creation aborted.\n");
        }
    } else {
        printf("Binary Tree is already created.\n");
    }
}

// Function to insert a node in the binary tree
BinaryTree *insertNode(BinaryTree *root, int element) {
    if (root == NULL) {
        BinaryTree *newNode = malloc(sizeof(BinaryTree));
        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            return root;
        }
        newNode->data = element;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (element < root->data) {
        root->left = insertNode(root->left, element);
    } else if (element > root->data) {
        root->right = insertNode(root->right, element);
    } else {
        printf("Element already exists in the tree.\n");
    }

    return root;
}

// Function to search for a node in the binary tree
BinaryTree *searchNode(BinaryTree *root, int element) {
    if (root == NULL) {
        return NULL;
    }

    if (element < root->data) {
        return searchNode(root->left, element);
    } else if (element > root->data) {
        return searchNode(root->right, element);
    } else {
        return root;
    }
}

// Function to find the node with minimum value (used in deleteNode)
BinaryTree *minValueNode(BinaryTree *node) {
    BinaryTree *current = node;

    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}

// Function to delete a node from the binary tree
BinaryTree *deleteNode(BinaryTree *root, int element) {
    if (root == NULL) {
        return root;
    }

    if (element < root->data) {
        root->left = deleteNode(root->left, element);
    } else if (element > root->data) {
        root->right = deleteNode(root->right, element);
    } else {
        if (root->left == NULL) {
            BinaryTree *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            BinaryTree *temp = root->left;
            free(root);
            return temp;
        }

        BinaryTree *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Function for inorder traversal of the binary tree
void inorderTraversal(BinaryTree *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to display the menu and return the user's choice
int menu() {
    int choice;
    printf("\nBinary Tree Operations:\n");
    printf("1. Create the Tree\n");
    printf("2. Add a Node to the Tree\n");
    printf("3. Search for a Value in the Tree\n");
    printf("4. Find the Min & Max Values in the Tree\n");
    printf("5. Delete a Value in the Tree\n");
    printf("6. Display the Values in the Tree\n");
    printf("7. Exit the Program\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}