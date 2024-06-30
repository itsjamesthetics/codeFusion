/*
	Developed by: James Ald Teves
	BS Computer Science
	Instructor: Assist. Prof. Melody Angelique Rivera
	Computing Problem 6

	Description: This program enables you to park car, view cars, and display all cars
	using Stack with a linked-list implementation. This time, we are using the stacks
	with Data Structure, we will use nodes to store the elements of the Stack.
*/

// Preprocessor Directives
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define STACKSIZE 5

typedef struct stack STACK;
struct stack
{

	int top;
	int data[STACKSIZE];
};

// Function Declarations
int Menu(void);
void Push(STACK *s, int item);
int Pop(STACK *s);
void Display(STACK s);

int main(void)
{

	STACK s;
	s.top = -1;
	int item, del;
	char choice;

	do
	{
		choice = Menu();
		switch (tolower(choice))
		{

		case 'a':
			printf("\n\t Enter Car License: ");
			scanf("%d", &item);
			Push(&s, item);
			if ((item < 100 || item > 999))
			{
				printf("\n\t Invalid! Try again... ");
				printf("\n\t Only (100-999) Car License to be Inputted.");
				printf("\n\n");
				system("pause");
				system("cls");
			}
			break;
		case 'b':
			del = Pop(&s);
			if (del != -1)
			{
				printf("\n\t Car License Popped: %d\n", del);
			}
			getch();
			break;
		case 'c':
			Display(s);
			break;
		case 'd':
			printf("\n\n\t\t Program Terminated! ");
			exit(0);
		default:
			printf("\n\n\t\tIncorrect Choice!");
			printf("\n\n");
			system("pause");
			system("cls");
			printf("\n");
		}
	} while (choice != 'd');
	return 0;
}

void Push(STACK *s, int item)
{

	if (s->top == STACKSIZE - 1)
	{
		printf("\n\t The Garage is FULL! ");
	}
	else
	{
		s->top = s->top + 1;
		s->data[s->top] = item;
	}
}

int Pop(STACK *s)
{

	if (s->top == -1)
	{
		printf("\n\t The Garage is EMPTY! ");
		return -1;
	}
	else
	{
		return s->data[(s->top)--];
	}
}

void Display(STACK s)
{

	int i;

	if (s.top == -1)
	{
		printf("\n\t The Garage is EMPTY! ");
	}
	else
	{
		printf("\n\t Existing Cars in the Parking Area: \n");
		for (i = s.top; i >= 0; i--)
		{
			printf("%d\n", s.data[i]);
		}
	}
	getch();
}

int Menu(void)
{

	char choice;

	system("cls");
	printf("\n\n\t\t Welcome to Parking Management System \n");
	printf("\n\t A. Park a Car ");
	printf("\n\t B. Pick Up a Car ");
	printf("\n\t C. Display All Cars ");
	printf("\n\t D. Exit Program ");
	printf("\n\n\t Please Enter your choice: ");
	scanf(" %c", &choice);
	fflush(stdin);
	system("cls");
	printf("\n");

	return choice;
}