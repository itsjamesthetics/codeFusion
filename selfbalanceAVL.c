/*
    Developed by: James Ald Teves
    BS Computer Science

    Description: An AVL tree program is a data structure implementation that maintains a self-balancing binary search tree.
    It ensures that the height difference between the left and right subtrees of any node is at most one,
    which helps maintain efficient search,insertion, and deletion operations.

    Instrcutor: Dr. Chuchi S. Montenegro
*/

// Preprocessor Directives
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

// Structure Definition of the Node
typedef struct node
{
    int data;
    int height;
    struct node *left;
    struct node *right;
} *ptr;

// Function Prototypes
ptr createNode(int data);
ptr insert(ptr root, int data);
ptr rotateRight(ptr y);
ptr rotateLeft(ptr x);
ptr rotateDouble(ptr z);
int getHeight(ptr node);
int getBalanceFactor(ptr node);
void updateHeight(ptr node);
void displayPreOrder(ptr node);
void displayPostOrder(ptr node);
int treeHeight(ptr node);
int calculateLevel(ptr node, int target, int level);
bool matchNodes(ptr root);

// Main function
int main()
{
    ptr root = NULL;
    int choice, value;

    printf("Welcome to the AVL Tree Program\n\n");
    do
    {
        printf("Select Option:\n");
        printf("1 - Add\n2 - View\n3 - Tree Height\n4 - Node Level\n5 - Match Nodes\n6 - Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to add: ");
            scanf("%d", &value);
            root = insert(root, value);
            printf("Value added.\n");
            getch();
            break;
        case 2:
            printf("Preorder Traversal: ");
            displayPreOrder(root);
            printf("\nPostorder Traversal: ");
            displayPostOrder(root);
            getch();
            printf("\n");
            break;
        case 3:
            printf("Height of the tree: %d\n", treeHeight(root));
            getch();
            break;
        case 4:
            printf("Enter node value to find its level: ");
            scanf("%d", &value);
            printf("Level of node %d is: %d\n", value, calculateLevel(root, value, 1));
            getch();
            break;
        case 5:
            if (matchNodes(root))
            {
                printf("They are parent and child nodes.\n");
                getch();
            }
            else
            {
                printf("They are not parent and child nodes.\n");
                getch();
            }
            break;
        case 6:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid option.\n");
        }
    } while (choice != 6);

    return 0;
}

// Function Definitions

ptr createNode(int data)
{
    ptr newNode = malloc(sizeof(struct node));
    if (newNode)
    {
        newNode->data = data;
        newNode->height = 1; // Initial height set to 1
        newNode->left = newNode->right = NULL;
    }
    return newNode;
}

ptr insert(ptr root, int data)
{
    // Standard BST insertion
    if (!root)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    else
    {
        return root; // Duplicate data not allowed
    }

    // Update height of the current node
    updateHeight(root);

    // Balance the tree
    int balance = getBalanceFactor(root);

    // Left Left Case
    if (balance > 1 && data < root->left->data)
    {
        return rotateRight(root);
    }

    // Right Right Case
    if (balance < -1 && data > root->right->data)
    {
        return rotateLeft(root);
    }

    // Left Right Case
    if (balance > 1 && data > root->left->data)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Right Left Case
    if (balance < -1 && data < root->right->data)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

ptr rotateRight(ptr y)
{
    ptr x = y->left;
    ptr T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    updateHeight(y);
    updateHeight(x);

    return x;
}

ptr rotateLeft(ptr x)
{
    ptr y = x->right;
    ptr T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    updateHeight(x);
    updateHeight(y);

    return y;
}

int getHeight(ptr node)
{
    if (!node)
    {
        return 0;
    }
    return node->height;
}

int getBalanceFactor(ptr node)
{
    if (!node)
    {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

void updateHeight(ptr node)
{
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

void displayPreOrder(ptr node)
{
    if (node)
    {
        printf("%d ", node->data);
        displayPreOrder(node->left);
        displayPreOrder(node->right);
    }
}

void displayPostOrder(ptr node)
{
    if (node)
    {
        displayPostOrder(node->left);
        displayPostOrder(node->right);
        printf("%d ", node->data);
    }
}

int treeHeight(ptr node)
{
    if (!node)
    {
        return 0;
    }
    return node->height;
}

int calculateLevel(ptr node, int target, int level)
{
    if (!node)
    {
        return 0;
    }
    if (node->data == target)
    {
        return level;
    }
    int downlevel = calculateLevel(node->left, target, level + 1);
    if (downlevel != 0)
    {
        return downlevel;
    }
    downlevel = calculateLevel(node->right, target, level + 1);
    return downlevel;
}

bool matchNodes(ptr root)
{
    int parentVal, childVal;
    printf("Enter parent node value: ");
    scanf("%d", &parentVal);
    printf("Enter child node value: ");
    scanf("%d", &childVal);

    while (root)
    {
        if (parentVal == root->data)
        {
            if (root->left && childVal == root->left->data)
            {
                return true;
            }
            if (root->right && childVal == root->right->data)
            {
                return true;
            }
            return false;
        }
        root = (childVal < root->data) ? root->left : root->right;
    }
    return false;
}