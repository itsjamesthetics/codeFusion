#include <stdio.h>

/*
	Developed by: James Ald Teves

	Silliman University
	Programming Assignment in CCS 2 - B

	Description: Circumference Calculator
*/

int main()
{
	// Variable initialization and declaration
	float pi = 3.14149, r, dia, cir, area;

	// User Input
	printf("Enter the radius of a Circle: ");
	scanf("%f", &r);

	// Process
	dia = 2 * r;
	area = pi * r * r;
	cir = pi * r * 2;

	// Display the Ouput
	printf("The Circumference is equal to: %.2f \n", cir);
	printf("The diameter is equal to: %.2f \n", dia);
	printf("The Area of Circle is equal to: %.2f \n", area);
}
