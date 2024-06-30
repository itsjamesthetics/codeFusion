#include <stdio.h>
#include <stdlib.h>

/*
	Developed by: James Ald Teves

	Silliman University
	Programming Assignment in CCS 2 - B

	Description: A loop activity.
*/

// Main Method
int main()
{

	// Initialization
	int first, second, a, b;

	// User Input
	printf("Enter first number: ");
	scanf("%i", &first);
	// User Input
	printf("Enter second number: ");
	scanf("%i", &second);

	// Condition if first is less than second

	if (first < second)
	{

		// Condition for all in between numbers

		printf("\nAll numbers between inputted value in ascending order:\n");
		for (a = first; a <= second; a++)
		{
			printf("%i ", a);
		}

		// Condition for even numbers

		int sum = 0;
		printf("\n\nAll even numbers between inputted value in ascending order:\n");

		for (b = first; b <= second; b++)
		{
			int c = b % 2;
			if (c == 0)
			{
				printf("%i ", b);
				sum = sum + b;
			}
			else
			{
				printf("");
			}
		}

		// Display sum of even number in between

		printf("\n\nThe sum of all the even numbers in between inputted values:\n");
		printf("%i ", sum);
	}

	// Condition if second is less than  first

	else
	{

		// Condition all in between numbers

		printf("\nAll numbers between inputted value in ascending order:\n");
		for (a = second; a <= first; a++)
		{
			printf("%i ", a);
		}

		// Condition for all even numbers

		int sum = 0;
		printf("\n\nAll even numbers between inputted value in ascending order:\n");
		for (b = second; b <= first; b++)
		{
			int c = b % 2;
			if (c == 0)
			{
				printf("%i ", b);
				sum = sum + b;
			}
			else
			{
				printf("");
			}
		}

		// Display sum of even number in between

		printf("\n\nThe sum of all the even numbers in between inputted values:\n");
		printf("%i ", sum);
	}
}
