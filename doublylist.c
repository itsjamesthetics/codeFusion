/*
	Developed by: James Ald Teves
	BS Computer Science

	Computing Programming 8
	Manipulating Doubly Lists
*/

// Preprocessor Directives
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// Global declaration
int Count = 1;

// Delcaring Subprograms
void create();
void insertbeg();
void insertend();
void displaybeg();
int deleteend();
int deletebeg();
void studentDetails();

// definition of a data node holding student info
struct node
{

	int studNum;
	char studlastName[100];
	char studfirstName[100];
	char studDegree[100];
	char studCollege[100];
	int studyearLevel;
	struct node *prev;
	struct node *next;

} *h, *temp, *temp1, *temp2, *temp4;

void create()
{

	int studNum;
	char studlastName[100];
	char studfirstName[100];
	char studDegree[100];
	char studCollege[100];
	int studyearLevel;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->next = NULL;
	printf("\n\n\t Please enter the following Details consecutively! \n");
	printf("\t Student\'s number, Lastname, Firstname, Degree, College, and year Level [1-5]: \n");
	scanf("\n\n\t\%d %s %s %s %s %s \n", &studNum, studlastName, studfirstName, studDegree, studCollege, studyearLevel);
	temp->studNum = studNum;
	strcpy(temp->studlastName, studlastName);
	strcpy(temp->studfirstName, studfirstName);
	strcpy(temp->studDegree, studDegree);
	strcpy(temp->studCollege, studCollege);
	temp->studyearLevel = studyearLevel;
	Count++;
}

// Function to insert at the beggining
void insertbeg()
{

	// If doubly list is empty
	if (h == NULL)
	{
		create();
		h = temp;
		temp1 = h;
	}
	// Else create a new node
	// and update the links
	else
	{

		create();
		temp->next = h;
		h->prev = temp;
		h = temp;
	}
}

// Function to insert at the end
void insertend()
{

	// If douby list is empty
	if (h == NULL)
	{
		create();
		h = temp;
		temp1 = h;
	}
	// Else create a new node and update links
	else
	{

		create();
		temp1->next = temp;
		temp->prev = temp1;
		temp1 = temp;
	}
}

// Function to display from the beggining
void displaybeg()
{

	temp2 = h;
	if (temp2 == NULL)
	{
		printf("\n\t List is empty \n");
		return;
	}
	printf("\n\t\t Linked list elements from the beginning: \n");
	while (temp2 != NULL)
	{

		printf("%d %s %s %s %s %d\n", temp2->studNum, temp2->studlastName, temp2->studfirstName, temp2->studDegree, temp2->studCollege, temp2->studyearLevel);
		temp2 = temp2->next;
	}
	// Print the counts
	printf("\t\tNumber of the Student: %d", Count);
}

// Function to delete at end
int deleteend()
{

	struct node *temp;
	temp = h;
	if (temp == NULL)
	{
		printf("\t\tThe list is empty\n");
		return 0;
	}
	if (temp->next == NULL)
	{
		printf("%d %s %s %s %s %d\n", temp->studNum, temp->studlastName, temp->studfirstName, temp->studDegree, temp->studCollege, temp->studyearLevel);
		free(temp);
		h = NULL;
	}
	else
	{

		temp = temp1;
		temp2 = temp1->prev;
		temp2->next = NULL;
		printf("%d %s %s %s %s %d\n", temp->studNum, temp->studlastName, temp->studfirstName, temp->studDegree, temp->studCollege, temp->studyearLevel);
		free(temp);
		temp1 = temp2;
	}
	Count--;
	return 0;
}

// Function to delete from beginning
int deletebeg()
{

	struct node *temp;
	temp = h;
	if (temp == NULL)
	{
		printf("\t\tThe list is empty\n");
		return 0;
	}
	if (temp->next == NULL)
	{
		printf("%d %s %s %s %s %d\n", temp->studNum, temp->studlastName, temp->studfirstName, temp->studDegree, temp->studCollege, temp->studyearLevel);
		free(temp);
		h = NULL;
	}
	else
	{
		h = h->next;
		h->prev = NULL;
		printf("%d %s %s %s %s %d\n", temp->studNum, temp->studlastName, temp->studfirstName, temp->studDegree, temp->studCollege, temp->studyearLevel);
		free(temp);
	}
	Count--;
	return 0;
}

// Function display menus
void studentDetails()
{

	int ch, n, i;
	h = NULL;
	temp = temp1 = NULL;
	printf("\n\n\t\t ***** Welcome to my Doubly Lists Student System!!! ***** \n");
	printf("\n\t 1. Create a DDL or Student\'s Entry \n");
	printf("\n\t 2. Display from the beginning \n");
	printf("\n\t 3. Insert at end \n");
	printf("\n\t 4. Delete at end \n");
	printf("\n\t 5. Insert at beginning \n");
	printf("\n\t 6. Delete at beginning \n");
	printf("\n\t 7. To show DLL as queue \n");
	printf("\n\t 8. To search for an List [Enter Latname] \n");
	printf("\n\t 9. Exit \n");
	printf("\n\n\t\t__________________________________________________________\n");
	while (1)
	{
		printf("\n\t Enter your Choice: ");
		scanf("%d", &ch);

		// Switch statements
		switch (ch)
		{
		case 1:
			printf("\n\t How many Students to record: ");
			scanf("%d", &n);
			for (i = 0; i < n; i++)
				insertend();
			break;

		case 2:
			displaybeg();
			break;

		case 3:
			insertend();
			break;

		case 4:
			deleteend();
			break;

		case 5:
			insertbeg();
			break;

		case 6:
			deletebeg();
			break;

		case 7:
			printf("\n To show DLL as que \n1. Perform inser and deletion operation by calling insertbeg() respectively\n\t OR \n2. Perform insert and delete operation by calling insertend() and deletebeg() respectively.\n");
			break;

		case 8:
			exit(0);

		case 9:
			exit(0);

		default:
			printf("\n\t\tIncorrect Choice!");
			printf("\n\t\tPlease try again!");
		}
	}
}
// Driver code
int main()
{
	// Call function
	studentDetails();
	return 0;
}
