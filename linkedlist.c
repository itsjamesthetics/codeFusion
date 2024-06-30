/*
    Developed by: James Ald Teves
    BS Computer Science
    Instructor: Assist. Prof. Melody Angelique Rivera
    Computing Problem 6
    
    Description: This program allows you to Park, Pick up, and Display all Cars
    using a Stack implemented with a Linked List. In this implementation, we use
    Nodes to store the elements of the Stack.
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define STACKSIZE 5

// Stack structure definition
typedef struct {
    int top;
    int data[STACKSIZE];
} Stack;

// Function prototypes
void Push(Stack *s, int item);
int Pop(Stack *s);
int ParkCar(Stack *s);
int RetrieveCar (Stack *s, Stack *tempStack);
bool isDuplicate(Stack *s, int item);
bool isEmpty(Stack *s);
void Display(Stack s);
int Menu(void);

// Main function
int main() {
    Stack stack = { -1, {0} }; // Initialize stack
    Stack tempStack = { -1, {0} }; // Initialize temporary stack for retrieval
    char choice;

    do {
        choice = Menu();
        switch (tolower(choice)) {
            case 'a':
                ParkCar(&stack);
                break;
            case 'b':
                RetrieveCar(&stack, &tempStack);
                break;
            case 'c':
                Display(stack);
                break;
            case 'd':
                printf("\n\n\t\t Program Terminated! ");
                exit(0);
            default:
                printf("\n\n\t\tIncorrect Choice!");
                printf("\n\n");
                system("pause");
                system("cls");
        }
    } while (choice != 'd');

    return 0;
}

// Function to push a car into the stack
void Push(Stack *s, int item) {
    if (s->top == STACKSIZE - 1) {
        printf("\n\t The Garage is FULL! ");
        getch();
    } else {
        s->top++;
        s->data[s->top] = item;
    }
}

// Function to park a car
int ParkCar(Stack *s) {
    int item;

    if(s->top == STACKSIZE - 1){
        printf("\n\t The Garage is FULL! ");
        getch();
    } else {
        printf("\n\t Enter Car License (100-999): ");
        scanf(" %d", &item);
        
        if (isDuplicate(s, item)) {
            printf("\n\t Car is already parked... ");
            getch();
        } else if (item < 100 || item > 999) {
            printf("\n\t Invalid! Try again... ");
            getch();
        } else {
            Push(s, item);
            printf("\n\t Car Parked Successfully!");
            getch();
        }
    }
}

int RetrieveCar (Stack *s, Stack *tempStack) {
	
    int item, retrievedItem = -1;

    if (s->top == -1) {
        printf("\n\t The Garage is EMPTY! ");
        getch();
    } else {
        printf("\n\t Enter Car License to Retrieve (100-999): ");
        scanf("%d", &item);
        
        if (item < 100 || item > 999) {
            printf("\n\t Invalid! Try again... ");
            getch();
        } else {
            // Move cars to tempStack until we find the car or the garage is empty
            while (s->top != -1 && s->data[s->top] != item) {
                Push(tempStack, Pop(s));
            }

            // Check if the car is found
            if (s->top != -1 && s->data[s->top] == item) {
                retrievedItem = Pop(s);
                printf("\n\t Car %d retrieved successfully!", retrievedItem);
            } else {
                printf("\n\t Car License not found!");
            }
            getch();

            // Move cars back from tempStack to s
            while (tempStack->top != -1) {
                Push(s, Pop(tempStack));
            }
        }
    }

    return retrievedItem; // Return the retrieved car item, or -1 if not found
}

// Check if the car is already parked
bool isDuplicate(Stack *s, int item) {
    for (int i = 0; i <= s->top; i++) {
        if (s->data[i] == item) {
            return true;
        }
    }
    return false;
}

// Check if the stack is empty
bool isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to remove a car from the stack
int Pop(Stack *s) {
    if (s->top == -1) {
        printf("\n\t The Garage is EMPTY! ");
        getch();
        return -1;
    } else {
        int item = s->data[s->top];
        s->top--;
        return item;
    }
}

// Function to display all cars
void Display(Stack s) {
    if (s.top == -1) {
        printf("\n\t The Garage is EMPTY! ");
    } else {
        printf("\n\t Existing Cars in the Parking Area: \n");
        for (int i = s.top; i >= 0; i--) {
            printf("%d\n", s.data[i]);
        }
    }
    getch();
}

// Function to display the menu
int Menu(void) {
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
    return choice;
}