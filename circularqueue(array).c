/*
	Developed by: James Ald Teves
	BS Computer Science

	Instructor: Prof. Assist. Melody Angelique Rivera
	Computing Problem 7
	
	Description: Circular Queue using Array Implementation.
*/

// Preprocessor Directives
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <windows.h>
#define QSIZE 5


// Function Declarations
int menu();
void createQueue(char queue[], int *front, int *rear);
void enQueue(char queue[], int *front, int *rear);
void deQueue(char queue[], int *front, int *rear);
void displayQueue(char queue[], int front, int rear);
bool isFull(int front, int rear);
bool isEmpty(int front, int rear);

int main() {
    char queue[QSIZE];
    int front = 0, rear = -1;
    int choice;

    while ((choice = menu()) != 5) {
        switch (choice) {
            case 1:
                createQueue(queue, &front, &rear);
                break;
            case 2:
                enQueue(queue, &front, &rear);
                break;
            case 3:
                deQueue(queue, &front, &rear);
                break;
            case 4:
                displayQueue(queue, front, rear);
                break;
            default:
                printf("Invalid Choice! Please try again...\n");
        }
    }

    printf("Program Terminated!\n");
    return 0;
}

void createQueue(char queue[], int *front, int *rear) {
    *front = 0;
    *rear = -1;
    printf("Queue has been created.\n");
}

void enQueue(char queue[], int *front, int *rear) {
    char element;
    if (isFull(*front, *rear)) {
        printf("The Queue is Full!\n");
        return;
    }

    printf("Enter element to enqueue: ");
    scanf(" %c", &element);

    *rear = (*rear + 1) % QSIZE;
    queue[*rear] = element;

    printf("Queue successfully added.\n");
}

void deQueue(char queue[], int *front, int *rear) {
    if (isEmpty(*front, *rear)) {
        printf("The Queue is Empty!\n");
        return;
    }

    printf("Element Dequeued: %c\n", queue[*front]);
    *front = (*front + 1) % QSIZE;

    if (*front == (*rear + 1) % QSIZE) {
        *front = 0;
        *rear = -1;
    }
}

void displayQueue(char queue[], int front, int rear) {
    if (isEmpty(front, rear)) {
        printf("The Queue is Empty!\n");
        return;
    }

    printf("The following elements are in the queue: ");
    for (int i = front; i != rear; i = (i + 1) % QSIZE) {
        printf("%c ", queue[i]);
    }
    printf("%c\n", queue[rear]); // Display the last element
}

bool isFull(int front, int rear) {
    return (rear + 1) % QSIZE == front;
}

bool isEmpty(int front, int rear) {
    return rear == -1;
}

int menu() {
    int choice;
    printf("\nWelcome to Circular Queue Program\n");
    printf("1. Create the Queue\n");
    printf("2. Add an element to the Queue\n");
    printf("3. Delete an element from the Queue\n");
    printf("4. Display the Queue\n");
    printf("5. Exit Program\n");
    printf("Enter Choice: ");
    scanf("%d", &choice);
    return choice;
}