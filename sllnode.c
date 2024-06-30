#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

/*
	Developed by: James Ald Teves

	Silliman University
	CCS 4 - C
	Instructor: Assist. Prof. Melody Angelique Rivera

	Description: This program enables you to record a detail's of a person.
	I use both of Linked list and Singly linked list in this program.
	This program uses Nodes, to store that inputted data from the user.
*/

// Define Statement
#define SIZE 10
#define NAMESIZE 40

// Global Count Declaration
int Count = 0;

typedef struct node *nd;
struct node
{

	char firstName[NAMESIZE];
	char lastName[NAMESIZE];
	char Sex[SIZE];
	int Feet;
	int Inches;
	int Pounds;
	float Weight;
	nd next;

} NODE;

// Function Declaration
void CreateNodeList(nd *head);
void ViewNodeList(nd head);
void SearchNodeList(nd head);
void UpdateNodeList(nd head);
void DeleteNodeList(nd head);
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

	nd h = *head, ptr, temp;
	h = malloc(sizeof(NODE));

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

	// Conversion of lbs to kg
	wt = lbs * 0.453592;

	//	if (h == NULL) {

	strcpy(h->firstName, fName);
	strcpy(h->lastName, lName);
	strcpy(h->Sex, sex);
	h->Feet = ft;
	h->Inches = inch;
	h->Weight = wt;
	h->next = NULL;
	*head = h;
	Count++;

	printf("\n\t Record Successfully! \n");
	system("cls");

	//	}
	//	else {
	/*
		h = *head;
		temp = malloc(sizeof(NODE));
		strcpy(temp->firstName, fName);
		strcpy(temp->lastName, lName);
		strcpy(temp->Sex, sex);
		temp->Feet = ft;
		temp->Inches = inch;
		temp->Weight = lbs;

		ptr = h;
		while (ptr->next != NULL) {

			ptr = ptr->next;

		}

		ptr->next = temp;
		temp->next = NULL;
		*head = h;
		Count++;
		*/
	//	}
}

void ViewNodeList(nd head)
{

	int i;
	nd h = head, ptr;
	system("cls");

	if (Count == 0)
	{

		printf("\n\t There are no records found !!!");
		printf("\n\t Press any key to continue... ");
		getch();
	}
	else
	{

		int i, x1, x2, x3, x4, x5, y;
		system("cls");
		gotoxy(1, 3);
		printf("Firstname");
		gotoxy(1, 4);
		printf("-----------");
		gotoxy(15, 3);
		printf("Lastname");
		gotoxy(15, 4);
		printf("---------");
		gotoxy(28, 3);
		printf("Sex");
		gotoxy(28, 4);
		printf("----");
		gotoxy(35, 3);
		printf("Height");
		gotoxy(35, 4);
		printf("-------");
		gotoxy(45, 3);
		printf("Weight");
		gotoxy(45, 4);
		printf("-------");

		x1 = 1;
		x2 = 15;
		x3 = 28;
		x4 = 35;
		x5 = 45;

		y = 5;
		ptr = h;

		while (ptr != NULL)
		{

			gotoxy(x1, y);
			printf("%s", ptr->firstName);
			gotoxy(x2, y);
			printf("%s", ptr->lastName);
			gotoxy(x3, y);
			printf("%s", ptr->Sex);
			gotoxy(x4, y);
			printf("%d' \t%d\"", ptr->Feet, ptr->Inches);
			gotoxy(x5, y);
			printf("%.2f kg", ptr->Weight);
			y++;
			ptr = ptr->next;
		}
	}

	if (Count == 10)
	{

		printf("\n\t The NODE is full... \n");
		printf("\n\t You can no longer record! \n");
		getch();
		int main();
	}
	getch();
}

void SearchNodeList(nd head)
{

	int i;
	nd h = head, ptr;

	if (h == NULL)
	{
		printf("\n\t There are no records yet. \n");
		printf("\n\t The list is empty \n");
		printf("\n\n");
		system("pause");
		system("cls");
		return;
	}
	else
	{

		int Ch;
		int found = 0;
		ptr = h;

		printf("\n\t\t SEARCH \n");
		printf("\n\t 1 - Search by Firstname \n");
		printf("\n\t 2 - Search by Lastname \n");
		printf("\n\t Enter the no. of Choice: ");
		scanf("%d", &Ch);
		fflush(stdin);

		if (Ch == 1)
		{

			char searchName[NAMESIZE];
			printf("\n\t Enter firstname to Search: ");
			gets(searchName);
			for (i = 0; i < 1; i++)
			{
				if (strcmp(searchName, ptr->firstName) == 0)
				{
					found++;
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
				}
			}
		}
		else if (Ch == 2)
		{

			char searchName[NAMESIZE];
			printf("\n\t Enter firstname to Search: ");
			gets(searchName);
			for (i = 0; i < 1; i++)
			{
				if (strcmp(searchName, ptr->lastName) == 0)
				{
					found++;
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
				}
			}
		}

		if (found == 0)
		{
			printf("\n\t The record does not exist. \n");
		}
	}
	getch();
	printf("\n");
	system("pause");
	system("cls");
}

void UpdateNodeList(nd head)
{

	int i, found = 0;
	nd h = head, ptr;
	char searchName[NAMESIZE];
	ptr = h;

	if (ptr == NULL)
	{
		printf("\n\tThe list is empty\n");
		printf("\n\n");
		system("pause");
		system("cls");
		return;
	}
	else
	{
		printf("\n\t Enter the firstname to be searched: ");
		gets(searchName);
		fflush(stdin);

		while (ptr != NULL)
		{
			if (searchName == ptr->firstName)
			{
				printf("\n\t\t Record Found!!! \n");
				printf("\n\t\t Update Records: \n");
				fflush(stdin);
				printf("\n\t Enter firstname: ");
				gets(ptr->firstName);
				printf("\n\t Enter lastname: ");
				gets(ptr->lastName);
				printf("\n\t Enter Sex: ");
				gets(ptr->Sex);
				printf("\n\t Enter heigh in ft: ");
				scanf("%d", ptr->Feet);
				getchar();
				printf("\n\t Enter inches: ");
				scanf("%d", ptr->Inches);
				getchar();
				printf("\n\t Enter weight: ");
				scanf("%d", ptr->Weight);
				getchar();
				found = 1;
			}
			ptr = ptr->next;
			i++;
		}
		if (found == 0)
		{
			printf("\n\t Name(s) cannot be found... ", searchName);
		}
	}

	printf("\n");
	system("pause");
	system("cls");
}

void DeleteNodeList(nd head)
{

	nd h = head, ptr;
	ptr = h;

	if (ptr == NULL)
	{
		printf("\n\t The list is empty \n");
		printf("\n\n");
		system("pause");
		system("cls");
		return;
	}
	if (ptr->next == NULL)
	{
		printf("\n\t Records Deleted: \n");
		printf("\n Firstname: ", ptr->firstName);
		printf("\n Lastname: ", ptr->lastName);
		printf("\n Sex: ", ptr->Sex);
		printf("\n Height in ft: ", ptr->Feet);
		printf("\n Height in inches: ", ptr->Inches);
		printf("\n WightL ", ptr->Weight);
		printf("\n");
		free(ptr);
		h = NULL;
	}
	else
	{
		h = h->next;
		printf("\n\t Records Deleted: \n");
		printf("\n Firstname: ", ptr->firstName);
		printf("\n Lastname: ", ptr->lastName);
		printf("\n Sex: ", ptr->Sex);
		printf("\n Height in ft: ", ptr->Feet);
		printf("\n Height in inches: ", ptr->Inches);
		printf("\n WightL ", ptr->Weight);
		printf("\n");
		free(ptr);
	}
	Count--;
	printf("\n\n");
	system("pause");
	system("cls");
	return;
}

// Inview Display Function
void gotoxy(short x, short y)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// Menu Function
int Menu()
{

	nd head;
	int choice;

	do
	{
		system("cls");
		printf("\n\n\t\t Welcome to Record Management System \n");
		printf("\n\t 1. Record Data");
		printf("\n\t 2. View Data");
		printf("\n\t 3. Search Data ");
		printf("\n\t 4. Delete Data ");
		printf("\n\t 5. Update Data ");
		printf("\n\t 6. Exit ");
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
			ViewNodeList(head);
			break;
		case 3:
			SearchNodeList(head);
			break;
		case 4:
			DeleteNodeList(head);
			break;
		case 5:
			UpdateNodeList(head);
			break;
		case 6:
			printf("\n\n\t\t Program Terminated! ");
			exit(1);
			break;
		default:
			printf("\n\n\t\t Incorrect Choice!");
		}
	} while (choice != 6);
}

// Main Method
int main(void)
{

	nd head;

	// Function Call
	Menu();
	CreateNodeList(&head);
	ViewNodeList(head);
	SearchNodeList(head);
	DeleteNodeList(head);
	UpdateNodeList(head);
	return 0;
}
