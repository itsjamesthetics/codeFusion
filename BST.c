/*
    Description: This program enables us to simulate Binary Search Tree. Binary Tree is a non-linear data structure nodes, that has a maximum
    of two children for every parent node. In this program, we are able to Create, Add, Search, Find the Max & Min Value, Delete Nodes, and Display in our Binary Search Tree.

    Developed by: James Ald Teves
    BS Computer Science
    Instructor: Assis. Prof. Melody Angelique Rivera

    Started: November 14, 2022
    Ended: November 25, 2022
*/

//  Preprocessor Directives
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <windows.h>

// Structure Declaration
typedef struct binarytree *bt;
struct binarytree
{

    int data;
    bt left;
    bt right;

} BIN;

//  Function Declaration
int main();
int Menu(int Choice);
bool isEmpty(bt *root);
void CreateBinary(bt *root, int *checkBinary);
void InsertElement(bt *root, char element);
void InorderTraversal(bt *root);
void Display(bt *root);
void FindMinMaxValues(bt *root);
void Search(bt *root, char element);
void Delete(bt *root, char element);

// Main Driver
int main()
{

    bt root;
    char element;
    int checkBinary = 0;
    int Choice;

    do
    {

        Choice = Menu(Choice);
        switch (Choice)
        {
        case 1:
            CreateBinary(&root, &checkBinary);
            break;

        case 2:
            if (checkBinary == 1)
            {
                InsertElement(&root, element);
            }
            else
            {
                printf("\n\t Binary Tree has not been Created! ");
                printf("\n\t ");
                system("pause");
                system("cls");
                printf("\n\n");
            }
            break;

        case 3:
            if (checkBinary == 1)
            {
                if (isEmpty(&root))
                {
                    printf("\n\t The Binary Tree is Empty! ");
                    getch();
                }
                else
                {
                    printf("\n\t Enter an Element to be Searched: ");
                    scanf("%c", &element);
                    Search(&root, element);
                }
            }
            else
            {
                printf("\n\t Binary Tree has not been Created! ");
                printf("\n\t ");
                system("pause");
                system("cls");
                printf("\n\n");
            }
            break;

        case 4:
            if (checkBinary == 1)
            {
                if (isEmpty(&root))
                {
                    printf("\n\t The Binary Tree is Empty! ");
                    getch();
                }
                else
                {
                    FindMinMaxValues(&root);
                }
            }
            else
            {
                printf("\n\t Binary Tree has not been Created! ");
                printf("\n\t ");
                system("pause");
                system("cls");
                printf("\n\n");
            }
            break;

        case 5:
            if (checkBinary == 1)
            {
                if (isEmpty(&root))
                {
                    printf("\n\t The Binary Tree is Empty! ");
                    getch();
                }
                else
                {
                    printf("\n\n\t Enter the Element to be Deleted: ");
                    scanf("%c", &element);
                    Delete(&root, element);
                }
            }
            else
            {
                printf("\n\t Binary Tree has not been Created! ");
                printf("\n\t ");
                system("pause");
                system("cls");
                printf("\n\n");
            }
            break;

        case 6:
            if (checkBinary == 1)
            {
                Display(&root);
            }
            else
            {
                printf("\n\t Binary Tree has not been Created! ");
                printf("\n\t ");
                system("pause");
                system("cls");
                printf("\n\n");
            }
            break;

        case 7:
            printf("\n\t\t Program Terminated! \n ");
            printf("\n");
            exit(0);
            break;

        default:
            printf("\n\t Incorrect Choice! ");
            printf("\n\t Please Try again... ");
            printf("\n\n");
            system("pause");
            system("cls");
            printf("\n");
            break;
        }

    } while (Choice != 7);

    return 0;
}

void CreateBinary(bt *root, int *checkBinary)
{

    bt head = *root;
    int checkB = *checkBinary;
    char Option;
    char Overwrite;

    if (checkB == 0)
    {

        printf("\n\t Do you want to Create Binary Tree (Y/N): ");
        scanf(" %c", &Option);

        switch (tolower(Option))
        {

        case 'y':
            checkB++;
            head = NULL;
            printf("\n\t Binary Search Tree has been Created! ");
            printf("\n\t ");
            system("pause");
            system("cls");
            printf("\n\n");
            break;

        case 'n':
            printf("\n\t Binary Tree Creation Failed! ");
            printf("\n\t ");
            system("pause");
            system("cls");
            printf("\n\n");
            break;

        default:
            printf("\n\t Invalid! ");
            printf("\n\t Please Try again... ");
            printf("\n\t ");
            system("pause");
            system("cls");
            printf("\n\n");
            break;

            *root = head;
            *checkBinary = checkB;
        }
    }
    else
    {

        printf("\n\t Binary Tree is Already Created! ");
        printf("\n\t Do you want to Overwrite Data (Y/N): ");
        printf("\n\t Warning: All Data's maybe Deleted! ");
        scanf("%c", &Overwrite);

        switch (tolower(Overwrite))
        {

        case 'y':
            main();
            getch();
            break;

        case 'n':
            return;
            break;

        default:
            printf("\n\t Invalid! ");
            printf("\n\t Please Try again... ");
            printf("\n\t ");
            system("pause");
            system("cls");
            printf("\n\n");
            break;
        }
    }

    *root = head;
    *checkBinary = checkB;
}

void InsertElement(bt *root, char element)
{

    bt temp = malloc(sizeof(BIN));

    printf("\n\n\t Enter Element: ");
    scanf("%c", &element);

    temp->data = element;
    temp->left = NULL;
    temp->right = NULL;

    if (isEmpty(root))
    {

        *root = temp;
    }
    else
    {

        bt head = *root;
        bt parent = NULL;

        while (head != NULL)
        {

            parent = head;

            if (element < head->data)
            {
                head = head->left;

                if (head == NULL)
                {

                    parent->left = temp;
                    printf("\n\t Character Added Successfully! ");
                    printf("\n\t ");
                    system("pause");
                    system("cls");
                    printf("\n\n");
                    return;
                }
            }

            else if (element > head->data)
            {

                head = head->right;

                if (head == NULL)
                {

                    parent->right = temp;
                    printf("\n\t Character Added Successfully! ");
                    printf("\n\t ");
                    system("pause");
                    system("cls");
                    printf("\n\n");
                    return;
                }
            }

            else if (head->data == element)
            {

                printf("\n\t The Character is Already Inputted! ");
                printf("\n\t Please input another Character... ");
                printf("\n\t ");
                system("pause");
                system("cls");
                printf("\n\n");
                return;
            }
        }
    }

    printf("\n\t Character Added Successfully! ");
    printf("\n\t ");
    system("pause");
    system("cls");
    printf("\n\n");
}

void Search(bt *root, char element)
{

    bt head = *root;

    if (head == NULL)
    {
        printf("\n\t Element not Found! ");
        printf("\n");
        printf("\n\t ");
        system("pause");
        system("cls");
        printf("\n\n");
    }
    else if (element < head->data)
    {
        return Search(&head->left, element);
    }
    else if (element > head->data)
    {
        return Search(&head->right, element);
    }
    else
    {
        printf("\n\t Element Found Successfully! ");
        printf("\n");
        printf("\n\t ");
        system("pause");
        system("cls");
        printf("\n\n");
    }
}

void Delete(bt *root, char element)
{

    bt head = *root, temp, ptr;

    if (head == NULL)
    {
        printf("\n\t Element not Found! ");
        printf("\n");
        printf("\n\t ");
        system("pause");
        system("cls");
        printf("\n\n");
    }
    else
    {

        if (element < head->data)
        {
            Delete(&head->left, element);
        }
        else if (element > head->data)
        {
            Delete(&head->right, element);
        }
        else
        {

            if (head->left != NULL && head->right != NULL)
            {

                temp = head->right;
                while (temp->left)
                {
                    temp = temp->left;
                }
                head->data = temp->data;
                Delete(&head->right, temp->data);
            }
            else
            {

                ptr = head;
                if (head->left != NULL)
                {
                    head = head->left;
                }
                else if (head->right != NULL)
                {
                    head = head->right;
                }
                else
                {
                    head = NULL;
                }
                free(ptr);
            }
            printf("\n\t Element successfully Deleted! \n ");
            printf("\n\t ");
            system("pause");
            system("cls");
            printf("\n\n");
        }
        *root = head;
    }
}

void FindMinMaxValues(bt *root)
{

    bt leftchild, rightchild;

    printf("\n\t\t The Following Elements: \n ");

    leftchild = *root;

    while (leftchild->left != NULL)
    {
        leftchild = leftchild->left;
    }

    printf("\n\t The Minimum Element is: %c ", leftchild->data);
    printf("\n\n");

    rightchild = *root;
    while (rightchild->right != NULL)
    {
        rightchild = rightchild->right;
    }

    printf("\n\t The Maximum Element is: %c", rightchild->data);
    printf("\n");

    printf("\n\t\t ");
    system("pause");
    system("cls");
    printf("\n\n");
}

void InorderTraversal(bt *root)
{

    bt head = *root;

    if (!isEmpty(root))
    {

        InorderTraversal(&head->left);
        printf(" %c ", head->data);
        InorderTraversal(&head->right);
    }
}

void Display(bt *root)
{

    bt head = *root;

    if (isEmpty(root))
    {
        printf("\n\t The Binary Tree is Empty! ");
        getch();
    }
    else
    {

        printf("\n\n\t The Following Elements are: ");
        if (head->left == NULL && head->right == NULL)
        {
            printf("%c", head->data);
            printf("\n\n\t ");
            system("pause");
            system("cls");
            printf("\n");
        }
        else
        {
            InorderTraversal(&head);
            printf("\n\n\t ");
            system("pause");
            system("cls");
            printf("\n");
        }
    }
}

bool isEmpty(bt *root)
{

    if (*root == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Menu
int Menu(int Choice)
{

    system("cls");
    printf("\n\n\t\t Welcome to Binary Tree System \n");
    printf("\n\t 1. Create the Tree ");
    printf("\n\t 2. Add a Node to the Tree ");
    printf("\n\t 3. Search for a Value in the Tree ");
    printf("\n\t 4. Find the Min & Max Values in the Tree ");
    printf("\n\t 5. Delete a Value in the Tree ");
    printf("\n\t 6. Display the Values in the Tree ");
    printf("\n\t 7. Exit the Program \n ");
    printf("\n\n\t Please Enter your choice: ");
    scanf(" %d", &Choice);
    fflush(stdin);
    system("cls");
    printf("\n");

    return Choice;
}