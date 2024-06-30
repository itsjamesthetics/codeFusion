#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*
	Developed by: James Ald Teves

	Silliman University
	Programming Assignment in CCS 2 - B

	Description: Distance Calculator
*/

int main()
{
    int distance;
    float meter, feet, inches, centimeter;

    printf("Enter the distance [in Kilometers]: ");
    scanf("%d", &distance);

    meter = distance * 1000;
    feet = distance * 3280.84;
    inches = distance * 39370.1;
    centimeter = distance * 100000;

    printf("Meter = %.2f\n", meter);
    printf("Feet = %.2f\n", feet);
    printf("Inches = %.2f\n", inches);
    printf("Centimeters = %.2f\n", centimeter);

    getch();
}
