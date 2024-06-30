/*
	Developed by: James Ald Teves
	BS Computer Science
	Instructor: Assist. Prof. Melody Angelique Rivera
	Doubly Linked List

	Description: This program enables you to record a detail's of a person.
	This time, the linked list in which navigation is possible in both ways. 
	Either forward and backward easily as compared to Single Linked List.
*/

// Preprocessor Directives
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

// Define Statement
#define SIZE 10
#define NAMESIZE 40

typedef struct dll *nd;
struct dll
{

	char firstName[NAMESIZE];
	char lastName[NAMESIZE];
	char Sex[SIZE];
	int Feet;
	int Inches;
	int Pounds;
	float Weight;
	nd left;
	nd right;

} NODE;

// Global Declaration
int recordCount = 0;

// Function Declaration
void CreateNodeList(nd *head);
void ViewNodeList(nd *head);
void SearchNodeList(nd *head);
void gotoxy(short x, short y);

void CreateNodeList(nd *head)
{

	// Local Vairables
	char fName[NAMESIZE];
	char lName[NAMESIZE];
	char sex[SIZE];
	int ft;
	int inch;
	int lbs;
	float wt;

	nd temp, ptr;
	nd h = *head;

	temp = malloc(sizeof(NODE));

	printf("\n\t Enter the following Detail's: \n");
	fflush(stdin);
	printf("\n\t Enter firstname: ");
	gets(fName);
	printf("\n\t Enter lastname: ");
	gets(lName);
	printf("\n\t Sex (Male/Female): ");
	gets(sex);
	printf("\n\t Height in ft: ");
	scanf("%d", &ft);
	printf("\n\t Inches: ");
	scanf("%d", &inch);
	printf("\n\t Weight in lbs: ");
	scanf("%d", &lbs);

	strcpy(temp->firstName, fName);
	strcpy(temp->lastName, lName);
	strcpy(temp->Sex, sex);
	temp->Feet = ft;
	temp->Inches = inch;
	// Conversion of lbs to kg
	wt = lbs * 0.453592;
	temp->Weight = wt;
	recordCount++;

	if (*head == NULL)
	{
		temp->left = NULL;
		temp->right = NULL;
		*head = temp;
		return;
	}
	else
	{
		h = *head;
		ptr = h;
		while (ptr->right != NULL)
		{
			ptr = ptr->right;
		}
		ptr->right = temp;
		temp->left = ptr;
		temp->right = NULL;
		//*head = h;
		return;
	}
}

void ViewNodeList(nd *head)
{

	nd ptr = *head;
	nd temp;
	int i;

	if (ptr == NULL)
	{
		printf("\n\t There are no records found! ");
		printf("\n\t Press any key to continue... ");
		printf("\n\n");
		system("pause");
		system("cls");
		printf("\n");
		return;
	}

	else
	{

		printf("\n\t\t List to the End NODE. \n");
		while (ptr != NULL)
		{

			printf("\n\t Firstname: %s", ptr->firstName);
			printf("\n\t Lastname: %s", ptr->lastName);
			printf("\n\t Sex: %s", ptr->Sex);
			printf("\n\t Height in ft: %d Inches: %d", ptr->Feet, ptr->Inches);
			printf("\n\t Weight in KG: %.2f", ptr->Weight);
			printf("\n");
			i++;
			temp = ptr;
			ptr = ptr->right;
		}

		printf("\n\t\t List from the End to Beginning of the NODE. \n");
		while (temp != NULL)
		{

			printf("\n\t Firstname: %s", temp->firstName);
			printf("\n\t Lastname: %s", temp->lastName);
			printf("\n\t Sex: %s", temp->Sex);
			printf("\n\t Height in ft: %d Inches: %d", temp->Feet, temp->Inches);
			printf("\n");
			i++;
			temp = temp->left;
		}
	}

	printf("\n\n\n\n\t\t Data's Recorded: %d", recordCount);
	printf("\n\n");
	system("pause");
	system("cls");
	printf("\n");
}

void SearchNodeList(nd *head)
{

	nd ptr = *head;
	char searchName[NAMESIZE];

	if (ptr == NULL)
	{
		printf("\n\t There are no records yet! ");
		printf("\n\t The list is empty... ");
		printf("\n\n");
		system("pause");
		system("cls");
		return;
	}

	int Choice;
	int found = 0;

	printf("\n\t\t SEARCH \n");
	printf("\n\t 1 - Search by Firstname \n");
	printf("\n\t 2 - Search by Lastname \n");
	printf("\n\t Enter the no. of Choice: ");
	scanf("%d", &Choice);
	fflush(stdin);

	if (Choice == 1)
	{
		printf("\n\t Enter firstname to Search: ");
		gets(searchName);
	}
	else if (Choice == 2)
	{
		printf("\n\t Enter lastname to Search: ");
		gets(searchName);
	}

	while (ptr != NULL)
	{
		if (Choice == 1)
		{
			if (strcmp(searchName, ptr->firstName) == 0)
			{
				found = 1;
				printf("\tThe record is existing. Here are the details\n");
				printf("\t\t%s %s\n", ptr->firstName, ptr->lastName);
				printf("\t\t%s\n", ptr->Sex);
				printf("\t\tHeight: %d feet %d inches\n", ptr->Feet, ptr->Inches);
				printf("\t\tWeight: %.2f kilograms\n", ptr->Weight);

				float ibw1, ibw2;
				if (strcmp("male", ptr->Sex) == 0)
				{
					ibw1 = 50 + (ptr->Inches * 2.3);
					ibw2 = 52 + (ptr->Inches * 1.9);
					if (!(ptr->Weight == ibw1 || ptr->Weight == ibw2))
					{
						printf("\n\t\tYour weight is not ideal for your height\n");
						printf("\t\tBased on the formula of J. Devine, your Ideal Body Weight should be: %.2f\n", ibw1);
						printf("\t\tBased on the formula of J.D. Robinson, your Ideal Body Weight should be: %.2f", ibw2);
					}
					if (strcmp("female", ptr->Sex) == 0)
					{
						ibw1 = 50 + (ptr->Inches * 1.9);
						ibw2 = 52 + (ptr->Inches * 1.7);
						if (!(ptr->Weight == ibw1 || ptr->Weight == ibw2))
						{
							printf("\n\t\tYour weight is not ideal for your height\n");
							printf("\t\tBased on the formula of J. Devine, your Ideal Body Weight should be: %.2f\n", ibw1);
							printf("\t\tBased on the formula of J.D. Robinson, your Ideal Body Weight should be: %.2f", ibw2);
						}
					}
				}
				getch();
				printf("\n");
				system("pause");
				return;
			}
			else
			{
				ptr = ptr->right;
			}
		}
		if (Choice == 2)
		{
			if (strcmp(searchName, ptr->lastName) == 0)
			{
				found = 1;
				printf("\tThe record is existing. Here are the details\n");
				printf("\t\t%s %s\n", ptr->firstName, ptr->lastName);
				printf("\t\t%s\n", ptr->Sex);
				printf("\t\tHeight: %d feet %d inches\n", ptr->Feet, ptr->Inches);
				printf("\t\tWeight: %.2f kilograms\n", ptr->Weight);

				float ibw1, ibw2;
				if (strcmp("male", ptr->Sex) == 0)
				{
					ibw1 = 50 + (ptr->Inches * 2.3);
					ibw2 = 52 + (ptr->Inches * 1.9);
					if (!(ptr->Weight == ibw1 || ptr->Weight == ibw2))
					{
						printf("\n\t\tYour weight is not ideal for your height\n");
						printf("\t\tBased on the formula of J. Devine, your Ideal Body Weight should be: %.2f\n", ibw1);
						printf("\t\tBased on the formula of J.D. Robinson, your Ideal Body Weight should be: %.2f", ibw2);
					}
				}
				if (strcmp("female", ptr->Sex) == 0)
				{
					ibw1 = 50 + (ptr->Inches * 1.9);
					ibw2 = 52 + (ptr->Inches * 1.7);
					if (!(ptr->Weight == ibw1 || ptr->Weight == ibw2))
					{
						printf("\n\t\tYour weight is not ideal for your height\n");
						printf("\t\tBased on the formula of J. Devine, your Ideal Body Weight should be: %.2f\n", ibw1);
						printf("\t\tBased on the formula of J.D. Robinson, your Ideal Body Weight should be: %.2f", ibw2);
					}
				}
				getch();
				printf("\n");
				system("pause");
				return;
			}
			else
			{
				ptr = ptr->right;
			}
		}
	}
	if (found != 1)
	{
		printf("\n\t The record does not exist...");
	}

	getch();
	printf("\n");
	system("pause");
	system("cls");
}

// Inview Display Function
void gotoxy(short x, short y)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// Function Menu
void Menu()
{

	nd head = NULL;
	int choice;

	do
	{
		system("cls");
		printf("\n\n\t\t Welcome to Record Management System \n");
		printf("\n\t 1. Record Data");
		printf("\n\t 2. View Data");
		printf("\n\t 3. Search Data");
		printf("\n\t 4. Exit Program ");
		printf("\n\n\t Please Enter your choice: ");
		scanf("%d", &choice);
		system("cls");
		printf("\n");

		switch (choice)
		{
		case 1:
			CreateNodeList(&head);
			break;
		case 2:
			ViewNodeList(&head);
			break;
		case 3:
			SearchNodeList(&head);
			break;
		case 4:
			printf("\n\n\t\t Program Terminated! ");
			exit(1);
		default:
			printf("\n\n\t\tIncorrect Choice!");
			printf("\n\n");
			system("pause");
			system("cls");
			printf("\n");
		}
	} while (choice != 4);
}

// Main Driver
int main()
{

	// Local Declaration
	nd head;

	// Function Call
	Menu();
}