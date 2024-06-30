/*
	Developed by: James Ald Teves
	BS Computer Science
	Instructor: Assist. Prof. Melody Angelique Rivera
	Computing Problem 5
	
	Description: This Program enables you to Park, Pick up, and Disploay all Cars using Stack with an Array implementation.
*/

//	Preprocessor Directives
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define SLIMIT 5

//	Functions Declarations
int Menu (void);
int CreateStack (int Garage[], int top);
int Push (int Garage[], int license, int top);
int Pop (int Garage[], int tempGarage[], int *top, int tempTop, int license);
bool isFull(int t);
bool isEmpty(int t);
bool isDuplicate(int Garage[], int license);
int ParkCar (int Garage[], int top);
int RetrieveCar(int Garage[], int tempGarage[], int top, int tempTop);
int Display (int Garage[], int top);

int main () {
	
	int Garage[SLIMIT];
	int tempGarage[SLIMIT];
	int tempTop;
	int top;
	top = CreateStack (Garage, top);
	tempTop = CreateStack (tempGarage, tempTop);
	char choice;

	do
	{
			choice = Menu();
		switch (tolower(choice)){
			
		case 'a':
			top = ParkCar(Garage, top);
			break;
		case 'b':
			top = RetrieveCar(Garage, tempGarage, top, tempTop);
			break;
		case 'c':
			Display(Garage, top);
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

int CreateStack (int Garage[], int top) {
	
	int i;
	
	for (i=0; i<SLIMIT; i++) {
		Garage[i] = 0;
	}
	top = -1;
	return top;
	
}

int Push (int Garage[], int license, int top) {
		top += 1;
		Garage[top] = license;
		return top;
}

int Pop (int Garage[], int tempGarage[], int *top, int tempTop, int license) {
	
	int tempLicense = -1;
	int i;
	int j;
	
	//pop from garage
	//push to tempgarage
	//if found, return license
	//if not found, return -1
	for (i = *top; i >= 0; i--) {
		if (Garage[i] == license) {
			tempLicense = Garage[i];
			*top = i;
			break;
		}
		else {
			tempTop = Push(tempGarage, Garage[i], tempTop);
		}
	}
	
	//push tempgarage to garage
	int t = *top - 1;
	for (j = tempTop; j >= 0; j--) {
		t = Push(Garage, tempGarage[j], t);
	}
	
	*top = t;
	
	return tempLicense;
}

bool isFull (int t) {
	return t == SLIMIT - 1;
}

bool isEmpty(int t) {
	return t == -1;
}

bool isDuplicate(int Garage[], int license) {
	int i;
	for (i = 0; i < SLIMIT; i++ ) {
		if (Garage[i] == license) {
			return true;
		}
	}
	
	return false;
}

int ParkCar (int Garage[], int top) {
	int license;
	
	if(isFull(top)){
		printf("\n\t The Garage is FULL! ");
		getch();
	}
	else {
		printf("\n\t Enter Car License (100-999): ");
		scanf(" %d", &license);
		
		if (isDuplicate(Garage, license)) {
			printf("\n\t Car is already parked... ");
			printf("\n\t Please input another license");
			printf("\n\n");
			system("pause");
			system("cls");
			return top;
		}
		
		if ((license < 100 || license > 999)) {
			printf("\n\t Invalid! Try again... ");
			printf("\n Only (100-999) Car License to be Inputted.");
			printf("\n\n");
			system("pause");
			system("cls");
			return top;
		}
		
		top = Push(Garage, license, top);
		printf("\n\t Car Parked Succesfully!");
		printf("\n\n");
		system("pause");
		system("cls");
		printf("\n");
	}
	
	return top;
	
}

int RetrieveCar(int Garage[], int tempGarage[], int top, int tempTop) {
	int license;
	int retrievedLicense;
	
	if(isEmpty(top)){
		printf("\n\t The Garage is EMPTY! ");
		getch();
	}
	else {
		printf("\n\t Enter Car License (100-999): ");
		scanf(" %d", &license);
		
		if ((license < 100 || license > 999)) {
			printf("\n\t Invalid! Try again... ");
			printf("\n Only (100-999) Car License to be Inputted.");
			printf("\n\n");
			system("pause");
			system("cls");
			return top;
		}
		
		retrievedLicense = Pop(Garage, tempGarage, &top, tempTop, license);
		if  (license == - 1) {
			printf("\n\t Car license %d not found!", license);
		} else {
			printf("\n\t Car %d retrieved Succesfully!", retrievedLicense);
		}
		printf("\n\n");
		system("pause");
		system("cls");
		printf("\n");
	}
	
	return top;
}

int Display (int Garage[], int top) {
	
	int i;
	
	if (isEmpty(top)) {
		printf("\n\t Parking Garage is Empty! \n");
	}
	else {
	 	if (isFull(top)) {
			printf("\n\t Parking Garage is Full! \n");
		}
		
		printf("\n\t Existing Cars in the Parking Area: \n");
		for (i=top; i>-1; i--) {
			printf("%d\n\t", Garage[i]);
			printf("\n\t");
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