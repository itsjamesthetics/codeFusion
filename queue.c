/*
	Developed by: James Ald Teves
	BS Computer Science
	Instructor: Assist. Prof. Melody Angelique Rivera
	Computing Problem 7
	
	Description: Circular Queue program. In this program we are able to simulate the First-In-First-Out data structure. 
	Whatever element comes into the structure first will be the first one to be deleted.
*/

//	Preprocessor Directives
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define QSIZE 5

//	Function Declaration
int Menu (int Choice);
char CreateQueue (char Queue [], int *head, int *tail, int *checkQueue);
bool isDuplicate (char Queue [], char *element);
bool isFull (int *head, int *tail);
bool isEmpty (int *head, int *tail);
void Enque (char Queue [], char *element, int *tail);
void Deque (char Queue [], char *element, int *head, int *tail);
void AddElement (char Queue [], char element, int *head, int *tail);
void Display (char Queue [], int *head, int *tail);

//Main Function
int main () {
	
	//Declarations
	char Queue [QSIZE];
	int head = 0;
	int tail = -1;
	int checkQueue = 0;
	char element;
	int Choice;
	
	do {
		
		Choice = Menu (Choice);
		
		switch (Choice) {
			case 1:
				CreateQueue (Queue, &head, &tail, &checkQueue);
				break;
				
			case 2:
				if (checkQueue == 1) {
					AddElement (Queue, element, &head, &tail);
				}
				else {
					printf("\n\t Queue not Created! ");
					printf("\n\t ");
					system("pause");
					system("cls");
					printf("\n\n");
				}
				break;
				
			case 3:
				Deque (Queue, &element, &head, &tail);
				break;
				
			case 4:
				Display (Queue, &head, &tail);
				break;
				
			case 5:
				printf("\n\t Program Terminated! ");
				exit(0);
				system("pause");
				system("cls");
			
			default:
				printf("\n\t Invalid Choice! ");
				printf("\n\t Please Try again... ");
		}
	}while (Choice != 5);
	return 0;
}


char CreateQueue (char Queue [], int *head, int *tail, int *checkQueue) {
	
	int i;
	int front = *head;
	int rear = *tail;
	int checkQ = *checkQueue;
	char option;
	
	printf("\n\t Do you want to Create Queue (Y/N): ");
	scanf("  %c", &option);
	
	switch (tolower(option)) {
			
		case 'y':
			checkQ++;
			printf ("\n\t Create Queue successfully! ");
			printf("\n\t ");
			system("pause");
			system("cls");
			printf("\n\n");
			break;
		
		case 'n':
			printf("\n\t Create Queue unsuccessful. ");
			printf("\n\t ");
			system("pause");
			system("cls");
			printf("\n\n");
			break;	
		
	}
	
	for (i = 0; i < QSIZE; i++) {
		Queue [i] = ' ';
	}
	
	front = 0;
	rear = -1;
	
	*head = front;
	*tail = rear;
	*checkQueue = checkQ;
	
}

void Enque (char Queue [], char *element, int *tail) {
	
	int rear = *tail;
	char x = *element;
	rear++;
	Queue [rear] = x;
	
	*tail = rear;
	*element = x;
	
}

void Deque (char Queue [], char *element, int *head, int *tail) {
	
	char x = *element;
	int front = *head;
	int rear = *tail;
	
	if (isEmpty(head, tail)) {
		printf("\n\t The Queue is Empty! ");
		getch();
	}
	else {
		
		printf("\n\t Deleted Element: %c", Queue[front]);
		printf("\n");
		printf("\n\t ");
		system("pause");
		system("cls");
		printf("\n\n");
		
		x = Queue [front];
		front++;
		
		*head = front;
		*tail = rear;
		*element = x;
	}	
}

void AddElement (char Queue [], char element, int *head, int *tail) {
	
	int front = *head;
	int rear = *tail;
	char choice;
	
	
	if (isFull(head, tail)) {
		printf("\n\t The Queue is Full! ");
		printf("\n\t You want to Overwrite Data (Y/N): ");
		scanf(" %c", &choice);
		
		switch(tolower(choice)) {
			
			case 'y':
				main();
				getch();
				break;
			case 'n':
				printf("\n\t Data saved! ");
				printf("\n\t ");
				system("pause");
				system("cls");
				printf("\n\n");
				return;
				break;
		}
		
	}
	else {
		
		printf("\n\t Enter element: ");
		scanf("%c", &element);
		
		if(isDuplicate(Queue, &element)) {
			printf("\n\t Character already inputted! ");
			printf("\n\t Please input another charater... ");
			printf("\n\n");
			system("pause");
			system("cls");
		}
		else {
			Enque (Queue, &element, tail);
			printf("\n\t Element successfully Added! ");
			printf("\n\t ");
			system("pause");
			system("cls");
			printf("\n\n");	
		}	
	}	
}

bool isDuplicate (char Queue [], char *element) {
	
	int i;
	char dataElement = *element;
	
	for (i = 0; i < QSIZE; i++) {
		if (Queue [i] == dataElement){
			return true;
		}
		else {
			return false;
		}
		
		
		*element = dataElement;
		
	}
	
}

bool isFull (int *head, int *tail) {

	if (*tail == QSIZE - 1) {
		return true;
	}
	else if (*head == (*tail + 1) % QSIZE) {
		return false;
	}
	else {
		return false;
	}
	
}

bool isEmpty (int *head, int *tail) {
	
	if (*head == 0 && *tail == - 1) {
		return true;
	}
	else {
		return false;
	}
	
}

void Display (char Queue [], int *head, int *tail) {
	
	int i;
	int front = *head;
	int rear = *tail;

	if (!isEmpty(head, tail)) {
		
		if (front <= rear) {
			for (i = front; i <= rear; i++) {
				printf("\t | %c | ", Queue [i]);
			}		
			
		}
		
	}
	else {
		printf("\n\t The Queue is Empty! ");
		getch();
	}
	printf("\n");
	printf("\n\t ");
	system("pause");
	system("cls");
	printf("\n\n");
}

int Menu (int Choice) {
	
		system("cls");
		printf("\n\n\t\t Welcome to Circular Queue System \n");
		printf("\n\t 1. Create the queue ");
		printf("\n\t 2. Add an element to the queue ");
		printf("\n\t 3. Delete an element from the queue ");
		printf("\n\t 4. Display the elements in the queue ");
		printf("\n\t 5. Exit Program ");
		printf("\n\n\t Please Enter your choice: ");
		scanf(" %d", &Choice);
		fflush(stdin);
		system("cls");
		printf("\n");
	return Choice;
}