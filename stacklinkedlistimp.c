/*
	Developed by: James Ald Teves
	BS Computer Science
	Instructor: Assist. Prof. Melody Angelique Rivera
	Computing Problem 6
	
	Description: This Program enables you to Park, Pick up, and Disploay all Cars using Stack with an Linked List implementation. This time, we are using the stacks with Data Structure, we will use Nodes to store the elements of the Stack.
*/

//Preprocessor Directives
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define STACKSIZE 5

typedef struct stack Stk;
struct stack {
	
	int top;
	int data [STACKSIZE];
	
};

//Function Declarations
int Menu (void);
void Push (Stk *Stack, int item);
void Display (Stk Stack);
int Pop (Stk *Stack, int item);
int ParkCar (Stk *Stack);
int RetrieveCar (Stk *Stack, Stk *tempStack);
bool isDuplicate(Stk *Stack, int item);
bool isEmpty(Stk *Stack);

//Main Driver
int main () {

	Stk Stack;
	Stk tempStack;
	tempStack.top = -1;
	Stack.top = -1;

	char choice;
	
	do
	{
			choice = Menu();
		switch (tolower(choice)){
			
		case 'a':
			ParkCar (&Stack);
			break;
		case 'b':
			RetrieveCar (&Stack, &tempStack);
			break;
		case 'c':
			Display(Stack);
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

void Push (Stk *Stack, int item) {
	
	if (Stack->top == STACKSIZE - 1) {
		printf("\n\t The Garage is Full! ");
		getch();
	}
	else {
		Stack->top = Stack->top + 1;
		Stack->data[Stack->top] = item;
	}
	
}

int ParkCar (Stk *Stack) {
	
	int item;
	
	if(Stack->top == STACKSIZE - 1){
		printf("\n\t The Garage is Full! ");
		getch();
	}
	else {
		printf("\n\t Enter Car License (100-999): ");
		scanf(" %d", &item);
		
		if (isDuplicate(Stack, item)) {
			printf("\n\t Car is already parked... ");
			printf("\n\t Please input another license");
			printf("\n\n");
			system("pause");
			system("cls");
		}
		else if ((item < 100 || item > 999)) {
			printf("\n\t Invalid! Try again... ");
			printf("\n\t Only (100-999) Car License to be Inputted.");
			printf("\n\n");
			system("pause");
			system("cls");
		}
		else {
			Push (Stack, item);
			printf("\n\t Car Parked Succesfully!");
			printf("\n\n");
			system("pause");
			system("cls");
			printf("\n");
			return Stack->top;
		}
	}
}

int RetrieveCar (Stk *Stack, Stk *tempStack) {
	
	int item;
	int retrieveItem;
	
	if(Stack->top == - 1) {
		printf("\n\t The Garage is Empty! ");
		getch();
	}
	else {
		printf("\n\t Enter Car License: ");
		scanf("%d", &item);
		
		if ((item < 100 || item > 999)) {
			printf("\n\t Invalid! Try again... ");
			printf("\n Only (100-999) Car License to be Inputted.");
			printf("\n\n");
			system("pause");
			system("cls");
		}
		else {
			
			retrieveItem = Pop (Stack, item);
			if (item == -1) {
				printf("\n\t Car License not found! ");
			}
			else {
				printf("\n\t Car on Top retrieved Succesfully!", retrieveItem);
			}
			printf("\n\n");
			system("pause");
			system("cls");
			printf("\n");
		}
	}
	
	return Stack->top;
}

bool isDuplicate(Stk *Stack, int item) {
	
	int i;
	
	for (i=0; i < STACKSIZE; i++ ) {
		if (Stack->top == item) {
			return true;
		}
	else {
		return false;	
	}
	}
}

bool isEmpty(Stk *Stack) {
	
	return Stack->top == -1;
	
}

int Pop (Stk *Stack, int item) {

	if (Stack->top == - 1) {
		printf("\n\t The Garage is Empty! ");
		return -1;
	}
	else {
		return Stack->data[(Stack->top)--];
	}
}

void Display (Stk Stack) {
	
	int i;
	
	if (Stack.top == -1) {
		printf("\n\t The Garage is Empty! ");
	}
	else {
		printf("\n\t Existing Cars in the Parking Area: \n");
		printf("\n");
		for (i = Stack.top; i >= 0; i--) {
			printf("\t | %d \t| \n", Stack.data[i]);
			printf("\t+-------+\n\t Car No.\n");
		}
	}
	getch();
}

int Menu (void) {
	
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
