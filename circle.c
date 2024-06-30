#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define pi 3.1416

/*
	Developed by: James Ald Teves

	Silliman University
	Programming Assignment in CCS 2 - B

	Description: Circle
*/

// Function Declaration
float diameter(float r);
float area(float r);
float circumference(float r);

int main()
{

	// Initialization and Userinput
	int choice;
	float radius, a, c, d;
	printf("Enter radius of circle:");
	scanf("%f", &radius);
	printf("Choose an option:");
	printf("\n1. Diameter\n2. Area\n3. Circumference");
	printf("\nEnter choice:");
	scanf("%d", &choice);

	// Switch Case
	switch (choice)
	{
	case 1:
		d = diameter(radius);
		printf("\nThe diameter is %.2f", d);
		break;
	case 2:
		a = area(radius);
		printf("\nThe area is %.2f", a);
		break;
	case 3:
		c = circumference(radius);
		printf("\nThe circumference is %.2f", c);
		break;
	default:
		printf("\nInvalid input");
	}
	getch();
}

float diameter(float r)
{
	float Diameter = 2 * r;
	return Diameter;
}

float area(float r)
{
	float Area = pi * r * r;
	return Area;
}

float circumference(float r)
{
	float Circumference = 2 * pi * r;
	return Circumference;
}
