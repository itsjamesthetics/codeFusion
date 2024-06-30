#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Developed by: James Ald Teves

	Silliman University
	Programming Assignment in CCS 2 - B

	Description: Data Structures
*/

// Declarations for subprograms
void create();
void insertbeg();
void insertend();
int deleteend();
int deletebeg();
void searchStud();
void searcuUpdateStud();

// Global declaration
int Count = 0;

// Structure declaration
struct node
{

	long long int studNum;
	char studlastName[20], studfirstName[20], studDegree[20], studCollege[20], studyearLevel[10];
	struct node *next;
	struct node *prev;

} *h, *temp, *temp1, *temp2, *temp4;

// Function to create node
void create()
{
	int studNum, i = 1;
	char studlastName[20], studfirstName[20], studDegree[50], studCollege[50], studyearLevel[20];

	temp = (struct node *)malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->next = NULL;

	printf("\n\tEnter Student Information\n");
	printf("\n\tStudent Number : ");
	scanf("%lld", &studNum);
	fflush(stdin);
	printf("\tLast Name : ");
	gets(studlastName);
	printf("\tFirst Name : ");
	gets(studfirstName);
	printf("\tStudent Degree : ");
	gets(studDegree);
	printf("\tCollege : ");
	gets(studCollege);
	printf("\tYear Level : ");
	gets(studyearLevel);
	printf("\n");

	temp->studNum = studNum;
	strcpy(temp->studlastName, studlastName);
	strcpy(temp->studfirstName, studfirstName);
	strcpy(temp->studDegree, studDegree);
	strcpy(temp->studCollege, studCollege);
	strcpy(temp->studyearLevel, studyearLevel);
	Count++;

	printf("\tRecords Added!\n\n");
	system("pause");
	system("cls");
}

// Function to insert at beginning
void insertbeg()
{
	// If DLL is empty
	if (h == NULL)
	{
		create();
		h = temp;
		temp1 = h;
	}

	// Else create a new node and
	// update the links
	else
	{
		create();
		temp->next = h;
		h->prev = temp;
		h = temp;
	}
}

// Function to insert at end
void insertend()
{
	// If DLL is empty
	if (h == NULL)
	{
		create();
		h = temp;
		temp1 = h;
	}

	// Else create a new node and
	// update the links
	else
	{
		create();
		temp1->next = temp;
		temp->prev = temp1;
		temp1 = temp;
	}
}

// Function to display from beginning
void displaybeg()
{
	int i = 1;
	temp2 = h;
	if (temp2 == NULL)
	{
		printf("\n\tThe list is empty\n");
		printf("\n\n");
		system("pause");
		system("cls");
		return;
	}
	printf("\n\t Linked list elements "
		   "from beginning:\n");
	while (temp2 != NULL)
	{

		printf("\n\t[Student %d]\n", i);
		printf("\n\tStudent Number : %lld\n", temp2->studNum);
		printf("\tLast Name : %s\n", temp2->studlastName);
		printf("\tFirst Name : %s\n", temp2->studfirstName);
		printf("\tStudent Degree : %s\n", temp2->studDegree);
		printf("\tCollege : %s\n", temp2->studCollege);
		printf("\tYear Level : %s", temp2->studyearLevel);
		printf("\n");
		i++;
		temp2 = temp2->next;
	}

	// Print the count
	printf("\n\t\tNumber of Students :  %d\n\n", Count);

	system("pause");
	system("cls");
}

// Function to delete at end
int deleteend()
{
	struct node *temp;
	temp = h;
	if (temp == NULL)
	{
		printf("\n\tThe list is empty\n");
		printf("\n\n");
		system("pause");
		system("cls");
		return 0;
	}
	if (temp->next == NULL)
	{
		printf("\n\tRecords Deleted:\n");
		printf("\n\tStudent Number : %lld\n", temp->studNum);
		printf("\tLast Name : %s\n", temp->studlastName);
		printf("\tFirst Name : %s\n", temp->studfirstName);
		printf("\tStudent Degree : %s\n", temp->studDegree);
		printf("\tCollege : %s\n", temp->studCollege);
		printf("\tYear Level : %s", temp->studyearLevel);
		printf("\n");
		free(temp);
		h = NULL;
	}
	else
	{
		temp = temp1;
		temp2 = temp1->prev;
		temp2->next = NULL;
		printf("\n\tRecords Deleted:\n");
		printf("\n\tStudent Number : %lld\n", temp->studNum);
		printf("\tLast Name : %s\n", temp->studlastName);
		printf("\tFirst Name : %s\n", temp->studfirstName);
		printf("\tStudent Degree : %s\n", temp->studDegree);
		printf("\tCollege : %s\n", temp->studCollege);
		printf("\tYear Level : %s", temp->studyearLevel);
		printf("\n");
		free(temp);
		temp1 = temp2;
	}
	Count--;

	printf("\n\n");
	system("pause");
	system("cls");
	return 0;
}

// Function to delete from beginning
int deletebeg()
{
	struct node *temp;
	temp = h;
	if (temp == NULL)
	{
		printf("\n\tThe list is empty\n");
		printf("\n\n");
		system("pause");
		system("cls");
		return 0;
	}
	if (temp->next == NULL)
	{
		printf("\n\tRecords Deleted:\n");
		printf("\n\tStudent Number : %lld\n", temp->studNum);
		printf("\tLast Name : %s\n", temp->studlastName);
		printf("\tFirst Name : %s\n", temp->studfirstName);
		printf("\tStudent Degree : %s\n", temp->studDegree);
		printf("\tCollege : %s\n", temp->studCollege);
		printf("\tYear Level : %s", temp->studyearLevel);
		printf("\n");
		free(temp);
		h = NULL;
	}
	else
	{
		h = h->next;
		h->prev = NULL;
		printf("\n\tRecords Deleted:\n");
		printf("\n\tStudent Number : %lld\n", temp->studNum);
		printf("\tLast Name : %s\n", temp->studlastName);
		printf("\tFirst Name : %s\n", temp->studfirstName);
		printf("\tStudent Degree : %s\n", temp->studDegree);
		printf("\tCollege : %s\n", temp->studCollege);
		printf("\tYear Level : %s", temp->studyearLevel);
		printf("\n");
		free(temp);
	}
	Count--;

	printf("\n\n");
	system("pause");
	system("cls");
	return 0;
}

// Function to search Student Number
void searchStud()
{
	int i = 1, found = 0;
	long long int searchNum;
	struct node *temp;
	temp = h;
	if (temp == NULL)
	{
		printf("\n\tThe list is empty\n");
		printf("\n\n");
		system("pause");
		system("cls");
		return;
	}
	else
	{
		printf("\n\tStudent Number to be Searched : ");
		scanf("%lld", &searchNum);
		fflush(stdin);
		while (temp != NULL)
		{
			if (searchNum == temp->studNum)
			{
				printf("\n\tStudent Found!\n");
				printf("\t[Student %d]\n", i);
				printf("\n\tStudent Information:\n");
				printf("\n\tStudent Number : %lld\n", temp->studNum);
				printf("\tLast Name : %s\n", temp->studlastName);
				printf("\tFirst Name : %s\n", temp->studfirstName);
				printf("\tStudent Degree : %s\n", temp->studDegree);
				printf("\tCollege : %s\n", temp->studCollege);
				printf("\tYear Level : %s", temp->studyearLevel);
				printf("\n");
				found = 1;
			}
			temp = temp->next;
			i++;
		}
		if (found == 0)
		{
			printf("\n\tStudent Number %lld Cannot be Found.\n", searchNum);
		}
	}

	printf("\n");
	system("pause");
	system("cls");
}

// Function to search and update record
void searchUpdateStud()
{
	int i = 1, found = 0;
	long long int searchNum;
	struct node *temp;
	temp = h;
	if (temp == NULL)
	{
		printf("\n\tThe list is empty\n");
		printf("\n\n");
		system("pause");
		system("cls");
		return;
	}
	else
	{
		printf("\n\tStudent Number to be Searched : ");
		scanf("%lld", &searchNum);
		fflush(stdin);
		while (temp != NULL)
		{
			if (searchNum == temp->studNum)
			{
				printf("\n\tStudent Found!\n");
				printf("\t[Student %d]\n", i);
				printf("\n\t\tUpdate Records:\n");
				printf("\n\tStudent Number : ");
				scanf("%lld", &temp->studNum);
				fflush(stdin);
				printf("\tLast Name : ");
				gets(temp->studlastName);
				printf("\tFirst Name : ");
				gets(temp->studfirstName);
				printf("\tStudent Degree : ");
				gets(temp->studDegree);
				printf("\tCollege : ");
				gets(temp->studCollege);
				printf("\tYear Level : ");
				gets(temp->studyearLevel);
				found = 1;
			}
			temp = temp->next;
			i++;
		}
		if (found == 0)
		{
			printf("\n\tStudent Number %lld Cannot be Found.\n", searchNum);
		}
	}

	printf("\n");
	system("pause");
	system("cls");
}

// Function displaying menus
void studentDetails()
{
	system("cls");
	int ch, n, i;
	h = NULL;
	temp = temp1 = NULL;
	do
	{
		printf("\n\n\t\t *** Welcome to my Doubly Lists Student System!!! *** \n");
		printf("\n\t 1. Create a DDL or Student\'s Entry \n");
		printf("\n\t 2. Insert at beginning \n");
		printf("\n\t 3. Insert at end\n");
		printf("\n\t 4. Display from the beginning\n");
		printf("\n\t 5. Delete at beginning\n");
		printf("\n\t 6. Delete at end\n");
		printf("\n\t 7. Search Student Number\n");
		printf("\n\t 8. Search and Update\n");
		printf("\n\t 9. Exit\n");
		printf("\n\n\t\t__________________________________________________________\n");
		printf("\n\t Enter choice : ");
		scanf("%d", &ch);
		fflush(stdin);

		// Switch statements begins
		switch (ch)
		{
		case 1:
			printf("\n\tEnter Number of Students : ");
			scanf("%d", &n);
			fflush(stdin);
			system("cls");
			for (i = 0; i < n; i++)
			{
				printf("\n\t\t[%d]\n", i + 1);
				insertend();
			}
			break;
		case 2:
			system("cls");
			printf("\n\t\tInsert at the Beginning:\n");
			insertbeg();
			break;
		case 3:
			system("cls");
			printf("\n\t\tInsert at the End:\n");
			insertend();
			break;
		case 4:
			system("cls");
			displaybeg();
			break;
		case 5:
			system("cls");
			deletebeg();
			break;
		case 6:
			system("cls");
			deleteend();
			break;
		case 7:
			system("cls");
			searchStud();
			break;
		case 8:
			system("cls");
			searchUpdateStud();
			break;
		case 9:
			system("cls");
			break;
		default:
			printf("\n\t\tIncorrect Choice!");
			printf("\n\t\tPlease try again!");
		}
	} while (ch != 9);
}

// Driver Code
int main()
{
	// Function Call
	studentDetails();
	return 0;
}
