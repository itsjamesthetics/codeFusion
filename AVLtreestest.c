/*
	Developed by: James Ald Teves
	BS Computer Science
	CompSci 22 - A

	An AVL tree program is a data structure implementation that maintains a self-balancing binary search tree.
	It ensures that the height difference between the left and right subtrees of any node is at most one, which helps maintain efficient search and insertion operations.

	Instrcutor: Dr. Chuchi S. Montenegro
	Program Started: May 19, 2023
	Program Finished: May 23, 2023
*/

// Preprocessor Directives
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>

// Structure Definition of the Node
typedef struct node *nd;
struct node
{

	int data;
	int height;
	nd left;
	nd right;

} NODE;

// Function Declaration
int findNode(nd *root, int searchNode);
int treeHeight(nd node);
int Level(nd node, int target, int level);
void inputAncDec(int *data1, int *data2);
void displayPreOrder(nd node);
void displayPostOrder(nd node);
void displayInOrder(nd node);
bool isAncestor(nd *root, int node1, int node2);
bool findDescendant(nd *root, int Node);
bool isDescendant(nd *root, int node1, int node2);
bool isChildOf(nd *root);
bool isParentOf(nd *root);

// Create Node Function
nd nodeCreation(int data)
{

	nd createNode = malloc(sizeof(NODE));
	createNode->data = data;
	createNode->left = NULL;
	createNode->right = NULL;
	createNode->height = 1;
	return createNode;
}

// Height Function
int getHeight(nd node)
{

	if (node == NULL)
	{
		return 0;
	}
	else
	{
		return node->height;
	}
}

// Balance function
int getBalanceFactor(nd node)
{

	if (node == NULL)
	{
		return 0;
	}
	else
	{
		return getHeight(node->left) - getHeight(node->right);
	}
}

// Update Height Function
void updateHeight(nd node)
{

	int leftHeight = getHeight(node->left);
	int rightHeight = getHeight(node->right);
	node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Right Rotation Function
nd rotateRight(nd y)
{

	nd x = y->left;
	nd T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	updateHeight(y);
	updateHeight(x);
	return x;
}

// Left Rotation Function
nd rotateLeft(nd x)
{

	nd y = x->right;
	nd T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	updateHeight(x);
	updateHeight(y);
	return y;
}

// Double Rotation Functions (left - right, right - left)
nd rotateDouble(nd z)
{

	if (getBalanceFactor(z) > 1 && getBalanceFactor(z->left) < 0)
	{
		z->left = rotateLeft(z->left);
		return rotateRight(z);
	}
	if (getBalanceFactor(z) < -1 && getBalanceFactor(z->right) > 0)
	{
		z->right = rotateRight(z->right);
		return rotateLeft(z);
	}
	return z;
}

// Node Insertion
nd insert(nd root, int data)
{

	// Perform normal BST insertion
	if (root == NULL)
	{
		return nodeCreation(data);
	}
	else if (data < root->data)
	{
		root->left = insert(root->left, data);
	}
	else if (data > root->data)
	{
		root->right = insert(root->right, data);
	}
	else
	{
		// Duplicate keys are not allowed in AVL tree
		printf("\n\t Duplicated Value! Try again... ");
		getch();
		return root;
	}

	// Update the height of the current node
	updateHeight(root);

	// Check the balance factor and perform rotations if needed
	int balanceFactor = getBalanceFactor(root);

	// Left-Left case
	if (balanceFactor > 1 && data < root->left->data)
	{
		return rotateRight(root);
	}

	// Right-Right case
	if (balanceFactor < -1 && data > root->right->data)
	{
		return rotateLeft(root);
	}

	// Left-Right case
	if (balanceFactor > 1 && data > root->left->data)
	{
		root->left = rotateLeft(root->left);
		return rotateRight(root);
	}

	// Right-Left case
	if (balanceFactor < -1 && data < root->right->data)
	{
		root->right = rotateRight(root->right);
		return rotateLeft(root);
	}

	// Double rotation cases
	return rotateDouble(root);
}

// Display in Pre-Order Traversal
void displayPreOrder(nd node)
{
	if (node == NULL)
	{
		return;
	}

	printf("%d, ", node->data);
	displayPreOrder(node->left);
	displayPreOrder(node->right);

	return;
}

// Display in Post-Order Traversal
void displayPostOrder(nd node)
{
	if (node == NULL)
	{
		return;
	}

	displayPostOrder(node->left);
	displayPostOrder(node->right);
	printf("%d, ", node->data);

	return;
}

// Display in In-Order Traversal
void displayInOrder(nd node)
{

	if (node == NULL)
	{
		return;
	}
	else
	{

		displayInOrder(node->left);
		printf("%d, ", node->data);
		displayInOrder(node->right);
	}
}

// getHeight Function
int treeHeight(nd node)
{
	if (node == NULL)
	{
		return 0;
	}
	else
	{
		int leftHeight = treeHeight(node->left);
		int rightHeight = treeHeight(node->right);

		return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
	}
}

// findLevel Function
int Level(nd node, int target, int level)
{
	if (node == NULL)
	{
		return 0;
	}
	else if (node->data == target)
	{
		return level;
	}
	else
	{
		int result = Level(node->left, target, level + 1);
		if (result != 0)
		{
			return result;
		}
		return Level(node->right, target, level + 1);
	}
}

// isDescendant Function
bool isDescendant(nd *root, int node1, int node2)
{

	nd Tree = *root;

	if (Tree != NULL)
	{

		if (Tree->data == node1)
		{
			printf("\n\t The Descendant of Node %d are: ", Tree->data);
			findDescendant(&Tree, node2);
			getch();
			return true;
		}
		else if (Tree->data < node1)
		{
			isDescendant(&Tree->right, node1, node2);
		}
		else if (Tree->data > node1)
		{
			isDescendant(&Tree->left, node1, node2);
		}
	}
}

// Prerequisite Function of Descendant
bool findDescendant(nd *root, int Node)
{

	nd Tree = *root;

	if (Tree == NULL)
	{
		return false;
	}
	if (Tree->left != NULL)
	{
		printf("\n\t %d", Tree->left->data);
		findDescendant(&Tree->left, Node);
	}
	if (Tree->right != NULL)
	{
		printf("\n\t %d", Tree->right->data);
		findDescendant(&Tree->right, Node);
	}
}

// isAncestor Function
bool isAncestor(nd *root, int node1, int node2)
{

	nd Tree = *root;

	if (Tree == NULL)
	{
		return false;
	}
	if (Tree->data == node2)
	{
		return true;
	}
	if (isAncestor(&Tree->left, node1, node2) || isAncestor(&Tree->right, node1, node2))
	{
		if (Tree->data == node1)
		{
			printf("\n\t Node %d is an Ancestor of Node %d", node1, node2);
			getch();
		}
		return true;
	}
	return false;
}

// isChild Function
bool isChildOf(nd *root)
{

	nd Tree = *root;
	nd Child = *root;
	nd Parent;
	int data;

	if (Tree == NULL)
	{

		printf("\n\t The AVL Tree does not exist. ");
		getch();
		return false;
	}
	else
	{

		printf("\n\t Check Child ");
		printf("\n\t Enter the Node: ");
		while (getchar() != '\n')
			;
		scanf("%d", &data);

		if (Tree->left == NULL && Tree->right == NULL)
		{
			printf("\n\t The Tree Consist of only one element... ");
			getch();
			return false;
		}

		while (true)
		{

			if (Child->data == data)
			{
				if (Child->data == Parent->data)
				{
					printf("\n\t Number inputted is the Root... ");
					getch();
					return false;
				}

				printf("\n\t Node \t %d is Child of Node %d", Child->data, Parent->data);
				getch();
				return true;
			}

			if (Child->data < data)
			{
				Parent = Child;
				Child = Child->right;
			}
			else if (Child->data > data)
			{
				Parent = Child;
				Child = Child->left;
			}

			if (Child == NULL)
			{
				printf("\n\t Inputted Node not found... ");
				getch();
				return false;
			}
		}
	}
}

// isParent Function of the Tree
bool isParentOf(nd *root)
{

	nd Tree = *root;
	nd Child = *root;
	nd Parent;
	int data;

	if (Tree == NULL)
	{

		printf("\n\t The AVL Tree does not exist. ");
		getch();
		return false;
	}
	else
	{

		printf("\n\t Check Parent ");
		printf("\n\t Enter the Node: ");
		while (getchar() != '\n')
			;
		scanf("%d", &data);

		if (Tree->left == NULL && Tree->right == NULL)
		{
			printf("\n\t The Tree Consist of only one element... ");
			getch();
			return false;
		}

		Parent = Child;

		while (true)
		{

			if (Child->data == data)
			{
				if (Child->data == Parent->data)
				{
					printf("\n\t Number inputted is the Root... ");
					getch();
					return false;
				}

				printf("\n\t Node \t %d is Parent of Node %d", Parent->data, Child->data);
				getch();
				return true;
			}

			if (Child->data < data)
			{
				Parent = Child;
				Child = Child->right;
			}
			else if (Child->data > data)
			{
				Parent = Child;
				Child = Child->left;
			}

			if (Child == NULL)
			{
				printf("\n\t Inputted Node not found... ");
				getch();
				return false;
			}
		}
	}
}

// to determine if the Node exist
bool isNode(nd *root)
{

	int searchNode, found;
	nd Tree = *root;

	if (Tree == NULL)
	{
		printf("\n\t The Tree does not exits. ");
		getch();
		return false;
	}

	printf("\n\t Input the Node: ");
	while (getchar() != '\n')
		;
	scanf("%d", &searchNode);

	found = findNode(root, searchNode);

	if (found == searchNode)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// FindNode Function
int findNode(nd *root, int searchNode)
{

	nd Tree = *root;

	if (Tree != NULL)
	{

		if (searchNode == Tree->data)
		{
			return Tree->data;
		}
		else if (searchNode > Tree->data)
		{
			findNode(&Tree->right, searchNode);
		}
		else if (searchNode < Tree->data)
		{
			findNode(&Tree->left, searchNode);
		}
	}
}

// Inputting of 2 Nodes
void inputAncDec(int *data1, int *data2)
{

	int Ancestor, Descendant;

	printf("\n\t Enter Ancestor Node: ");
	while (getchar() != '\n')
		;
	scanf("%d", &Ancestor);

	printf("\n\t Enter Descendant Node: ");
	while (getchar() != '\n')
		;
	scanf("%d", &Descendant);

	*data1 = Ancestor;
	*data2 = Descendant;
}

// Main Driver
int main()
{

	nd root = NULL;
	int Choice, Node, targetLevel, data1, data2;

	do
	{
		system("cls");
		printf("\n\t\t\t\t\t Welcome to AVL Tree! \n");
		printf("\n\t 1. Insert Value \n");
		printf("\n\t 2. Find Node \n");
		printf("\n\t 3. Display \n");
		printf("\n\t 4. Height \n");
		printf("\n\t 5. Level \n");
		printf("\n\t 6. Find Parent \n");
		printf("\n\t 7. Find Child \n");
		printf("\n\t 8. Ancestor \n");
		printf("\n\t 9. Descendant \n");
		printf("\n\t 10. Terminate Program \n");
		printf("\n\t\t\t Enter your Choice: ");
		fflush(stdin);
		scanf("%d", &Choice);

		switch (Choice)
		{

		case 1:
			printf("\n\t Input Value: ");
			scanf("%d", &Node);
			while (getchar() != '\n')
				;
			root = insert(root, Node);
			break;

		case 2:
			Node = isNode(&root);
			if (Node)
			{
				printf("\n\t The Node exist. ");
				getch();
			}
			else
			{
				printf("\n\t The Node does not exist. ");
				getch();
			}
			break;

		case 3:
			printf("\n\t Pre-Order Traversal: ");
			displayPreOrder(root);
			printf("\n\t In-Order Traversal: ");
			displayInOrder(root);
			printf("\n\t Post-Order Traversal: ");
			displayPostOrder(root);
			printf("\n\n");
			printf("\n\t Traversal Displayed! \n");
			getch();
			break;

		case 4:
			printf("\n\t Height of Tree: %d \n\n", treeHeight(root));
			getch();
			break;

		case 5:
			printf("\n\t Enter Target Level: ");
			scanf("%d", &targetLevel);
			while (getchar() != '\n')
				;
			printf("\n\t Level of Node: %d\n\n", Level(root, targetLevel, 0));
			getch();
			break;

		case 6:
			if ((isParentOf(&root)))
			{
			}
			else
			{
				printf("\n\t Try again... ");
				getch();
			}
			break;

		case 7:
			if ((isChildOf(&root)))
			{
			}
			else
			{
				printf("\n\t Try again... ");
				getch();
			}
			break;

		case 8:
			inputAncDec(&data1, &data2);
			isAncestor(&root, data1, data2);
			if ((isAncestor(&root, data1, data2)))
			{
			}
			else
			{
				printf("\n\t Node %d is not an Ancestor of node %d", data1, data2);
				getch();
			}
			break;

		case 9:
			inputAncDec(&data1, &data2);
			isDescendant(&root, data1, data2);
			getch();
			break;

		case 10:
			printf("\n\t\t Program Terminated! ");
			exit(0);
			break;

		default:
			printf("\n\t Input an Integer from 1-10. Try again... ");
			getch();
		}
	} while (Choice != 9);
	return 0;
}